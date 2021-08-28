//
// Created by uffa on 28/08/2021.
//

#ifndef PROGETTO_LABORATORIO_REGISTER_H
#define PROGETTO_LABORATORIO_REGISTER_H


#include <list>
#include "Activities.h"

class Register {
public:

    std::list<Activities> ShowActivitiesByDay(int dayU);

    Register() {}

    virtual ~Register() = default;

    void addActivities(const Activities &work) {
        activities.push_back(work);
    }

    void removeActivities(const Activities &work) {
        activities.remove(work);
    }


private:
    std::list<Activities> activities;
};


#endif //PROGETTO_LABORATORIO_REGISTER_H
