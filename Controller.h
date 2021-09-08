//
// Created by uffa on 05/09/2021.
//

#ifndef PROGETTO_LABORATORIO_CONTROLLER_H
#define PROGETTO_LABORATORIO_CONTROLLER_H


#include "Register.h"

class Controller {
public:
    Controller(Register* m) : model(m) {}
    void Run();
private:
    Register* model;
};



#endif //PROGETTO_LABORATORIO_CONTROLLER_H
