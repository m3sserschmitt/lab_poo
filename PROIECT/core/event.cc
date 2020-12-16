#include "../data_structures/iterable/vector/vector.h"
#include "./include/note.h"

#include "./include/event.h"

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

    cout << "enter date (dd.mm.yyyy): ";
    in >> this->date;

    cout << "enter time (hh:mm or hh:mm:ss): ";
    in >> this->time;

    return in;
}

ostream &Event::show(ostream &out) const
{
    out << this->name << " on " << this->date << " " << this->time;

    return out;
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
