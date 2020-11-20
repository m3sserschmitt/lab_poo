#include "produs.h"

#ifndef PRODUS_NEPERISABIL_H
#define PRODUS_NEPERISABIL_H

class ProdusNeperisabil : public Produs
{
    int garantie;
public:
    ProdusNeperisabil();
    ProdusNeperisabil(const ProdusNeperisabil &);
    ProdusNeperisabil(string nume, int pretBrut, int garantie);
    float calculeazaPret();

    friend ostream &operator<<(ostream &out, const ProdusNeperisabil &p);
    friend istream &operator>>(istream &in, ProdusNeperisabil &p);
};

#endif