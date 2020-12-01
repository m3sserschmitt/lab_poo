#include "automobil.h"

#ifndef MASINA_UNDERCOVER_H
#define MASINA_UNDERCOVER_H

class MasinaUndercover : public Automobil
{
    int viteza;
    int nr_gloante;

public:
    MasinaUndercover();
    MasinaUndercover(string nume, string model, string utilizare, int viteza, int nr_gloante);
    
    void afisare();
};

#endif