//
// Created by uffa on 28/08/2021.
//

#include "Register.h"

std::list<Activities> Register::ShowActivitiesByDay(int dayU) {
    std::list<Activities> activitiesByDay;
    for (const auto& itr:activities) {
        if (itr.getDay() == dayU) {
            activitiesByDay.push_back(itr);
        }
    }
    return activitiesByDay;
}

wxString Register::ShowActivitiesByDayStamp(int dayX) {
    std::list<Activities> activitybyday;
    std::string lista;
    activitybyday = ShowActivitiesByDay(dayX);
    for ( const auto& itr: activitybyday) {
        lista += itr.getDescription() + "   ";
    }
    wxString mystring(lista);
    return mystring;
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

