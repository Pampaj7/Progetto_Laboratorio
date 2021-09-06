//
// Created by uffa on 05/09/2021.
//

#ifndef PROGETTO_LABORATORIO_SUBJECT_H
#define PROGETTO_LABORATORIO_SUBJECT_H

#include "Observer.h"

class Subject {
public:
    virtual ~Subject() {}
    virtual void notify() = 0;
    virtual void addObserver(Observer* o) = 0;
    virtual void removeObserver(Observer* o) = 0;
};


#endif //PROGETTO_LABORATORIO_SUBJECT_H
