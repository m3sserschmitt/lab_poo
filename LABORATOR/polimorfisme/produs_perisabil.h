#include "produs.h"

#ifndef PRODUS_PERISABIL_H
#define PRODUS_PERISABIL_H

class ProdusPerisabil : public Produs
{
    string dataExpirare;

public:
    ProdusPerisabil() {  };
    ProdusPerisabil(const ProdusPerisabil &);
    ProdusPerisabil(string nume, float pretBrut, string dataExpirare);
    float calculeazaPret();

    friend ostream &operator<<(ostream &out, const ProdusPerisabil &p);
    friend istream &operator>>(istream &in, ProdusPerisabil &p);
};

#endif