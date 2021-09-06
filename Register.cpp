//
// Created by uffa on 28/08/2021.
//

#include "Register.h"

std::list<Activities> Register::ShowActivitiesByDay(int dayU) {
    std::list<Activities> activitiesByDay;
    for (auto itr:activities)
        if (itr.getDay() == dayU)
            activitiesByDay.push_back(itr);
    return activitiesByDay;
}

std::string Register::ShowActivitiesByDayStamp(int dayX) {
    std::list <Activities> activitiees;
    std::string list;
    activitiees = ShowActivitiesByDay(dayX);
    for (auto itr:activitiees) {
        list += itr.getDescription() + "\n";
    }
    return list;
}

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

