#include <iostream>
#include <vector>

int main()
{
    std::vector<char> vec;

    for(char l{'a'} ; l<='k' ; ++l)
        vec.push_back(l);

    for(std::vector<char>::iterator it {vec.begin()} ; it!=vec.end() ; ++it)
    {
        switch (std::tolower(*it))
        {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            *it = '*';
            break;
        }
    }

    std::cout << "The vector results in: { ";
    for(std::vector<char>::iterator it {vec.begin()} ; it!=vec.end() ; ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << "}\n";

    return 0;
}