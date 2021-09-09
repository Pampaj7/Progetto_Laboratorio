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
        lista += itr.getDescription() + "\n";
    }
    wxString mystring(lista);
    return mystring;
}
/*
wxString Register::ShowActivitiesByDayStamp(int dayX) {


    std::list<Activities> list;
    std::string basicString;
    std::cout << "fuori primo for" << std::endl;
    for (const auto& itr:activities) {
        if (itr.getDay() == dayX) {
            list.push_back(itr);
            std::cout << "dentro primo for" << std::endl;
        }
    }
    std::cout << "fuori secondo for" << std::endl;
    for ( const auto& itr: list) {
        basicString += itr.getDescription() + "\n";
        std::cout << "dentro secondo for" << std::endl;
    }

    wxString mystring(basicString); //
    return mystring;
}*/


const std::string &Register::getOwner() const {
    return Owner;
}

void Register::setOwner(const std::string &owner) {
    Owner = owner;
}

const std::list<Activities> &Register::getActivities() const {
    return activities;
}

void Register::setActivities(const std::list<Activities> &activities) {
    Register::activities = activities;
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

