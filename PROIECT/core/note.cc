#include "./exceptions/include/exception.h"
#include "./include/note.h"

#include <fstream>
#include <map>

using namespace std;

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

ifstream &Note::read2(ifstream &in)
{
    map<string, string> m = {{"Name", ""}, {"Date", ""}, {"Description", ""}};

    this->read_map(in, m);

    this->name = m["Name"];
    this->date.set_date(m["Date"]);
    this->description = m["Description"];

    return in;
}

string Note::to_string() const
{
    string str = this->name + " for " + this->date.to_string();

    if (this->description.size())
    {
        str += "\n---> " + this->description;
    }

    return str;
}

string Note::to_string2() const
{
    string str = "[Note]";
    str += "\nName: " + this->name;
    str += "\nDate: " + this->date.to_string();

    if (this->description.size())
    {
        str += "\nDescription: " + this->description;
    }

    return str;
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
