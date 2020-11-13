#include "student.h"

Student::Student()
{
    this->note = NULL;
}

Student::Student(const Student &s) : Persoana(s)
{
    this->facultate = s.facultate;
    this->buget = s.buget;
    this->nr_note = s.nr_note;
    this->note = NULL;

    this->copiaza_note(s.note, s.nr_note);
}

Student::Student(Persoana p, string facultate, bool buget, int *note, int nr_note) : Persoana(p)
{
    this->facultate = facultate;
    this->buget = buget;
    this->nr_note = nr_note;
    this->note = NULL;

    this->copiaza_note(note, nr_note);
}

void Student::copiaza_note(int *note, int nr_note)
{
    if (this->note)
    {
        delete[] this->note;
        this->note = NULL;
    }

    this->note = new int[nr_note];

    for (int i = 0; i < nr_note; i++)
    {
        this->note[i] = note[i];
    }
}

float Student::media()
{
    float total = 0;
    for (int i = 0; i < this->nr_note; i++)
    {
        total += this->note[i];
    }

    return total / this->nr_note;
}

bool Student::operator<(Student s)
{
    return this->media() < s.media();
}

bool Student::operator>(Student s)
{
    return this->media() > s.media();
}

bool Student::operator<=(Student s)
{
    return not((*this) > s);
}

bool Student::operator>=(Student s)
{
    return not((*this) < s);
}

bool Student::operator==(Student s)
{
    return ((*this) <= s) and ((*this) >= s);
}

void Student::operator=(Student s)
{
    if (this != &s)
    {
        Persoana::operator=(s);

        this->facultate = s.facultate;
        this->buget = s.buget;
        this->nr_note = s.nr_note;

        this->copiaza_note(s.note, s.nr_note);
    }
}

ostream &operator<<(ostream &out, Student &s)
{
    out << (Persoana &)s << "\n";
    out << "facultatea: " << s.facultate << "\n";
    out << "buget: " << s.buget << "\n";
    out << "media: " << s.media();

    return out;
}