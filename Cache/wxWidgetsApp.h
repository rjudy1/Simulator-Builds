// Author: Rachael Judy
// Date: 3/31/2020
// Purpose:  Template wxWidgets application class header file.  No modification to this file are required
// MODIFICATIONS: Rachael Judy - 3/31/2020


#ifndef __WXWIDGETSAPP_H
#define __WXWIDGETSAPP_H

#include <wx/wx.h>

class wxWidgetsApp : public wxApp {
  public:
    wxWidgetsApp();
    virtual ~wxWidgetsApp();
    virtual bool OnInit();
};

DECLARE_APP(wxWidgetsApp)

#endif
