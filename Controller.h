//
// Created by uffa on 05/09/2021.
//

#ifndef PROGETTO_LABORATORIO_CONTROLLER_H
#define PROGETTO_LABORATORIO_CONTROLLER_H


#include "Register.h"

class Controller {
public:

    Controller(Register* m) : aRegister(m) {}
    void Click();

private:
    Register* aRegister;
};



#endif //PROGETTO_LABORATORIO_CONTROLLER_H
