//
// Created by uffa on 04/09/2021.
//

#include "View.h"
#include <wx/panel.h>

View::View(Register *model, Controller *controller, wxWindow *parent, wxWindowID id, const wxString &title,const wxPoint &pos, const wxSize &size, long style) : wxFrame(parent, id, title, pos, size, style) {
    this->model = model; //bo
    this->model->addObserver(this);
    this->controller = controller;

    this->SetSizeHints(wxDefaultSize, wxDefaultSize);

    wxBoxSizer *frameSizer;
    frameSizer = new wxBoxSizer(wxHORIZONTAL);


    staticText = new wxStaticText(this, wxID_ANY, wxT("Lista Attività"), wxDefaultPosition, wxDefaultSize, 0);
    staticText->Wrap(-1); // il wrap aggiusta da sè la dimensione del testo
    frameSizer->Add(staticText, 0, wxALL, 5); //lista attività


    textCtrl = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    frameSizer->Add(textCtrl, 0, wxALL, 5); //finestra output
/////////////////////////
    wxBoxSizer *frameSizerInput;
    frameSizerInput = new wxBoxSizer(wxVERTICAL);

    textCtrlinput = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    frameSizerInput->Add(textCtrlinput, 10, wxALL, 15);

   wxBoxSizer *checkButton;
   checkButton = new wxBoxSizer(wxVERTICAL);

   runButton = new wxButton(this, wxID_ANY, wxT("Invio"), wxDefaultPosition, wxDefaultSize, 0);

    this->SetSizer(frameSizer);
    this->Layout();

    this->Centre(wxBOTH);
    update();
}

void View::onRunButtonClick(wxCommandEvent &event) {
   //  controller->
}



View::~View() {

    model->removeObserver(this);
}

void View::update() {
    int giorno;
    giorno = wxAtoi(textCtrlinput->GetValue()); //da capire quale
    wxString value = model->ShowActivitiesByDayStamp(giorno);
    textCtrl->ChangeValue(value);
}

