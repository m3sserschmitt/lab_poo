#include "./include/note.h"

Note::Note() : Event() {}

Note::Note(std::string name) : Event(name) {}

Note::Note(const Note &note) : Event(note) {}

istream &Note::read(istream &in)
{
    cout << "enter name: ";
    getline(in, this->name);

    cout << "enter date (dd.mm.yyyy): ";
    in >> this->date;

    cout << "description: ";
    getline(in, this->description);

    return in;
}

ostream &Note::show(ostream &out)
{
    out << this->name << " on " << this->date;
    out << "\ndescription: " << this->description;

    return out;
}

void Note::set_description(string description)
{
    this->description = description;
}

string Note::get_description()
{
    return this->description;
}