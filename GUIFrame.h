///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __GUIFRAME_H__
#define __GUIFRAME_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/statusbr.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/grid.h>
#include <wx/button.h>
#include <wx/statbox.h>
#include <wx/frame.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////

#define idMenuCalc 1000
#define idMenuQuit 1001
#define idMenuAbout 1002
#define ID_RATA 1003
#define ID_MAX_KOL 1004
#define ID_TROSKOVI_SKL 1005
#define ID_MAX_ZAL 1006
#define ID_BROJ_RAZDOBLJA 1007
#define ID_TROSKOVI_NAB 1008

///////////////////////////////////////////////////////////////////////////////
/// Class GUIFrame
///////////////////////////////////////////////////////////////////////////////
class GUIFrame : public wxFrame 
{
	private:
	
	protected:
		wxMenuBar* mbar;
		wxMenu* fileMenu;
		wxMenu* helpMenu;
		wxStatusBar* statusBar;
		wxStaticText* m_staticText1;
		wxTextCtrl* txtRata;
		wxStaticText* m_staticText2;
		wxTextCtrl* txtMaxKol;
		wxStaticText* m_staticText4;
		wxTextCtrl* txtTrosSkl;
		wxStaticText* m_staticText5;
		wxTextCtrl* txtMaxZal;
		wxStaticText* m_staticText6;
		wxTextCtrl* txtBrojRazd;
		wxStaticText* m_staticText3;
		wxTextCtrl* txtTrosNab;
		wxStaticText* m_staticText8;
		wxGrid* gridPotraznja;
		wxButton* btnIzracunaj;
		wxButton* m_button3;
		wxStaticText* m_staticText9;
		wxGrid* gridRjesenje;
		wxStaticText* m_staticText81;
		wxGrid* gridOdluka;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnClose( wxCloseEvent& event ) { event.Skip(); }
		virtual void Izracunaj( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnQuit( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAbout( wxCommandEvent& event ) { event.Skip(); }
		virtual void ParamPromijenjen( wxCommandEvent& event ) { event.Skip(); }
		virtual void GridPotraznjaPromijenjena( wxGridEvent& event ) { event.Skip(); }
		virtual void OtvoriDijalogIspisa( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		GUIFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Optimalna nabava - dinamičko programiranje"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 800,650 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~GUIFrame();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class dlgIspisRacunanja
///////////////////////////////////////////////////////////////////////////////
class dlgIspisRacunanja : public wxDialog 
{
	private:
	
	protected:
		wxTextCtrl* txtIspis;
		wxButton* m_button2;
		
		// Virtual event handlers, overide them in your derived class
		virtual void Zatvori( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		dlgIspisRacunanja( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 800,768 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~dlgIspisRacunanja();
	
};

#endif //__GUIFRAME_H__
