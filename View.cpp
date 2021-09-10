//
// Created by uffa on 04/09/2021.
//

#include "View.h"
#include <wx/panel.h>

View::View(Register *pRegister, Controller *controller, wxWindow *parent, wxWindowID id, const wxString &title,
           const wxPoint &pos, const wxSize &size, long style) : wxFrame(parent, id, title, pos, size, style) {
    this->aRegister = pRegister;
    this->aRegister->addObserver(this);
    this->controller = controller;

    this->SetSizeHints(wxDefaultSize, wxDefaultSize);

    wxSizer *frameSizerInput;
    frameSizerInput = new wxBoxSizer(wxHORIZONTAL);

    wxSizer *frameSizerOutput;
    frameSizerOutput = new wxBoxSizer(wxHORIZONTAL);

    staticTextDay = new wxStaticText(this, wxID_ANY, wxT("Inserisci il giorno"), wxDefaultPosition, wxDefaultSize, 0);
    staticTextDay->Wrap(-1);
    frameSizerInput->Add(staticTextDay, 0, wxLEFT | wxRIGHT, 24);

    staticTextList = new wxStaticText(this, wxID_ANY, wxT("Attività giornaliere"), wxDefaultPosition, wxDefaultSize, 0);
    staticTextList->Wrap(-1);
    frameSizerOutput->Add(staticTextList, 0, wxLEFT | wxRIGHT, 20);

    textCtrlInput = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    frameSizerInput->Add(textCtrlInput, 0, wxLEFT | wxRIGHT, 10);

    textCtrlOutput = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    frameSizerOutput->Add(textCtrlOutput, 0, wxLEFT | wxRIGHT, 10);

    wxSizer *buttonSizer;
    buttonSizer = new wxBoxSizer(wxVERTICAL);

    clickSearchButton = new wxButton(this, wxID_ANY, wxT("Mostra impegni"), wxDefaultPosition, wxDefaultSize, 0);
    buttonSizer->Add(clickSearchButton, 0, wxALIGN_CENTER | wxUP | wxRIGHT, 10);

    wxSizer *sizer;
    sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(frameSizerInput, 1, wxUP, 10);
    sizer->Add(frameSizerOutput, 1, wxUP, 10);

    wxBoxSizer *allSizer;
    allSizer = new wxBoxSizer(wxHORIZONTAL);
    allSizer->Add(sizer, 1, wxALL, 5);
    allSizer->Add(buttonSizer, 1, wxALL, 5);


    this->SetSizer(allSizer);
    this->Layout();
    this->Centre(wxBOTH);

    clickSearchButton->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(View::onClickSearchButton), NULL,
                               this);

}


View::~View() {
    clickSearchButton->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(View::onClickSearchButton), NULL,
                                  this);
    aRegister->removeObserver(this);
}


void View::update() {
    int giorno = 20;
    giorno = wxAtoi(textCtrlInput->GetValue());
    wxString value = aRegister->showActivitiesByDay(giorno);
    textCtrlOutput->ChangeValue(value);
}


void View::onClickSearchButton(wxCommandEvent &event) {
    controller->ClickSearch();
}