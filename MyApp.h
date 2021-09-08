//
// Created by uffa on 04/09/2021.
//

#ifndef PROGETTO_LABORATORIO_MYAPP_H
#define PROGETTO_LABORATORIO_MYAPP_H

#include "wx/wx.h"
#include "wx/wxprec.h"
#include "View.h"


class MyApp : public wxApp {
public:
    virtual bool OnInit() {
        Register* model = new Register;
        Controller* controller = new Controller(model);
        View *frame = new View(model, controller, NULL, wxID_ANY, "Progetto_Laboratorio" );
        frame->Show( true );
        return true;
    }

};


#endif //PROGETTO_LABORATORIO_MYAPP_H
