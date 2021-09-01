//
// Created by uffa on 28/08/2021.
//

#include "Activities.h"

int Activities::getStart() const {
    return start;
}

void Activities::setStart(int start) {
    Activities::start = start;
}

int Activities::getAnEnd() const {
    return end;
}

void Activities::setAnEnd(int anEnd) {
    end = anEnd;
}

int Activities::getDay() const {
    return day;
}

void Activities::setDay(int day) {
    Activities::day = day;
}

const std::string &Activities::getDescription() const {
    return description;
}

void Activities::setDescription(const std::string &description) {
    Activities::description = description;
}


