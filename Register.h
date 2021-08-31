//
// Created by uffa on 28/08/2021.
//

#ifndef PROGETTO_LABORATORIO_REGISTER_H
#define PROGETTO_LABORATORIO_REGISTER_H


#include <list>
#include <iostream>
#include "Activities.h"

class Register {
public:

    Register(const std::string &name) : Owner(name) {}

    virtual ~Register() = default;

    std::list<Activities> ShowActivitiesByDay(int dayU);  //ocho

    void addActivities(const Activities &work) {
        activities.push_back(work);
    }

    void removeActivities(const Activities &work) {
        activities.remove(work);
    }

    void ShowActivitiesByDayStamp(const std::list<Activities> &a);

private:
    std::list<Activities> activities;
    std::string Owner;
};


#endif //PROGETTO_LABORATORIO_REGISTER_H
