#include "event.h"

#ifndef NOTE_H
#define NOTE_H

class Note: public Event
{
protected:
    string description;

    istream &read(istream &in);
    ostream &show(ostream &out);
public:
    Note();
    Note(std::string name);
    Note(const Note &e);

    void set_description(string description);
    string get_description();

    // friend ostream &operator<<(ostream &, Note *);
    // friend istream &operator>>(istream &, Note *);
};

#endif