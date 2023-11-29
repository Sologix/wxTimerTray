#ifndef __TimerTrayAboutDlg__
#define __TimerTrayAboutDlg__

#include <wx/wx.h>
#include "TimerTrayUI.h"

class TimerTrayAboutDlg : public AboutDlg
{
	public:
		TimerTrayAboutDlg( wxWindow* parent );

		void SetAboutBitmap( const wxBitmap& bitmap );
};

#endif // __TimerTrayAboutDlg__
