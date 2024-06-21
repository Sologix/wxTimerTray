#ifndef __TIMERTRAYMAINFRAME__
#define __TIMERTRAYMAINFRAME__
#include <wx/wx.h>
#include <wx/timer.h>
#include <wx/notifmsg.h>
#include "TimerTrayUI.h"

class MyTaskBarIcon;

class TimerTrayMainFrame : public MainFrame
{
	public:
		TimerTrayMainFrame(wxWindow* parent);
		~TimerTrayMainFrame();
		void SaveLastTimerSetting() const;
		virtual void OnClose( wxCloseEvent& event );
		void CreateTaskBarIcon();

#if defined(__WXOSX__) && wxOSX_USE_COCOA
		MyTaskBarIcon* m_dockIcon;
#endif

	protected:
		wxTimer* m_timer = nullptr;
		MyTaskBarIcon* m_taskBarIcon = nullptr;
		long m_hours = 0;
		long m_minutes = 0;
		long m_seconds = 0;
		bool m_iconizeOnTimerTick = true;

		void LoadLastTimerSetting() const;
		void FillComboBoxValues() const;
		void StartTimer();
		void StopTimer();
		void ToggleTimer();
		bool Countdown();
		void TimerElapsed() const;
		void ReloadTimer();
		void UpdateLabel() const;
		void UpdateNotificationToolTip() const;
		void OnTimer( wxTimerEvent& event );
		void OnStartResetBtnClicked(wxCommandEvent& event) override;
		void OnHoursSelected(wxCommandEvent& event) override;
		void OnMinutesSelected(wxCommandEvent& event) override;
		void OnSecondsSelected(wxCommandEvent& event) override;
};

#endif // __TIMERTRAYMAINFRAME__
