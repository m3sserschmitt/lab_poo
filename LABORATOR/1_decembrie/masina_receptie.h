#include "automobil.h"

#ifndef MASINA_RECEPTIE_H
#define MASINA_RECEPTIE_H

class MasinaReceptie : public Automobil
{
    int distanta_acustica;
    int distanta_video;

public:

    MasinaReceptie();
    MasinaReceptie(string marca, string model, string utilizare, int distanta_acustica, int distanta_video);

    void afisare();
};

#endif