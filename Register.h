//
// Created by uffa on 28/08/2021.
//

#ifndef PROGETTO_LABORATORIO_REGISTER_H
#define PROGETTO_LABORATORIO_REGISTER_H


#include <list>
#include <iostream>
#include "Activities.h"
#include "Subject.h"

class Register : public Subject {
public:
    //AAA must be initialized
    explicit Register(const std::string &name = "aa") : Owner(name) {}

    virtual ~Register() = default;

    std::list<Activities> ShowActivitiesByDay(int dayU);  //ocho

    void addActivities(const Activities &work) {
        activities.push_back(work);
    }

    void removeActivities(const Activities &work) {
        activities.remove(work);
    }

    std::string ShowActivitiesByDayStamp(int dayX);

    const std::string &getOwner() const;

    void setOwner(const std::string &owner);

    const std::list<Activities> &getActivities() const;

    void setActivities(const std::list<Activities> &activities);

    int getData() const {
        return data;
    }
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
