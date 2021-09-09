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
    bool OnInit() override {

        Activities studio(13, 14, 20, "Studio");
        Activities palestra(17, 19, 20, "palestra");
        Activities giostra(12, 13, 19, "Giostra");
        Activities pranzo(2, 3, 3, "Pranzo");
        Activities cena(2, 3, 4, "Cena");
        Activities merenda(1, 4, 20, "Merenda");
        Activities videogame(7, 8, 19, "Videogiochi");
        Activities stream(12, 15, 19, "stream");

        auto* model = new Register;

        model->addActivities(studio);
        model->addActivities(palestra);
        model->addActivities(giostra);
        model->addActivities(pranzo);
        model->addActivities(cena);
        model->addActivities(merenda);
        model->addActivities(videogame);
        model->addActivities(stream);

        auto* controller = new Controller(model);
        View *frame = new View(model, controller, NULL, wxID_ANY, "Progetto_Laboratorio" );
        frame->Show( true );

        return true;
    }

};


#endif //PROGETTO_LABORATORIO_MYAPP_H
