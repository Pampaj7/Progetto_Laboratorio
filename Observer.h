//
// Created by uffa on 05/09/2021.
//

#ifndef PROGETTO_LABORATORIO_OBSERVER_H
#define PROGETTO_LABORATORIO_OBSERVER_H


class Observer {
public:
    virtual ~Observer() {}
    virtual	void update() = 0;
};


#endif //PROGETTO_LABORATORIO_OBSERVER_H
