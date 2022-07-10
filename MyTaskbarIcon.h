#ifndef __MYTASKBARICON__
#define __MYTASKBARICON__
#include <wx/wx.h>
#include <wx/event.h>
#include <wx/taskbar.h>

#include "TimerTrayAboutDlg.h"
#include "TimerTrayMainFrame.h"

class MyTaskBarIcon : public wxTaskBarIcon
{
     wxDECLARE_EVENT_TABLE();

public:
#if defined(__WXOSX__) && wxOSX_USE_COCOA
    MyTaskBarIcon( wxTaskBarIconType iconType = wxTBI_DEFAULT_TYPE ) : wxTaskBarIcon( iconType ), m_pMainFrame( nullptr ), m_pAboutDlg( nullptr ) { OnLoad(); }
#else
    MyTaskBarIcon() : m_pMainFrame(nullptr), m_pAboutDlg(nullptr) { OnLoad(); }
#endif

    TimerTrayMainFrame* m_pMainFrame;
    TimerTrayAboutDlg* m_pAboutDlg;

    void OnLoad();
     void ShowMainFrame();

     void OnLeftButtonDClick( wxTaskBarIconEvent& );
    void OnMenuOpen( wxCommandEvent& );
    void OnMenuAbout( wxCommandEvent& );
    void OnMenuExit( wxCommandEvent& );
    wxMenu* CreatePopupMenu() wxOVERRIDE;
};
#endif // __MYTASKBARICON__
