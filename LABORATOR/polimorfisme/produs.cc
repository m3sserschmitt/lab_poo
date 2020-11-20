#include "produs.h"

using namespace std;

Produs::Produs(const Produs &p)
{
    this->nume = p.nume;
    this->pretBrut = p.pretBrut;
}

Produs::Produs(string nume, float pretBrut)
{
    this->nume = nume;
    this->pretBrut = pretBrut;
}

void Produs::afisareBrand()
{
    cout << "Acest produs apartine Ruja's SRL";
}

float Produs::calculeazaPret()
{
    return pretBrut;
}

ostream &operator<<(ostream &out, const Produs &p)
{

    out << p.nume;
    return out;
}

istream &operator>>(istream &in, Produs &p)
{

    cout << "Numele este: ";
    in >> p.nume;
    cout << "Pretul brut este: ";
    in >> p.pretBrut;

    return in;
}