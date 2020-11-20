#include "produs_perisabil.h"

ProdusPerisabil::ProdusPerisabil(const ProdusPerisabil &p) : Produs(p)
{
    this->dataExpirare = p.dataExpirare;
}

ProdusPerisabil::ProdusPerisabil(string nume, float pretBrut, string dataExpirare): Produs(nume, pretBrut)
{
    this->dataExpirare = dataExpirare;
}

float ProdusPerisabil::calculeazaPret()
{

    return pretBrut + (40 * pretBrut) / 100;
}

ostream &operator<<(ostream &out, const ProdusPerisabil &p)
{
    out << (Produs &)p;
    out << " " << p.dataExpirare;
    return out;
}

istream &operator>>(istream &in, ProdusPerisabil &p)
{
    cout << "introduceti produs perisabil: " << endl;
    in >> (Produs &)p;
    cout << "Dati data: ";
    in >> p.dataExpirare;
    return in;
}