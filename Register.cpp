//
// Created by uffa on 28/08/2021.
//

#include "Register.h"

wxString Register::showActivitiesByDay(int dayX) {

    std::list<Activities> activitiesByDay;
    std::string lista;

    for (const auto &itr: activities) {
        if (itr.getDay() == dayX) {
            activitiesByDay.push_back(itr);
        }
    }

    for (const auto &itr: activitiesByDay) {
        lista += itr.getDescription() + "   ";
    }

    wxString wxString(lista);
    return wxString;
}



const std::string &Register::getOwner() const {
    return Owner;
}

void Register::setOwner(const std::string &owner) {
    Owner = owner;
}

void Register::notify() {
    for (Observer* observer : observers)
        observer->update();
}

void Register::setData(const int i) {
    data = i;
    notify();
}

void Register::addObserver(Observer* o) {
    observers.push_back(o);
}

void Register::removeObserver(Observer* o) {
    observers.remove(o);
}

