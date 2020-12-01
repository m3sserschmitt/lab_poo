#include "automobil.h"

#ifndef MASINA_INTERVENTIE_H
#define MASINA_INTERVENTIE_H

class MasinaInterventie : public Automobil
{
    int nr_locuri;
    bool mitraliera;

public:
    MasinaInterventie();
    MasinaInterventie(string marca, string model, string utilizare, int locuri, bool mitraliera);

    void afisare();
};

#endif