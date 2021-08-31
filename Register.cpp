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

void Register::ShowActivitiesByDayStamp(const std::list<Activities> &a) {
    for (auto itr:a)
        std::cout << itr.getDescription() << std::endl;
}
