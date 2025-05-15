#ifndef __MYTASKBARICON__
#define __MYTASKBARICON__
#ifdef __WXMSW__
#include <wx/msw/msvcrt.h>      // redefines the new() operator 
#endif
#include <wx/wx.h>
#include <wx/event.h>
#include <wx/taskbar.h>
#include "TimerTrayMainFrame.h"

class MyTaskBarIcon : public wxTaskBarIcon
{
	wxDECLARE_EVENT_TABLE();

public:
#if defined(__WXOSX__) && wxOSX_USE_COCOA
	MyTaskBarIcon(TimerTrayMainFrame* pMainFrame, wxTaskBarIconType iconType = wxTBI_DEFAULT_TYPE ) : wxTaskBarIcon( iconType ), m_pMainFrame(pMainFrame) { OnLoad(); }
#else
	MyTaskBarIcon(TimerTrayMainFrame* pMainFrame);
#endif

	void OnLeftButtonDClick( wxTaskBarIconEvent& );
	void OnMenuOpen( wxCommandEvent& ); 
	void OnMenuAbout( wxCommandEvent& );
	void OnMenuExit( wxCommandEvent& );
	wxMenu* CreatePopupMenu() wxOVERRIDE;

protected:
	TimerTrayMainFrame* m_pMainFrame = nullptr;
	void ShowMainFrame() const;
};
#endif // __MYTASKBARICON__
