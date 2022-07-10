///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/combobox.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/statbmp.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MainFrame
///////////////////////////////////////////////////////////////////////////////
class MainFrame : public wxFrame
{
	private:

	protected:
		wxStaticText* m_countDownLbl;
		wxComboBox* m_hoursCb;
		wxStaticText* m_staticText2;
		wxComboBox* m_minutesCb;
		wxStaticText* m_staticText3;
		wxComboBox* m_secondsCb;
		wxStaticText* m_staticText4;
		wxButton* m_startResetBtn;

		// Virtual event handlers, overide them in your derived class
		virtual void OnActivate( wxActivateEvent& event ) { event.Skip(); }
		virtual void OnHoursSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMinutesSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSecondsSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnStartResetBtnClicked( wxCommandEvent& event ) { event.Skip(); }


	public:

		MainFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("TimerTray"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 305,267 ), long style = wxCAPTION|wxCLOSE_BOX|wxFRAME_NO_TASKBAR|wxTAB_TRAVERSAL );

		~MainFrame();

};

///////////////////////////////////////////////////////////////////////////////
/// Class AboutDlg
///////////////////////////////////////////////////////////////////////////////
class AboutDlg : public wxDialog
{
	private:

	protected:
		wxStaticBitmap* m_stopwatchBmp;
		wxStaticText* m_staticText5;
		wxStaticText* m_staticText6;
		wxStaticText* m_staticText7;
		wxStaticText* m_versionLbl;
		wxButton* m_button2;

	public:

		AboutDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("About"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );
		~AboutDlg();

};

