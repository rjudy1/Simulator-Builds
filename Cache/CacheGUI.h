// Author: Rachael Judy
// Date: 3/31/2020
// Purpose: Generates GUI for cache simulator

///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 30 2011)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __CACHEGUI_H__
#define __CACHEGUI_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class CacheGUI
///////////////////////////////////////////////////////////////////////////////
class CacheGUI : public wxFrame 
{
	private:
	
	protected:
		wxStaticText* m_staticText26;
		wxTextCtrl* inputText;
		wxStaticText* resultLabel;
		wxButton* searchButton;
		wxButton* m_button2;
		wxStaticText* m_staticText2;
		wxStaticText* m_staticText3;
		wxStaticText* m_staticText4;
		wxStaticText* tag000;
		wxStaticText* data000;
		wxStaticText* tag001;
		wxStaticText* data001;
		wxStaticText* m_staticText9;
		wxStaticText* tag010;
		wxStaticText* data010;
		wxStaticText* tag011;
		wxStaticText* data011;
		wxStaticText* m_staticText14;
		wxStaticText* tag100;
		wxStaticText* data100;
		wxStaticText* tag101;
		wxStaticText* data101;
		wxStaticText* m_staticText20;
		wxStaticText* tag110;
		wxStaticText* data110;
		wxStaticText* tag111;
		wxStaticText* data111;
		
		// Virtual event handlers, overide them in your derived class
		virtual void searchCache( wxCommandEvent& event ) { event.Skip(); }
		virtual void resetCache( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		CacheGUI( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Cache Simulator - Rachael Judy"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 333,300 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~CacheGUI();
	
};

#endif //__CACHEGUI_H__
