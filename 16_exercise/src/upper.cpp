#include <upper.hpp>

void to_upper_case_letter(std::string& s, char l)
{
    for(std::size_t i {0} ; i<s.size() ; ++i)
    {
        if (s[i] == l)
            s[i] = std::toupper(s[i]);
    }
}