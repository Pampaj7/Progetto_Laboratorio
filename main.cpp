#include <iostream>
#include "Register.h"
#include "Activities.h"

int main() {
    Activities studio(13, 14, 20, "Studio");
    Activities palestra(17, 19, 20, "palestra");
    Activities giostra(12, 13, 19, "bruuum");

    Register registro;
    registro.addActivities(studio);
    registro.addActivities(palestra);
    registro.addActivities(giostra);

    std::list<Activities> attivitagiornaliera = registro.ShowActivitiesByDay(20);
    registro.ShowActivitiesByDayStamp(attivitagiornaliera);

    return 0;
}
