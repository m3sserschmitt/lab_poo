#include "produs_neperisabil.h"

ProdusNeperisabil::ProdusNeperisabil(){
    this->garantie = 0;
}

ProdusNeperisabil::ProdusNeperisabil(const ProdusNeperisabil &p): Produs(p){
    this->garantie = p.garantie;
}

ProdusNeperisabil::ProdusNeperisabil(string nume, int pretBrut, int garantie): Produs(nume, pretBrut){
    this->garantie = garantie;
}

float ProdusNeperisabil::calculeazaPret()
{

    return pretBrut + (10 * pretBrut) / 100;
}

ostream &operator<<(ostream &out, const ProdusNeperisabil &p)
{
    out << (Produs &)p;
    out << ", garantie: " << p.garantie;
    return out;
}

istream &operator>>(istream &in, ProdusNeperisabil &p)
{   
    cout << "introduceti produs neperisabil: " << endl;
    in >> (Produs &)p;
    cout << "ani garantie: ";
    in >> p.garantie;
    return in;
}