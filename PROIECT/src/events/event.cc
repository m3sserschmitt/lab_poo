#include "data_structures/vector/vector.h"

#include "events/event.h"

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

void Event::set_time(Time time)
{
    this->time = time;
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
}

ostream &operator<<(ostream &out, Event event)
{
    out << event.get_date() << " " << event.get_time();
    return out;
}