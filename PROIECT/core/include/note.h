#include "event.h"

#include <fstream>

#ifndef NOTE_H
#define NOTE_H

class Note : public Entry
{
    std::string description;

    std::istream &read(std::istream &in);
    std::ifstream &read2(std::ifstream &in);

public:
    Note();
    Note(std::string name);
    Note(std::string name, std::string description);
    Note(const Note &e);

    int compare(const Entry &e) const;

    void set_description(std::string description);
    std::string get_description() const;

    std::string to_string() const;
    std::string to_string2() const;

    Note &operator=(const Note &);
};

#endif