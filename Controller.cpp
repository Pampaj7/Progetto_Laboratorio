//
// Created by uffa on 05/09/2021.
//

#include "Controller.h"


void Controller::Click() {
    int value = model->getData();
    value++;
    model->setData(value);
}

