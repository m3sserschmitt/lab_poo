#include <string>
#include <iostream>

using namespace std;
 
#ifndef AUTOMOBIL_H
#define AUTOMOBIL_H

class Automobil
{
    string marca;
    string model;
    string utilizare;

public:
    Automobil();
    Automobil(string marca, string model, string utilizare);

    virtual void afisare();
};

#endif