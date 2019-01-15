////////////////////////////////////////////////////////////////////////////////
//                                                                            //
// NDK 2.0 - Network Development Kit                                          //
//                                                                            //
// Authors: Sebastien Lachance                                                //
//                                                                            //
// E-mail:  netblitz@rocler.qc.ca                                             //
//                                                                            //
// -------------------------------------------------------------------------- //
//                                                                            //
// Permission to use, copy, modify, and distribute this software for any      //
// purpose and without fee is hereby granted. This is no guarantee about the  //
// use of this software. For any comments, bugs or thanks, please email us.   //
//                                                                            //
// -------------------------------------------------------------------------- //
//                                                                            //
// Targeted Platform: Any Windows version                                     //
//                                                                            //
// Last modification: October 2005                                            //
//                                                                            //
// History:                                                                   //
//                                                                            //
// 1- First release of this file.                                             //
// 2- The class is renamed and some optimizations are applied. Hungarian      //
//    notation is used.                                                       //
// 3- Fix a bug that resolves socket notification. With Visual C++ .NET,      //
//    after a short time socket notifications were not send anymore.          //
// 4- Connections from a telnet client are now closed when data are send to   //
//    the server. Before, the server crashed.                                 //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Includes                                                                   //
////////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "NDKServerSocket.h"
#include "NDKMessage.h"
#include "NDKServer.h"


////////////////////////////////////////////////////////////////////////////////
// Constructors / Destructor                                                  //
////////////////////////////////////////////////////////////////////////////////

// Constructor.
CNDKServerSocket::CNDKServerSocket()
{
	m_pServer = NULL;
	m_pFile = NULL;
	m_pArchiveIn = NULL;
	m_pArchiveOut = NULL;
}


// Constructor with initialization.
CNDKServerSocket::CNDKServerSocket(CNDKServer* pServer)
{
	ASSERT(pServer != NULL);

	m_pServer = pServer;
	m_pFile = NULL;
	m_pArchiveIn = NULL;
	m_pArchiveOut = NULL;
}


// Destructor.
CNDKServerSocket::~CNDKServerSocket()
{
	CleanUp();
}


////////////////////////////////////////////////////////////////////////////////
// Attributes                                                                 //
////////////////////////////////////////////////////////////////////////////////

// Return if the buffer is empty.
BOOL CNDKServerSocket::IsBufferEmpty() const
{
	ASSERT(m_pArchiveIn != NULL);

	BOOL bResult = TRUE;

	if (m_pArchiveIn != NULL)
		bResult = m_pArchiveIn->IsBufferEmpty();
	
	return bResult;
}


////////////////////////////////////////////////////////////////////////////////
// Operations                                                                 //
////////////////////////////////////////////////////////////////////////////////

// Initializes the socket.
BOOL CNDKServerSocket::Initialize()
{
	BOOL bResult = FALSE;

	m_pFile = new CAOISocketFile(this);

	if (m_pFile != NULL)
	{
		TRY
		{
			m_pArchiveIn = new CArchive(m_pFile, CArchive::load);
			m_pArchiveOut = new CArchive(m_pFile, CArchive::store);
			bResult = TRUE;
		}
		CATCH(CArchiveException, e)
		{
		}
		CATCH(CFileException, e)
		{
		}
		END_CATCH
	}

	if (!bResult)
		CleanUp();

	return bResult;
}


// Closes the socket.
void CNDKServerSocket::Close()
{
	CleanUp();
}


// Sends a message.
void CNDKServerSocket::SendMessage(CNDKMessage &msg)
{
	ASSERT(m_pArchiveOut != NULL);

	if (m_pArchiveOut != NULL)
	{
		msg.Serialize(*m_pArchiveOut);
				
		m_pArchiveOut->Flush();
	}
}


// Receive a message.
void CNDKServerSocket::ReceiveMessage(CNDKMessage &msg)
{
	BYTE cBuffer[5] = {""};
	
	// Make sure that each message has more than 5 bytes. If the number of read bytes is
	// less than 5, it comes from a telnet connection, in this case, an exception is thrown.
	if (CSocket::Receive(cBuffer, 5, MSG_PEEK) >= 5)
		msg.Serialize(*m_pArchiveIn);
	else
		AfxThrowArchiveException(CArchiveException::badSchema);
}


////////////////////////////////////////////////////////////////////////////////
// Overrides from CSocket                                                     //
////////////////////////////////////////////////////////////////////////////////

// Called when a new connection attemps to connect.
void CNDKServerSocket::OnAccept(int nErrorCode) 
{
	CSocket::OnAccept(nErrorCode);

	ASSERT(m_pServer != NULL);

	if (m_pServer != NULL)
		m_pServer->ProcessPendingAccept(nErrorCode);
}


// Called when data is received.
void CNDKServerSocket::OnReceive(int nErrorCode) 
{
	// With Visual C++ 2003, this patch is needed because for an unknown reason socket notifications are not send
	//VERIFY(AsyncSelect(/*FD_READ |*/ FD_WRITE | FD_OOB | FD_ACCEPT | FD_CONNECT | FD_CLOSE));
	VERIFY(AsyncSelect(FD_READ | FD_WRITE | FD_OOB | FD_ACCEPT | FD_CONNECT | FD_CLOSE));	// modified by danny, important for speed up

	CSocket::OnReceive(nErrorCode);

	ASSERT(m_pServer != NULL);

	if (m_pServer != NULL)
	{
		if (m_pServer->ProcessPendingRead(this, nErrorCode))
		{	
			CString strSocketAddress;
			UINT    unPort = 0;

			// Restore to the default notification
			if (GetSockName(strSocketAddress, unPort) != 0)
				VERIFY(AsyncSelect());
		}
	}
}


////////////////////////////////////////////////////////////////////////////////
// Private Operations.                                                        //
////////////////////////////////////////////////////////////////////////////////

// Cleans up
void CNDKServerSocket::CleanUp()
{
	if (m_pArchiveOut != NULL)
	{
		m_pArchiveOut->Abort();

		delete m_pArchiveOut;
		m_pArchiveOut = NULL;
	}
	
	if (m_pArchiveIn != NULL)
	{
		delete m_pArchiveIn;
		m_pArchiveIn = NULL;
	}
	
	if (m_pFile != NULL)
	{
		delete m_pFile;
		m_pFile = NULL;
	}
}
