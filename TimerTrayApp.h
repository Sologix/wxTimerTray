#ifndef _MAIN_H_
#define _MAIN_H_

#include <wx/wx.h>
#include <wx/snglinst.h>
#include "TimerTrayMainFrame.h"
#include "Images/Watch.xpm"

wxIcon g_Icon = wxIcon(Watch);

class TimerTrayApp : public wxApp
{
  public:
	TimerTrayApp();
    bool OnInit(void) wxOVERRIDE;
	int OnExit(void)  wxOVERRIDE;
	
  protected:
	TimerTrayMainFrame* m_pMainFrame;
	wxSingleInstanceChecker* m_pChecker;
};

DECLARE_APP(TimerTrayApp)

#endif
