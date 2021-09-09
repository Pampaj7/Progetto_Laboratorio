//
// Created by uffa on 28/08/2021.
//

#ifndef PROGETTO_LABORATORIO_REGISTER_H
#define PROGETTO_LABORATORIO_REGISTER_H


#include <list>
#include <iostream>
#include "Activities.h"
#include "Subject.h"
#include<wx/string.h>

class Register : public Subject {
public:

    explicit Register(const std::string &name = "aa") : Owner(name) {}

    virtual ~Register() = default;

    std::list<Activities> ShowActivitiesByDay(int dayU);

    void addActivities(const Activities &work) {
        activities.push_back(work);
    }

    wxString ShowActivitiesByDayStamp(int dayX);

    const std::string &getOwner() const;

    void setOwner(const std::string &owner);

    void setData(const int i);

    virtual void addObserver(Observer* o) override;

    virtual void removeObserver(Observer* o) override;

    virtual void notify() override;


private:
    std::list<Activities> activities;
    std::string Owner;
    std::list<Observer*> observers;
    int data = 0;
};


#endif //PROGETTO_LABORATORIO_REGISTER_H
