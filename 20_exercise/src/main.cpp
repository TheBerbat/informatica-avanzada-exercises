#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    auto print_vec = [](const auto& vec){
        for(const char& c : vec)
            std::cout << c << " ";
        std::cout << '\n';
    };
    auto is_vowel = [](unsigned char e){
        return e == 'a' || e == 'e' || e == 'i' || e == 'o' || e == 'u';
    };

    // Create vector
    //
    std::vector<char> vec;
    // Prints first state
    print_vec(vec);
    
    // Inserts elements
    //
    for (char ch{'a'} ; ch<='k' ; ++ch)
        vec.push_back(ch);
    // Prints state
    print_vec(vec);

    // Replace vowels
    //
    std::replace_if(vec.begin(), vec.end(), is_vowel, '*');
    // Prints state
    print_vec(vec);
    
    return 0;
}
