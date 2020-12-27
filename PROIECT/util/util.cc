#include "./include/util.h"

#include <math.h>

std::vector<std::string> split(std::string str, std::string sep, int max_split)
{
    if (!str.size())
        return {};

    std::vector<std::string> tokens;

    size_t sep_pos;
    int split_index = 0;

    // tokens.reserve(10);

    do
    {
        split_index++;
        sep_pos = str.find(sep);

        // tokens.resize(tokens.size() + 1);
        tokens.push_back(str.substr(0, sep_pos));
        if (sep_pos == std::string::npos)
        {
            // tokens.resize(split_index);
            return tokens;
        }

        str = str.substr(sep_pos + sep.size());
        if (split_index == max_split && str.size())
        {

            // tokens.resize(tokens.size() + 1);
            tokens.push_back(str);
            // tokens.resize(split_index + 1);
            return tokens;
        }
    } while (true);

    return tokens;
}

void strip(std::string &str, std::string chars)
{
    size_t start = str.find_first_not_of(chars);
    size_t end = str.find_last_not_of(chars);

    str = str.substr(start, end - start + 1);
}

bool is_number(std::string str, int &n)
{
    if (!str.size())
        return false;

    n = 0;
    int s = str.size() - 1;

    for (int i = 0; i <= s ; i ++)
    {
        int c = (int)str[i];

        if (c < 48 || c > 57)
        {
            n = 0;
            return false;
        }

        n += (c - 48) * pow(10, s - i);
    }

    return true;
}