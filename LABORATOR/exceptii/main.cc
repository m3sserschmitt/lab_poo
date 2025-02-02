#include <iostream>
#include <string.h>
#include <vector>
#include <list>
#include <fstream>
#include <exception>
#include <stdexcept>

using namespace std;
using std::runtime_error;

class Masina
{
private:
    char *marca;
    string nrinmatriculare;
    float consum;
    int nrPlinuri;
    float *cantitatePlin;
    int kilometraj;
    double pretCombustibil;
    bool inmatriculat;
    float listaPretCombustibil[100];
    const int id;
    static int contorId;
    static int numarViteze;

public:
    //constructor fara parametri
    Masina() : id(contorId++)
    {
        this->marca = NULL;
        this->nrinmatriculare = "NA";
        this->consum = 0;
        this->cantitatePlin = NULL;
        this->kilometraj = 0;
        this->pretCombustibil = 0;
        this->inmatriculat = true;
        for (int i = 0; i < 100; i++)
            this->listaPretCombustibil[i] = 0;
    }

    //constructor cu toti parametri
    Masina(char *marca, string nrinmatriculare, float consum, int nrPlinuri, float *cantitatePlin, int kilometraj, double pretCombustibil, bool inmatriculat, float listaPretCombustibil[100]) : id(contorId++)
    {
        if(not marca)
        {
            throw std::runtime_error("Nu s-a introdus marca.");
        }

        if(not nrinmatriculare.size())
        {
            throw std::runtime_error("Nu s-a introdus numarul de inmatriculare.");
        }

        if(consum < 0)
        {
            throw std::runtime_error("S-a introdus un consum negativ.");
        }

        if(nrPlinuri < 0)
        {
            throw std::runtime_error("S-a introdus un numar negativ de plinuri.");
        }

        if(not cantitatePlin)
        {
            throw std::runtime_error("Nu s-a introdus cantitate plin.");
        }

        if(kilometraj < 0)
        {
            throw std::runtime_error("S-a introdus un kilometraj negativ.");
        }

        if(pretCombustibil < 0)
        {
            throw std::runtime_error("Pretul combustibilului este negativ");
        }

        //ar tb si aici stergere
        this->marca = new char[strlen(marca) + 1];
        strcpy(this->marca, marca);
        this->nrinmatriculare = nrinmatriculare;
        this->consum = consum;
        this->nrPlinuri = nrPlinuri;
        this->cantitatePlin = new float[this->nrPlinuri];
        for (int i = 0; i < this->nrPlinuri; i++)
            this->cantitatePlin[i] = cantitatePlin[i];
        this->kilometraj = kilometraj;
        this->pretCombustibil = pretCombustibil;
        this->inmatriculat = inmatriculat;
        for (int i = 0; i < this->nrPlinuri; i++)
            this->listaPretCombustibil[i] = listaPretCombustibil[i];
    }
    //constructor cu 2 parametri
    Masina(float consum, int nrPlinuri) : id(contorId++)
    {
        this->consum = consum;
        this->nrPlinuri = nrPlinuri;
    }

    //constructor de copiere
    Masina(const Masina &c) : id(contorId++)
    {
        if (c.marca != NULL)
        {
            this->marca = new char[strlen(c.marca) + 1];
            strcpy(this->marca, c.marca);
        }

        this->nrinmatriculare = c.nrinmatriculare;
        this->consum = c.consum;
        this->nrPlinuri = c.nrPlinuri;

        this->cantitatePlin = new float[nrPlinuri];
        for (int i = 0; i < this->nrPlinuri; i++)
            this->cantitatePlin[i] = c.cantitatePlin[i];
        this->kilometraj = c.kilometraj;
        this->pretCombustibil = c.pretCombustibil;
        this->inmatriculat = c.inmatriculat;
        for (int i = 0; i < this->nrPlinuri; i++)
            this->listaPretCombustibil[i] = c.listaPretCombustibil[i];

        cout << "S a apelat copy constructor";
    }

    //operator egal =
    Masina &operator=(const Masina &c)
    {
        if (this != &c)
        {
            if (this->marca != NULL)
                delete[] this->marca;
            this->marca = new char[strlen(c.marca) + 1];
            strcpy(this->marca, c.marca);

            this->nrinmatriculare = c.nrinmatriculare;
            this->consum = c.consum;
            this->nrPlinuri = c.nrPlinuri;
            if (this->cantitatePlin != NULL)
                delete[] this->cantitatePlin;
            this->cantitatePlin = new float[nrPlinuri];
            for (int i = 0; i < this->nrPlinuri; i++)
                this->cantitatePlin[i] = c.cantitatePlin[i];
            this->kilometraj = c.kilometraj;
            this->pretCombustibil = c.pretCombustibil;
            this->inmatriculat = c.inmatriculat;
            for (int i = 0; i < this->nrPlinuri; i++)
                this->listaPretCombustibil[i] = c.listaPretCombustibil[i];
        }
        return *this;
    }

    //operator <<(operator de afisare)

    friend ostream &operator<<(ostream &out, const Masina &c)
    {
        out << "Marca este " << c.marca << endl;
        out << "Nr inmatriculare" << c.nrinmatriculare << endl;
        out << "plinurile sunt: ";
        for (int i = 0; i < c.nrPlinuri; i++)
            out << c.cantitatePlin[i] << " ";
        out << endl;
        out << "Consumul este: " << c.consum << endl;
        out << "Numarul de plinuri este: " << c.nrPlinuri << endl;
        out << "Kilometrajul este: " << c.kilometraj << endl;
        out << "Pretul combustibilului este: " << c.pretCombustibil << endl;
        out << "Este inmatriculat: " << c.inmatriculat << endl;
        out << "Lista Pret Combustibil: ";
        for (int i = 0; i < c.nrPlinuri; i++)
            out << c.listaPretCombustibil[i] << " ";
        out << endl;

        return out;
    }
    //operator >>(operator de citire)
    friend istream &operator>>(istream &in, Masina &c)
    {
        cout << "introduceri marca masinii ";
        char buffer[100];
        in.getline(buffer, 100);
        if (c.marca != NULL)
            delete[] c.marca;
        c.marca = new char[strlen(buffer) + 1];
        strcpy(c.marca, buffer);
        in >> c.marca;

        cout << "introduceti numar de pliniuri ";
        in >> c.nrPlinuri;

        cout << "Introduceti numarul de inmatriculare ";
        in >> c.nrinmatriculare;

        cout << "Introduceti consumul ";
        in >> c.consum;

        cout << "Introduceti kilometrajul masinii ";
        in >> c.kilometraj;

        cout << "Pretul combustibilului este ";
        in >> c.pretCombustibil;

        cout << "Introduceti daca este inmatriculat";
        in >> c.inmatriculat;

        cout << "Cantitate de combustibil a plinurilor este ";
        if (c.cantitatePlin != NULL)
            delete[] c.cantitatePlin;
        c.cantitatePlin = new float[c.nrPlinuri];
        for (int i = 0; i < c.nrPlinuri; i++)
            in >> c.cantitatePlin[i];

        cout << endl
             << "lista pret combustibil ";
        for (int i = 0; i < c.nrPlinuri; i++)
            in >> c.listaPretCombustibil[i];
        return in;
    }
    //Citire din fisier
    friend ifstream &operator>>(ifstream &fIn, Masina &c)
    {

        char buffer[100];
        fIn.getline(buffer, 100);
        if (c.marca != NULL)
            delete[] c.marca;
        c.marca = new char[strlen(buffer) + 1];
        strcpy(c.marca, buffer);
        fIn >> c.nrPlinuri;
        fIn >> c.nrinmatriculare;
        fIn >> c.consum;
        fIn >> c.kilometraj;
        fIn >> c.inmatriculat;
        if (c.cantitatePlin != NULL)
            delete[] c.cantitatePlin;
        c.cantitatePlin = new float[c.nrPlinuri];
        for (int i = 0; i < c.nrPlinuri; i++)
            fIn >> c.cantitatePlin[i];
        for (int i = 0; i < c.nrPlinuri; i++)
            fIn >> c.listaPretCombustibil[i];
        return fIn;
    }

    friend ofstream &operator<<(ofstream &fout, const Masina &c)
    {
        fout << "Marca este " << c.marca << endl;
        fout << "Nr inmatriculare" << c.nrinmatriculare << endl;
        fout << "plinurile sunt: ";
        for (int i = 0; i < c.nrPlinuri; i++)
            fout << c.cantitatePlin[i] << " ";
        fout << endl;
        fout << "Consumul este: " << c.consum << endl;
        fout << "Numarul de plinuri este: " << c.nrPlinuri << endl;
        fout << "Kilometrajul este: " << c.kilometraj << endl;
        fout << "Pretul combustibilului este: " << c.pretCombustibil << endl;
        fout << "Este inmatriculat: " << c.inmatriculat << endl;
        fout << "Lista Pret Combustibil: ";
        for (int i = 0; i < c.nrPlinuri; i++)
            fout << c.listaPretCombustibil[i] << " ";
        fout << endl;

        return fout;
    }
};

int Masina::numarViteze = 6;
int Masina::contorId = 1000;

int main()
{

    ifstream f("dateIn.txt");
    ofstream g("dateOut.txt");

    Masina m;
    f >> m;
    cout << m;
    g << m;

    return 0;
}
