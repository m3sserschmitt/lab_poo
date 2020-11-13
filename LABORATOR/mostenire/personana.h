#include <iostream>
#include <string>

using namespace std;

class Persoana
{

    string nume;
    string cnp;
    float inaltime;

public:
    Persoana();
    Persoana(const Persoana &p);
    Persoana(string nume, string cnp, float inaltime);

    bool operator<(Persoana);
    bool operator>(Persoana);
    bool operator>=(Persoana);
    bool operator<=(Persoana);
    bool operator==(Persoana);

    void operator=(Persoana &);

    friend ostream &operator<<(ostream &out, Persoana &p);
};