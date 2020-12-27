#include "notebook.h"
#include "note.h"

#include <vector>
#include <string>

void add(vector<std::string> arguments, Notebook &notebook);

void list_entries(vector<std::string> arguments, Notebook &notebook);

void export_entries(vector<std::string> arguments, Notebook &notebook);

void import_entries(vector<std::string> arguments, Notebook &notebook);

void remove(vector<std::string> arguments, Notebook &notebook);