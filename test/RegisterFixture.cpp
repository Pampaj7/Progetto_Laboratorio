

#include "gtest/gtest.h"
#include "../Register.h"
#include "../Activities.h"

class RegisterSuite : public ::testing::Test {

protected:

    virtual void setUp() {
        Activities a(12, 13, 5, "powerlifting");
        Activities b(21, 23, 11, "Gara");
        R.setOwner("Pampaj");
        R.addActivities(a);
        R.addActivities(b);
    }

    Register R;
};

TEST_F(RegisterSuite, TestOwner) {
    R.setOwner("pampaj-junior");
    ASSERT_EQ("pampaj-junior", R.getOwner()); // register must have c'tor initialized
}

TEST_F(RegisterSuite, TestAddActivities) {
    //Activities b(21, 23, 11, "Gara");
    //R.addActivities(b); //check
    ASSERT_EQ(true, R.isEmpty());
}

TEST_F(RegisterSuite, testdata) {
    R.setData(1);
    ASSERT_EQ(1, R.getData());
}


//33 min del 21


// la suite di test che raggruppa i casi di test e organizziamo la nostra suite
//relativamente ad un aspetto fondamentale del nostro codice es. videogame dove devi gestire le
//collisioni delle varie entità del gioco avremo quindi un test suite delle collisiooni
//valutando tutte le possibili collisioni conm i possibili oggetti

// nel caso più casi di test abbiano bisogno dello stesso ambiente per poter essere valutati
// e per cui dobbiamo organizzare e istanziare diverse entità o impostare certi valori in certi oggetti
//abbiamo una fixture che consente di avere un setup comune prima dell'esecuzione di ogni test
// tipo dobbiamo controllare un sistema di gestione degli ordini online, nel setup della fixture
//creaiamo un database di prova ci inseriamo dei dati nel database e eseguiamo i vari test
// e in fondo ne cancelliamo tale database nel teardown