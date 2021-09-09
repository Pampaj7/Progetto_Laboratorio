//
// Created by uffa on 04/09/2021.
//

#include "View.h"
#include <wx/panel.h>

View::View(Register *model, Controller *controller, wxWindow *parent, wxWindowID id, const wxString &title,
           const wxPoint &pos, const wxSize &size, long style) : wxFrame(parent, id, title, pos, size, style) {
    this->model = model;
    this->model->addObserver(this);
    this->controller = controller;

    this->SetSizeHints(wxDefaultSize, wxDefaultSize);

    wxSizer *frameSizerOutput;
    frameSizerOutput = new wxBoxSizer(wxHORIZONTAL);

    staticTextList = new wxStaticText(this, wxID_ANY, wxT("Attività giornaliere"), wxDefaultPosition, wxDefaultSize, 0);
    staticTextList->Wrap(-1);
    frameSizerOutput->Add(staticTextList, 0, wxLEFT | wxRIGHT, 20);

    textCtrlOutput = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    frameSizerOutput->Add(textCtrlOutput, 0, wxLEFT | wxRIGHT, 10);

    wxSizer *frameSizerInput;
    frameSizerInput = new wxBoxSizer(wxHORIZONTAL);

    staticTextDay = new wxStaticText(this, wxID_ANY, wxT("Inserisci il giorno"), wxDefaultPosition, wxDefaultSize, 0);
    staticTextDay->Wrap(-1);
    frameSizerInput->Add(staticTextDay, 0, wxLEFT | wxRIGHT, 10);

    textCtrlInput = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    frameSizerInput->Add(textCtrlInput, 0, wxLEFT | wxRIGHT, 10);

    wxSizer *buttonSizer;
    buttonSizer = new wxBoxSizer(wxVERTICAL);

    clickButton = new wxButton(this, wxID_ANY, wxT("Mostra impegni"), wxDefaultPosition, wxDefaultSize, 0);
    buttonSizer->Add(clickButton, 0, wxALIGN_CENTER | wxUP | wxRIGHT, 10);

    wxSizer *inputOutputSizer;
    inputOutputSizer = new wxBoxSizer(wxVERTICAL);
    inputOutputSizer->Add(frameSizerInput, 1, wxUP, 10);
    inputOutputSizer->Add(frameSizerOutput, 1, wxUP, 10);

    wxBoxSizer *allSizer;
    allSizer = new wxBoxSizer(wxHORIZONTAL);
    allSizer->Add(inputOutputSizer, 1, wxALL, 5);
    allSizer->Add(buttonSizer, 1, wxALL, 5);


    this->SetSizer(allSizer);
    this->Layout();

    this->Centre(wxBOTH);

    clickButton->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(View::onClickButton), NULL,this);

}


View::~View() {
    clickButton->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(View::onClickButton), NULL,this);
    model->removeObserver(this);
}

void View::update() {
   int giorno =20;
    giorno = wxAtoi(textCtrlInput->GetValue());
    wxString value = model->ShowActivitiesByDayStamp(giorno);
    textCtrlOutput->ChangeValue(value);
}


void View::onClickButton(wxCommandEvent &event) {
    controller->Click();
}