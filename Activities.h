//
// Created by uffa on 28/08/2021.
//

#ifndef PROGETTO_LABORATORIO_ACTIVITIES_H
#define PROGETTO_LABORATORIO_ACTIVITIES_H

#include <ctime>
#include <string>

class Activities {
public:

    int getStart() const;

    int getAnEnd() const;

    int getDay() const;

    const std::string &getDescription() const;


    Activities(int aNstart, int anEnd, int dayY, const std::string &descriptionn) : start(aNstart), end(anEnd),
                                                                                    day(dayY),
                                                                                    description(descriptionn) {}

    virtual ~Activities() = default;

    bool operator==(const Activities &up) const {
        if (description == up.description)
            if (day == up.day)
                if (end == up.end)
                    if (start == up.start)
                        return true;

        return false;
    }

private:
    int start;
    int end;
    int day;
    std::string description;
};


#endif //PROGETTO_LABORATORIO_ACTIVITIES_H
