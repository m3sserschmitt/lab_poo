#include "./include/util.h"

std::vector<std::string> split(std::string str, std::string sep, int max_split)
{
    std::vector<std::string> tokens;

    size_t sep_pos;
    int split_index = 0;

    if (!str.size())
        return tokens;

    tokens.reserve(10);

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

bool is_number(std::string str)
{
    if (!str.size())
        return false;

    for (unsigned int i = 0; i < str.size(); i++)
    {
        int c = (int)str[i];

        if (c < 48 || c > 57)
            return false;
    }

    return true;
}