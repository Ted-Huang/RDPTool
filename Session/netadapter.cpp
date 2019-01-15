﻿#include "stdafx.h"
#include "netadapter.h"
#include "winerr.h"

#define ALLOCATE_FROM_PROCESS_HEAP( bytes )		::HeapAlloc( ::GetProcessHeap(), HEAP_ZERO_MEMORY, bytes )
#define DEALLOCATE_FROM_PROCESS_HEAP( ptr )		if( ptr ) ::HeapFree( ::GetProcessHeap(), 0, ptr )
#define REALLOC_FROM_PROCESS_HEAP( ptr, bytes )	::HeapReAlloc( ::GetProcessHeap(), HEAP_ZERO_MEMORY, ptr, bytes )

////////////////////////////////////////////////////////////
//	Description:
//		Builds a listing of all network adapters found
//		on the current system.  If there is not enough
//		space in the passed in buffer ERROR_INSUFFICIENT_BUFFER
//		is returned. If error lpdwOutSzBuf contains the
//		needed buffer size.  If no error it returned
//		used buffer size.
////////////////////////////////////////////////////////////
DWORD EnumNetworkAdapters(CNetworkAdapter* pAdapters, ULONG ulSzBuf, LPDWORD lpdwOutSzBuf) 
{	
	IP_ADAPTER_INFO* pAdptInfo	= NULL;
	IP_ADAPTER_INFO* pNextAd	= NULL;	
	ULONG ulLen					= 0;
	int nCnt					= 0;
	CWinErr erradapt;
	
	erradapt = ::GetAdaptersInfo(pAdptInfo, &ulLen);
	if (erradapt == ERROR_BUFFER_OVERFLOW) 
	{
		pAdptInfo = (IP_ADAPTER_INFO*)ALLOCATE_FROM_PROCESS_HEAP(ulLen);
		erradapt = ::GetAdaptersInfo(pAdptInfo, &ulLen);		
	}

	// acquire a count of how many network adapters
	// we are going to need to work on so that
	// we can make sure we have adequate buffer space.
	pNextAd = pAdptInfo;
	while (pNextAd) 
	{
		nCnt++;
		pNextAd = pNextAd->Next;
	}

	// now that we have the count we need to determine if the caller passed in an
	// adequate buffer for us to store all the needed adapters.  we set the variable
	// to the needed number of bytes so the caller will now how many there are 
	// and how much space is needed to hold them.
	*lpdwOutSzBuf = nCnt * sizeof(CNetworkAdapter);
	if (ulSzBuf < *lpdwOutSzBuf) 
	{		
		DEALLOCATE_FROM_PROCESS_HEAP(pAdptInfo);
		return ERROR_INSUFFICIENT_BUFFER;
	}

	// this needs to be reset for future use.
	nCnt = 0;

	if (erradapt == ERROR_SUCCESS) 
	{
		// initialize the pointer we use the move through
		// the list.
		pNextAd = pAdptInfo;

		// loop through for all available interfaces and setup an associated
		// CNetworkAdapter class.
		while (pNextAd) 
		{
			pAdapters[nCnt].SetupAdapterInfo(pNextAd);	
			// move forward to the next adapter in the list so
			// that we can collect its information.
			pNextAd = pNextAd->Next;
			nCnt++;
		}
	}

	// free any memory we allocated from the heap before
	// exit.  we wouldn't wanna leave memory leaks now would we? ;p
	DEALLOCATE_FROM_PROCESS_HEAP(pAdptInfo);		

	return ERROR_SUCCESS;
}

////////////////////////////////////////////////////////////
//	Description:
//		Construction.  Initializes the variables and makes
//		sure all the collection classes are cleaned out.
////////////////////////////////////////////////////////////
CNetworkAdapter::CNetworkAdapter() 
{
	m_bDhcpUsed		= FALSE;
	m_bWinsUsed		= FALSE;
	m_dwIndex		= 0;
	m_nAdapterType	= 0;

	::memset(&m_ucAddress.ucAddress, 0, MAX_ADAPTER_ADDRESS_LENGTH);
	m_ucAddress.nLen = 0;
	
	m_DnsAddresses.clear();
	m_IpAddresses.clear();
	m_GatewayList.clear();

	return;
}

////////////////////////////////////////////////////////////
//	Description:
//		Deconstruction.
////////////////////////////////////////////////////////////
CNetworkAdapter::~CNetworkAdapter() 
{
#ifdef _DEBUG
	::memset(&m_ucAddress.ucAddress, 0, MAX_ADAPTER_ADDRESS_LENGTH);
	m_ucAddress.nLen = 0;
	m_bDhcpUsed		= FALSE;
	m_bWinsUsed		= FALSE;
	m_dwIndex		= 0;
	m_nAdapterType	= 0;
#endif
	
	m_DnsAddresses.clear();
	m_IpAddresses.clear();
	m_GatewayList.clear();

	return;
}

BOOL CNetworkAdapter::SetupAdapterInfo(IP_ADAPTER_INFO* pAdaptInfo) 
{
	BOOL bSetupPassed				= FALSE;
	IP_ADDR_STRING* pNext			= NULL;
	IP_PER_ADAPTER_INFO* pPerAdapt	= NULL;
	ULONG ulLen						= 0;
	CWinErr err;

	_IPINFO iphold;
	
	if (pAdaptInfo) 
	{		
#ifndef _UNICODE 
		m_sName			= pAdaptInfo->AdapterName;		
		m_sDesc			= pAdaptInfo->Description;
		m_sPriWins		= pAdaptInfo->PrimaryWinsServer.IpAddress.String;
		m_sSecWins		= pAdaptInfo->SecondaryWinsServer.IpAddress.String;
		m_sDhcpAddr		= pAdaptInfo->DhcpServer.IpAddress.String;
#else
		USES_CONVERSION;
		m_sName			= A2W(pAdaptInfo->AdapterName);
		m_sDesc			= A2W(pAdaptInfo->Description);
		m_sPriWins		= A2W(pAdaptInfo->PrimaryWinsServer.IpAddress.String);
		m_sSecWins		= A2W(pAdaptInfo->SecondaryWinsServer.IpAddress.String);
		m_sDhcpAddr		= A2W(pAdaptInfo->DhcpServer.IpAddress.String);
#endif
		m_dwIndex		= pAdaptInfo->Index;		
		m_nAdapterType	= pAdaptInfo->Type;	
		m_bDhcpUsed		= pAdaptInfo->DhcpEnabled;
		m_bWinsUsed		= pAdaptInfo->HaveWins;	
		m_tLeaseObtained= pAdaptInfo->LeaseObtained;
		m_tLeaseExpires	= pAdaptInfo->LeaseExpires;

		//set adapter address length, and then copy each byte from
		//pAdaptInfo->Address (the MAC address) to the adapter address structure.  
		m_ucAddress.nLen = pAdaptInfo->AddressLength;
		for (int i=0; i<(int)m_ucAddress.nLen; i++)
		{
			m_ucAddress.ucAddress[i] = pAdaptInfo->Address[i];
		}
		
		if (pAdaptInfo->CurrentIpAddress) 
		{
#ifndef _UNICODE 
			m_sCurIpAddr.sIp		= pAdaptInfo->CurrentIpAddress->IpAddress.String;
			m_sCurIpAddr.sSubnet	= pAdaptInfo->CurrentIpAddress->IpMask.String;
#else
			m_sCurIpAddr.sIp		= A2W(pAdaptInfo->CurrentIpAddress->IpAddress.String);
			m_sCurIpAddr.sSubnet	= A2W(pAdaptInfo->CurrentIpAddress->IpMask.String);
#endif
		}
		else
		{
			m_sCurIpAddr.sIp		= _T("0.0.0.0");
			m_sCurIpAddr.sSubnet	= _T("0.0.0.0");
		}

		// since an adapter may have more than one ip address we need
		// to populate the array we have setup with all available
		// ip addresses.
		pNext = &(pAdaptInfo->IpAddressList);
		while (pNext) 
		{
#ifndef _UNICODE 
			iphold.sIp		= pNext->IpAddress.String;
			iphold.sSubnet	= pNext->IpMask.String;
#else
			iphold.sIp		= A2W(pNext->IpAddress.String);
			iphold.sSubnet	= A2W(pNext->IpMask.String);
#endif
			m_IpAddresses.push_back(iphold);
			pNext = pNext->Next;
		}

		// an adapter usually has just one gateway however the provision exists
		// for more than one so to "play" as nice as possible we allow for it here
		// as well.
		pNext = &(pAdaptInfo->GatewayList);
		while (pNext) 
		{
#ifndef _UNICODE 
			m_GatewayList.push_back(pNext->IpAddress.String);
#else
			m_GatewayList.push_back(A2W(pNext->IpAddress.String));
#endif
			pNext = pNext->Next;
		}	
			
		// we need to generate a IP_PER_ADAPTER_INFO structure in order
		// to get the list of DNS addresses used by this adapter.
		err = ::GetPerAdapterInfo(m_dwIndex, pPerAdapt, &ulLen);
		if (err == ERROR_BUFFER_OVERFLOW) 
		{
			pPerAdapt = (IP_PER_ADAPTER_INFO*)ALLOCATE_FROM_PROCESS_HEAP(ulLen);
			err = ::GetPerAdapterInfo(m_dwIndex, pPerAdapt, &ulLen);
			
			// if we succeed than we need to drop into our loop
			// and fill the DNS array will all available IP addresses.
			if (err == ERROR_SUCCESS) 
			{
				pNext = &(pPerAdapt->DnsServerList);
				while (pNext) 
				{
#ifndef _UNICODE 
					m_DnsAddresses.push_back(pNext->IpAddress.String);
#else
					m_DnsAddresses.push_back(A2W(pNext->IpAddress.String));
#endif
					pNext = pNext->Next;
				}				
				bSetupPassed = TRUE;
			}

			// this is done outside the err == ERROR_SUCCES just in case. the macro
			// uses NULL pointer checking so it is ok if pPerAdapt was never allocated.
			DEALLOCATE_FROM_PROCESS_HEAP(pPerAdapt);
		}		
	}
	
	return bSetupPassed;
}

////////////////////////////////////////////////////////////
//	Description:
//		Releases the addresses held by this adapter.
////////////////////////////////////////////////////////////
BOOL CNetworkAdapter::ReleaseAddress() 
{	
	return DoRenewRelease(&::IpReleaseAddress);
}

////////////////////////////////////////////////////////////
//	Description:
//		Renews the address being held by this adapter.
////////////////////////////////////////////////////////////
BOOL CNetworkAdapter::RenewAddress() 
{
	return DoRenewRelease(&::IpRenewAddress);
}

////////////////////////////////////////////////////////////
//	Description:
//		Generic function that can handle either renewing
//		or releasing an adapters ip address.
////////////////////////////////////////////////////////////
BOOL CNetworkAdapter::DoRenewRelease(DWORD( __stdcall *func)(PIP_ADAPTER_INDEX_MAP AdapterInfo)) 
{	
	IP_INTERFACE_INFO*	pInfo	= NULL;
	BOOL bDidIt					= FALSE;
	ULONG ulLen					= 0;
	int nNumInterfaces			= 0;
	int nCnt					= 0;
	CWinErr err;

	err = ::GetInterfaceInfo(pInfo, &ulLen);
	if (err == ERROR_INSUFFICIENT_BUFFER) 
	{
		pInfo = (IP_INTERFACE_INFO*)ALLOCATE_FROM_PROCESS_HEAP(ulLen);
		err = ::GetInterfaceInfo(pInfo, &ulLen);

		if (err != NO_ERROR) 
			return FALSE;			
	}

	// we can assume from here out that we have a valid array
	// of IP_INTERFACE_INFO structures due to the error 
	// checking one above.
	nNumInterfaces = ulLen / sizeof(IP_INTERFACE_INFO);
	for (nCnt=0; nCnt<nNumInterfaces; nCnt++) 
	{
		if (pInfo[nCnt].Adapter[0].Index == m_dwIndex) 
		{
			err = func(&pInfo[nCnt].Adapter[0]);
			
			// free all used memory since we don't need it any more.
			DEALLOCATE_FROM_PROCESS_HEAP(pInfo);	
			
			bDidIt = (err == NO_ERROR);			
			if (!bDidIt)
				return FALSE;

			break;
		}
	}			

	return bDidIt;
}

////////////////////////////////////////////////////////////
//	Description:
//		Generic function to grab a string from an array.
//		purpose of this function is just to add error 
//		checking.
////////////////////////////////////////////////////////////
tstring	CNetworkAdapter::GetStringFromArray(const StringArray* pPtr, int nIndex) const 
{
	tstring sStr = _T("");
	if (pPtr && ((SIZE_T)nIndex < pPtr->size())) 
	{
		sStr = (*pPtr)[nIndex];
	}

	return sStr;
}

////////////////////////////////////////////////////////////
//	Description:
//		Returns a string translation of the integer type
//		identifier for an adapter.
////////////////////////////////////////////////////////////
tstring CNetworkAdapter::GetAdapterTypeString(UINT nType) 
{
	tstring sType = _T("");
	switch (nType) 
	{
		case MIB_IF_TYPE_OTHER:		sType = _T("Other");		break;
		case MIB_IF_TYPE_ETHERNET:	sType = _T("Ethernet");		break; 
		case MIB_IF_TYPE_TOKENRING:	sType = _T("Token Ring");	break; 
		case MIB_IF_TYPE_FDDI:		sType = _T("FDDI");			break; 
		case MIB_IF_TYPE_PPP:		sType = _T("PPP");			break; 
		case MIB_IF_TYPE_LOOPBACK:	sType = _T("Loopback");		break; 
		case MIB_IF_TYPE_SLIP:		sType = _T("SLIP");			break; 	
		default: sType = _T("Invalid Adapter Type");			break;
	};

	return sType;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//											Data Accessor Functions														//
//											Pretty Self Explanatory														//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

tstring CNetworkAdapter::GetAdapterName()				const {return m_sName;}
tstring CNetworkAdapter::GetAdapterDescription()		const {return m_sDesc;}
time_t CNetworkAdapter::GetLeaseObtained()				const {return m_tLeaseObtained;}
time_t CNetworkAdapter::GetLeaseExpired()				const {return m_tLeaseExpires;}
SIZE_T	CNetworkAdapter::GetNumIpAddrs()				const {return m_IpAddresses.size();}
SIZE_T	CNetworkAdapter::GetNumDnsAddrs()				const {return m_DnsAddresses.size();}
tstring	CNetworkAdapter::GetDnsAddr(int nDns)			const {return GetStringFromArray(&m_DnsAddresses, nDns);}
tstring CNetworkAdapter::GetCurrentIpAddress()			const {return m_sCurIpAddr.sIp;}
BOOL CNetworkAdapter::IsDhcpUsed()						const {return m_bDhcpUsed;}
tstring	CNetworkAdapter::GetDchpAddr()					const {return m_sDhcpAddr;}
BOOL CNetworkAdapter::IsWinsUsed()						const {return m_bWinsUsed;}
tstring CNetworkAdapter::GetPrimaryWinsServer()			const {return m_sPriWins;}
tstring CNetworkAdapter::GetSecondaryWinsServer()		const {return m_sSecWins;}
tstring	CNetworkAdapter::GetGatewayAddr(int nGateway)	const {return GetStringFromArray(&m_GatewayList, nGateway);}
SIZE_T	CNetworkAdapter::GetNumGatewayAddrs()			const {return m_GatewayList.size();}
DWORD CNetworkAdapter::GetAdapterIndex()				const {return m_dwIndex;}
UINT CNetworkAdapter::GetAdapterType()					const {return m_nAdapterType;}

tstring	CNetworkAdapter::GetIpAddr(int nIp) const 
{	
	tstring sAddr = _T("");
	if ((SIZE_T)nIp < m_IpAddresses.size()) 
	{
        sAddr = m_IpAddresses[nIp].sIp;
	}
	return sAddr;
}

tstring CNetworkAdapter::GetSubnetForIpAddr(int nIp) const 
{ 
	tstring sAddr = _T("");
	if ((SIZE_T)nIp < m_IpAddresses.size()) 
	{
        sAddr = m_IpAddresses[nIp].sSubnet;
	}
	return sAddr;
}

// returns formatted MAC address in HEX punctuated with hyphens "-"
tstring CNetworkAdapter::GetAdapterAddress(void)
{
	tstring sAddr = _T("");
	CString sTemp = _T("");
	for (unsigned int i=0; i<m_ucAddress.nLen; i++)
	{
		if (i > 0)
			sAddr += _T("-");

		sTemp.Format(_T("%02X"), m_ucAddress.ucAddress[i]);
		sAddr += sTemp;
	}

	return sAddr;
}

// copies the adapter's address raw bytes into the CByteArray pointed to by pAdapterAddress
void CNetworkAdapter::GetAdapterAddress(CByteArray& pAdapterAddress)
{
	for (unsigned int i=0; i<m_ucAddress.nLen; i++)
	{
		pAdapterAddress.Add(m_ucAddress.ucAddress[i]);
	}
}