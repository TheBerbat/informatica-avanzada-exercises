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
    auto replace_vowels = [](auto& vec){
        std::for_each(vec.begin(), vec.end(), [](char& ch){
            auto is_vowel = [](unsigned char e){
                return e == 'a' || e == 'e' || e == 'i' || e == 'o' || e == 'u';
            };
            if (is_vowel(ch))
                ch = '*';
        });
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
    replace_vowels(vec);
    // Prints state
    print_vec(vec);
    
    return 0;
}
