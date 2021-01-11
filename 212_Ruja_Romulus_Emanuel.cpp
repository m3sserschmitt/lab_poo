/*
Ruja Romulus-Emanuel 212
g++ (Debian 10.2.0-16) 10.2.0
Eduard Szmeteanca
*/

#include <iostream>
#include <string>
#include <list>
#include <map>
#include <vector>

using namespace std;

class Vaccin
{
    float pret;
    float temperatura;
    list<string> substante;
    string producatori;

    string schema_vaccinare;

public:
    Vaccin()
    {
        this->pret = 0;
        this->temperatura = 0;
    }

    Vaccin(float pret, float temperatura, list<string> substante, string producatori)
    {
        this->pret = pret;
        this->temperatura = temperatura;
        this->substante = substante;
        this->producatori = producatori;
    }

    Vaccin(const Vaccin &v)
    {
        this->pret = v.pret;
        this->temperatura = v.temperatura;
        this->substante = v.substante;
        this->producatori = v.producatori;
    }

    Vaccin &operator=(const Vaccin &v)
    {
        if (this != &v)
        {
            this->pret = v.pret;
            this->temperatura = v.temperatura;
            this->substante = v.substante;
        }

        return *this;
    }

    virtual ~Vaccin() {}

    virtual void afisareSchemaVaccinare() = 0;

    virtual ostream &afisare(ostream &out)
    {
        out << "producatori: " << this->producatori << "\n";
        out << "pret: " << this->pret << "\n";
        out << "temperatura de pastrare: " << this->temperatura << "\n";

        list<string>::iterator it = this->substante.begin();
        list<string>::iterator end = this->substante.end();

        if (this->substante.size())
        {
            out << "substante componente: \n";
            for (; it != end; it++)
            {
                out << *it << "\n";
            }
        }

        return out;
    }

    virtual istream &citire(istream &in)
    {

        cout << "producatori: ";
        in >> this->producatori;

        cout << "pret: ";
        in >> this->pret;

        cout << "temperatura pastrare: ";
        in >> this->temperatura;

        cout << "substante componente(\"0\" pentru terminare): ";
        string subst;

        while (true)
        {
            in >> subst;

            if (subst == "0")
            {
                break;
            }

            this->substante.push_back(subst);

            subst.clear();
        }

        return in;
    }

    friend ostream &operator<<(ostream &out, Vaccin &v)
    {
        return v.afisare(out);
    }

    friend istream &operator>>(istream &in, Vaccin &v)
    {
        return v.citire(in);
    }
};

class VaccinAntigripal : public Vaccin
{
    list<string> tulpini;
    bool conform_OMS;

public:
    VaccinAntigripal() : Vaccin()
    {
        this->tulpini = {};
        this->conform_OMS = false;
    }

    VaccinAntigripal(float pret, float temperatura, list<string> substante, string producatori, list<string> tulpini, bool conform_OMS) : Vaccin(pret, temperatura, substante, producatori)
    {
        this->tulpini = tulpini;
        this->conform_OMS = conform_OMS;
    }

    VaccinAntigripal(const VaccinAntigripal &v) : Vaccin(v)
    {
        this->tulpini = v.tulpini;
        this->conform_OMS = v.conform_OMS;
    }

    void afisareSchemaVaccinare()
    {
        cout << "se administrează la adulți o doză de 0.5 ml, iar la copii și adolescenți o doză de 0.3 ml, repetându-se din 2 în 2 ani\n";
    }

    VaccinAntigripal &operator=(const VaccinAntigripal &v)
    {
        if (this != &v)
        {
            this->tulpini = v.tulpini;
            this->conform_OMS = v.conform_OMS;
        }

        return *this;
    }

    istream &citire(istream &in)
    {
        Vaccin::citire(in);

        cout << "conform cu OMS: ";
        in >> this->conform_OMS;

        string tulp;

        cout << "introduceti tulpinile(\"0\" pentru terminare): ";
        while (true)
        {
            in >> tulp;

            if (tulp == "0")
            {
                break;
            }

            this->tulpini.push_back(tulp);

            tulp.clear();
        }

        return in;
    }

    ostream &afisare(ostream &out)
    {
        Vaccin::afisare(out);

        out << "conform OMS: " << this->conform_OMS << "\n";

        list<string>::iterator it = this->tulpini.begin();
        list<string>::iterator end = this->tulpini.end();

        if (this->tulpini.size())
        {
            out << "tulpini: \n";
            for (; it != end; it++)
            {
                out << *it << "\n";
            }
        }

        return out;
    }
};

class VaccinAntihepatic : public Vaccin
{
    string tip;
    string administrare;

public:
    VaccinAntihepatic() : Vaccin()
    {
        this->tip = "necunoscut";
        this->administrare = "necunoscut";
    }

    VaccinAntihepatic(float pret, float temperatura, list<string> substante, string producatori, string tip, string administrare) : Vaccin(pret, temperatura, substante, producatori)
    {
        this->tip = tip;
        this->administrare = administrare;
    }

    VaccinAntihepatic(const VaccinAntihepatic &v) : Vaccin(v)
    {
        this->tip = v.tip;
        this->administrare = v.administrare;
    }

    void afisareSchemaVaccinare()
    {
        cout << "Antihepatită A și B, la copii cu vârstă mai mică de 1 an se adminstrează 2 injectări la un interval de o lună, a treia injectare după 6 luni de la prima administrare\n";
    }

    istream &citire(istream &in)
    {
        Vaccin::citire(in);

        cout << "tip administrare: ";
        in >> this->administrare;

        cout << "tipul hepatitei: ";
        in >> this->tip;

        return in;
    }

    ostream &afisare(ostream &out)
    {
        Vaccin::afisare(out);

        out << "tip administrare: " << this->administrare << "\n";
        out << "tip hepatita: " << this->tip << "\n";

        return out;
    }
};

class VaccinAntiSarsCov2 : public Vaccin
{
    float rata_eficienta;
    string reactii_adverse;
    string medicamente_contraindicate;

public:
    VaccinAntiSarsCov2() : Vaccin()
    {
        this->rata_eficienta = 0;
        this->reactii_adverse = "";
        this->medicamente_contraindicate = "";
    }

    VaccinAntiSarsCov2(float pret, float temperatura, list<string> substante, string producatori,
                       float rata_eficienta, string reactii_adverse,
                       string medicamente_contraindicate) : Vaccin(pret, temperatura, substante, producatori)
    {
        this->rata_eficienta = rata_eficienta;
        this->reactii_adverse = reactii_adverse;
        this->medicamente_contraindicate = medicamente_contraindicate;
    }

    VaccinAntiSarsCov2(const VaccinAntiSarsCov2 &v) : Vaccin(v)
    {
        this->rata_eficienta = v.rata_eficienta;
        this->reactii_adverse = v.reactii_adverse;
        this->medicamente_contraindicate = v.medicamente_contraindicate;
    }

    VaccinAntiSarsCov2 &operator=(const VaccinAntiSarsCov2 &v)
    {
        if (this != &v)
        {
            this->rata_eficienta = v.rata_eficienta;
            this->reactii_adverse = v.reactii_adverse;
            this->medicamente_contraindicate = v.medicamente_contraindicate;
        }

        return *this;
    }

    void afisareSchemaVaccinare()
    {
        cout << "se administrează persoanelor cu vârstă de peste 16 ani, 2 doze la o perioadă de 21 zile\n";
    }

    istream &citire(istream &in)
    {
        Vaccin::citire(in);

        cout << "reactii adverse: ";
        in >> this->reactii_adverse;

        cout << "medicamente contraindicate: ";
        in >> this->medicamente_contraindicate;

        return in;
    }
    ostream &afisare(ostream &out)
    {
        Vaccin::afisare(out);

        out << "reactii adverse: " << this->reactii_adverse << "\n";

        out << "medicamente contraindicate: " << this->medicamente_contraindicate << "\n";

        return out;
    }
};

class Comanda
{
    string data;
    string cumparator;
    map<string, int> vaccinuri;

public:
    Comanda(){}

    Comanda(string data, string comparator, string vaccin, int doze)
    {
        this->data = data;
        this->cumparator = cumparator;

        this->vaccinuri[vaccin] = doze;
    }

    friend ostream &operator<<(ostream &out, Comanda &v)
    {
        out << "data: " << v.data << "\n";
        out << "comparator: " << v.cumparator << "\n";

        return out;
    }
};

class ListaComenzi
{
    vector<Comanda> comenzi;

public:
    ListaComenzi() {}

    Comanda operator[](int i)
    {
        return comenzi[i];
    }

    friend ListaComenzi operator+(ListaComenzi l, Comanda c)
    {
        ListaComenzi lista_noua = l;
        l.comenzi.push_back(c);

        return lista_noua;
    }
};

int main()
{
    VaccinAntigripal a;
    VaccinAntihepatic b;
    VaccinAntiSarsCov2 c;

    cin >> a >> b >> c;
    cout << a << b << c;

    Vaccin *list1[3];
    list1[0] = new VaccinAntigripal();
    list1[1] = new VaccinAntihepatic();
    list1[2] = new VaccinAntiSarsCov2();

    for (int i = 0; i < 3; i++)
        list1[i]->afisareSchemaVaccinare();

    Comanda com1("20-12-2020", "SpitalX", "AntiSarsCov2",20);
    ListaComenzi lista;

    lista = lista + com1;

    return 0;
}