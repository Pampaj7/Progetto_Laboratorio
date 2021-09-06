//
// Created by uffa on 04/09/2021.
//

#include "View.h"


View::View(Register *model, Controller *controller, wxWindow *parent, wxWindowID id, const wxString &title,const wxPoint &pos, const wxSize &size, long style) : wxFrame(parent, id, title, pos, size, style) {
    this->model = model; //bo
    this->model->addObserver(this);
    this->controller = controller;

    this->SetSizeHints(wxDefaultSize, wxDefaultSize);

    wxBoxSizer *frameSizer;
    frameSizer = new wxBoxSizer(wxHORIZONTAL);

    staticText = new wxStaticText(this, wxID_ANY, wxT("Lista Attività"), wxDefaultPosition, wxDefaultSize, 0);
    staticText->Wrap(-1);
    frameSizer->Add(staticText, 0, wxALL, 5); //lista attività

    textCtrl = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    frameSizer->Add(textCtrl, 0, wxALL, 5); //finestra output

    textCtrl = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    frameSizer->Add(textCtrl, 0, wxALL, 5); //finestra output

    wxBoxSizer *buttonSizer;
    buttonSizer = new wxBoxSizer(wxVERTICAL);



    incrementButton = new wxButton(this, wxID_ANY, wxT("Increment"), wxDefaultPosition, wxDefaultSize, 0);
    buttonSizer->Add(incrementButton, 0, wxALL, 5);

    decrementButton = new wxButton(this, wxID_ANY, wxT("Decrement"), wxDefaultPosition, wxDefaultSize, 0);
    buttonSizer->Add(decrementButton, 0, wxALL, 5);

    frameSizer->Add(buttonSizer, 1, wxEXPAND, 5);

    this->SetSizer(frameSizer);
    this->Layout();

    this->Centre(wxBOTH);

    // Connect Events
    incrementButton->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(View::onIncrementButtonClick), NULL,
                             this);
    decrementButton->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(View::onDecrementButtonClick), NULL,
                             this);

    update();
}

View::~View() {
    // Disconnect Events
    incrementButton->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(View::onIncrementButtonClick), NULL,
                                this);
    decrementButton->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(View::onDecrementButtonClick), NULL,
                                this);
    // unsubscribe from model
    model->removeObserver(this);
}

void View::onIncrementButtonClick(wxCommandEvent &event) {
    controller->increment();
}

void View::onDecrementButtonClick(wxCommandEvent &event) {
    controller->decrement();
}

void View::update() {
    std::string value = model->ShowActivitiesByDayStamp();
    wxString wxIntString = wxString::Format(wxT("%i"), value);
    textCtrl->ChangeValue(wxIntString);
}
