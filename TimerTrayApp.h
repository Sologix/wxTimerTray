#ifndef _MAIN_H_
#define _MAIN_H_

#include <wx/wx.h>
#include <wx/snglinst.h>
#include "TimerTrayMainFrame.h"

wxIcon* g_Icon = new wxIcon();

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
