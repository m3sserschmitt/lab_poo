#include "./exceptions/include/exception.h"
#include "./include/note.h"

Note::Note() : Entry() {}

Note::Note(std::string name) : Entry(name) {}

Note::Note(std::string name, std::string description) : Entry(name)
{
    this->description = description;
}

Note::Note(const Note &note) : Entry(note)
{
    this->description = note.description;
}

int Note::compare(const Entry &e) const
{
    Note *note = dynamic_cast<Note *>(&(Entry &)e);
    Event *event = dynamic_cast<Event *>(&(Entry &)e);

    Date d;

    if (note)
    {
        d = note->date;
    }
    else if (event)
    {
        d = event->get_date();

        if (this->date == d)
        {
            return -1;
        }
    }
    else
    {
        d = e.get_date();
    }

    return this->date > d ? 1 : -1 * (d > this->date);
}

istream &Note::read(istream &in)
{
    cout << "enter name: ";
    getline(in, this->name);

    while (true)
    {
        cout << "enter date (dd.mm.yyyy): ";
        try
        {
            in >> this->date;
        }
        catch (const Exception &e)
        {
            std::cerr << e.what() << '\n';
            continue;
        }
        break;
    }

    cout << "description: ";
    getline(in, this->description);

    return in;
}

ostream &Note::show(ostream &out) const
{
    out << this->name << " for " << this->date;
    if (this->description.size())
    {
        out << "\n---> " << this->description;
    }

    return out;
}

void Note::set_description(string description)
{
    this->description = description;
}

string Note::get_description() const
{
    return this->description;
}

Note &Note::operator=(const Note &note)
{
    if (this != &note)
    {
        this->name = note.name;
        this->description = note.description;
        this->date = note.date;
    }

    return *this;
}
