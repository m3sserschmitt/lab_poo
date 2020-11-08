#include "../../data_structures/include/vector/vector.h"

#include "../include/event.h"

Event::Event(){

}

Event::Event(std::string name){
    this->name = name;
}

Event::Event(const Event &event){
    this->name = event.name;
    this->date = event.date;
    this->time = event.time;
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

bool Event::operator<(Event other)
{
    Vector<bool> u = {this->date < other.get_date(), this->time < other.get_time()};
    Vector<bool> v = {this->date > other.get_date(), this->time > other.get_time()};

    return u > v;
}

bool Event::operator>(Event other)
{
    Vector<bool> u = {this->date > other.get_date(), this->time > other.get_time()};
    Vector<bool> v = {this->date < other.get_date(), this->time < other.get_time()};

    return u > v;
}

bool Event::operator<=(Event other)
{
    return not((*this) > other);
}

bool Event::operator>=(Event other)
{
    return not((*this) < other);
}

bool Event::operator==(Event other)
{
    return this->name == other.get_name() and this->date == other.get_date() and this->date == other.get_date(); 
}

ostream &operator<<(ostream &out, Event event)
{
    out << event.get_name() << " on " << event.get_date() << " " << event.get_time();
    return out;
}

istream &operator>>(istream &in, Event &event)
{
    cout << "enter name: ";
    string name;
    getline(in, name);

    cout << "enter date (dd.mm.yyyy): ";
    Date date;
    in >> date;

    cout << "enter time (hh:mm or hh:mm:ss): ";
    Time time;
    in >> time;

    event.set_name(name);
    event.set_date(date);
    event.set_time(time);

    return in;
}