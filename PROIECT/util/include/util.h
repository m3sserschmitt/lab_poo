#include <vector>
#include <string>

std::vector<std::string> split(std::string str, std::string sep, int max_split);

void strip(std::string &str, std::string chars);

bool is_number(std::string str, int &n);