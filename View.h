//
// Created by uffa on 04/09/2021.
//

#ifndef PROGETTO_LABORATORIO_VIEW_H
#define PROGETTO_LABORATORIO_VIEW_H

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
#include "Controller.h"
#include "Register.h"


class View : public wxFrame, public Observer {
public:
    View(Register* model, Controller* controller, wxWindow* parent=NULL, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
    virtual ~View();
    virtual void update() override;

private:
    Register* model;
    Controller* controller;
    wxStaticText* staticTextList;
    wxStaticText* staticTextDay;
    wxTextCtrl* textCtrlOutput;
    wxTextCtrl* textCtrlInput;
    wxButton* clickButton;


    virtual void onClickButton(wxCommandEvent& event );


};


#endif //PROGETTO_LABORATORIO_VIEW_H
