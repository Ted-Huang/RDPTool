#pragma once

#include "RdpEncomAPI.h"



void OnAttendeeConnected(IDispatch *pAttendee);
void OnAttendeeDisconnected(IDispatch *pAttendee);
void OnControlLevelChangeRequest(IDispatch  *pAttendee, CTRL_LEVEL RequestedLevel);


//class CRDPSession;
class EventSink : public _IRDPSessionEvents {
public:
	EventSink(){
	}

	~EventSink(){
	}

	// IUnknown
	virtual HRESULT STDMETHODCALLTYPE  QueryInterface(
		REFIID iid, void**ppvObject){
		*ppvObject = 0;
		if (iid == IID_IUnknown || iid == IID_IDispatch || iid == __uuidof(_IRDPSessionEvents))
			*ppvObject = this;
		if (*ppvObject)
		{
			((IUnknown*)(*ppvObject))->AddRef();
			return S_OK;
		}
		return E_NOINTERFACE;
	}

	virtual ULONG STDMETHODCALLTYPE  AddRef(void){
		return 0;
	}

	virtual ULONG STDMETHODCALLTYPE  Release(void){
		return 0;
	}


	// IDispatch
	virtual HRESULT STDMETHODCALLTYPE  GetTypeInfoCount(
		__RPC__out UINT *pctinfo){
		return E_NOTIMPL;
	}

	virtual HRESULT STDMETHODCALLTYPE  GetTypeInfo(
		UINT iTInfo,
		LCID lcid,
		__RPC__deref_out_opt ITypeInfo **ppTInfo){
		return E_NOTIMPL;
	}

	virtual HRESULT STDMETHODCALLTYPE  GetIDsOfNames(
		__RPC__in REFIID riid,
		__RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
		UINT cNames,
		LCID lcid,
		__RPC__out_ecount_full(cNames) DISPID *rgDispId){
		return E_NOTIMPL;
	}

	virtual HRESULT STDMETHODCALLTYPE  EventSink::Invoke(
		DISPID dispIdMember,
		REFIID riid,
		LCID lcid,
		WORD wFlags,
		DISPPARAMS FAR* pDispParams,
		VARIANT FAR* pVarResult,
		EXCEPINFO FAR* pExcepInfo,
		unsigned int FAR* puArgErr){


		switch (dispIdMember){
		case DISPID_RDPSRAPI_EVENT_ON_ATTENDEE_CONNECTED:
			OnAttendeeConnected(pDispParams->rgvarg[0].pdispVal);
			break;
		case DISPID_RDPSRAPI_EVENT_ON_ATTENDEE_DISCONNECTED:
			OnAttendeeDisconnected(pDispParams->rgvarg[0].pdispVal);
			break;
		case DISPID_RDPSRAPI_EVENT_ON_CTRLLEVEL_CHANGE_REQUEST:
			OnControlLevelChangeRequest(pDispParams->rgvarg[1].pdispVal, (CTRL_LEVEL)pDispParams->rgvarg[0].intVal);
			break;
		}
		return S_OK;
	}
};

class CRDPSession{
public:
	CRDPSession();
	~CRDPSession();

	CString GetConnectionString();
private:
	void Init();
	int ConnectEvent(IUnknown* Container, REFIID riid, IUnknown* Advisor, IConnectionPointContainer** picpc, IConnectionPoint** picp);

private:
	IConnectionPointContainer* m_picpc;
	IConnectionPoint* m_picp;
	EventSink m_ev;
	IRDPSRAPISharingSession * m_pSession;
	IRDPSRAPIInvitation * m_pInvatition;
};
