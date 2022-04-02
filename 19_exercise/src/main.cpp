#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>

template <typename T>
bool palindrome(const std::vector<T>& s)
{
    std::cout << "xD1\n";
    return std::equal(s.begin(), s.begin() + s.size()/2, s.rbegin());
}

template <>
bool palindrome(const std::vector<char>& s)
{
    std::cout << "xD2\n";
    auto eq_uppercase = [](const int& a, const int& b){
        return std::toupper(a) == std::toupper(b);
    };
    return std::equal(s.begin(), s.begin() + s.size()/2, s.rbegin(), eq_uppercase);
}

int main()
{
    std::vector<int>    mi_vec1 { 1, 2, 3, 2, 1 };
    std::vector<char>   mi_vec2 { 'A', 'a', 'a', 'A', 'h' };

    std::cout << palindrome(mi_vec1) << '\n';
    std::cout << palindrome(mi_vec2) << '\n';
    
    return 0;
}
