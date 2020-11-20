#include <string>
#include <iostream>

using namespace std;

#ifndef PRODUS_H
#define PRODUS_H

class Produs
{
protected:
    string nume;
    float pretBrut;

public:
    Produs() {  };
    Produs(const Produs &);
    Produs(string nume, float pretBrut);
    
    void afisareBrand();
    virtual float calculeazaPret();

    friend ostream &operator<<(ostream &out, const Produs &p);
    friend istream &operator>>(istream &in, Produs &p);
};

#endif