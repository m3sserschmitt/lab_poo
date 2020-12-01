#include "../data_structures/iterable/vector/vector.h"

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

ostream &Event::show(ostream &out)
{
    out << this->name << " on " << this->date << " " << this->time;

    return out;
}

int Event::compare(Event *e)
{
    Vector<bool> u = {this->date < e->date, this->time < e->time};
    Vector<bool> v = {this->date > e->date, this->time > e->time};

    return u < v ? 1 : -1 * (v < u);
}

void Event::set_date(Date date)
{
    this->date = date;
}

void Event::set_date(int day, int month, int year)
{
    this->set_date(Date(day, month, year));
}

void Event::set_time(Time time)
{
    this->time = time;
}

void Event::set_time(int hours, int minutes, int seconds)
{
    this->set_time(Time(hours, minutes, seconds));
}

void Event::set_name(std::string name)
{
    this->name = name;
}

std::string Event::get_name()
{
    return this->name;
}

Date Event::get_date()
{
    return this->date;
}

Time Event::get_time()
{
    return this->time;
}

bool Event::operator<(Event &e)
{
    return this->compare(&e) < 0;
}

bool Event::operator>(Event &e)
{
    return this->compare(&e) > 0;
}

bool Event::operator<=(Event &e)
{
    return not((*this) > e);
}

bool Event::operator>=(Event &e)
{
    return not((*this) < e);
}

bool Event::operator==(Event &e)
{
    return this->name == e.name and not this->compare(&e);
}

ostream &operator<<(ostream &out, Event &event)
{
    return event.show(out);
}

istream &operator>>(istream &in, Event &event)
{
    return event.read(in);
}