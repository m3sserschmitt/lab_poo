#include "personana.h"


class Student : public Persoana
{
    string facultate;
    bool buget;
    int nr_note;
    int *note;

protected:
    void copiaza_note(int *note, int nr_note);

public:
    Student();
    Student(const Student &);
    Student(Persoana p, string facultate, bool buget, int *note, int nr_note);

    float media();

    bool operator<(Student);
    bool operator>(Student);
    bool operator<=(Student);
    bool operator>=(Student);
    bool operator==(Student);

    void operator=(Student);

    friend ostream &operator<<(ostream &out, Student &s);
};