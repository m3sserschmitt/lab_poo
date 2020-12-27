#include "../data_structures/iterable/vector/vector.h"
#include "./exceptions/include/exception.h"
#include "./include/note.h"

#include "./include/event.h"
#include "../util/include/util.h"

#include <map>

using namespace std;

Event::Event()
{
}

Event::Event(std::string name)
{
    this->name = name;
}

Event::Event(const Event &event)
{
    this->name = event.name;
    this->date = event.date;
    this->time = event.time;
}

istream &Event::read(istream &in)
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

    while (true)
    {
        try
        {
            cout << "enter time (hh:mm or hh:mm:ss): ";
            in >> this->time;
        }
        catch (const Exception &e)
        {
            std::cerr << e.what() << '\n';
            continue;
        }
        break;
    }

    return in;
}

ifstream &Event::read2(ifstream &in)
{
    map<string, string> m = {{"Name", ""}, {"Date", ""}, {"Time", ""}};
    
    this->read_map(in, m);
    
    this->name = m["Name"];
    this->date.set_date(m["Date"]);
    this->time.set_time(m["Time"]);

    return in;
}

string Event::to_string() const
{
    return this->name + " on " + this->date.to_string() + " " + this->time.to_string();
}

string Event::to_string2() const
{
    string str = "[Event]";
    str += "\nName: " + this->name;
    str += "\nDate: " + this->date.to_string();
    str += "\nTime: " + this->time.to_string();

    return str;
}

int Event::compare(const Entry &e) const
{
    Event *event = dynamic_cast<Event *>(&(Entry &)e);
    Note *note = dynamic_cast<Note *>(&(Entry &)e);

    Vector<bool> u;
    Vector<bool> v;

    if (event)
    {
        u = {event->date > this->date, event->time > this->time};
        v = {this->date > event->date, this->time > event->time};
    }
    else if (note)
    {
        u = {note->get_date() > this->date, 0};
        v = {note->get_date() < this->date, 1};
    }
    else
    {
        u = {e.get_date() > this->date};
        v = {e.get_date() < this->date};
    }

    return u < v ? 1 : -1 * (v < u);
}

void Event::set_time(Time time)
{
    this->time = time;
}

void Event::set_time(int hours, int minutes, int seconds)
{
    this->set_time(Time(hours, minutes, seconds));
}

Time Event::get_time() const
{
    return this->time;
}

Event &Event::operator=(const Event &event)
{
    if (this != &event)
    {
        this->name = event.name;
        this->date = event.date;
        this->time = event.time;
    }

    return *this;
}
