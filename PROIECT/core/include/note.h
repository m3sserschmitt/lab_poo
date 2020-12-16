#include "event.h"

#ifndef NOTE_H
#define NOTE_H

class Note: public Entry
{
protected:
    string description;

    istream &read(istream &in);
    ostream &show(ostream &out) const;

public:
    Note();
    Note(std::string name);
    Note(std::string name, std::string description);
    Note(const Note &e);

    int compare(const Entry &e) const;

    void set_description(string description);
    string get_description() const;

    Note &operator=(const Note &);
};

#endif