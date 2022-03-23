#include <upper.hpp>
#include <iostream>

int main()
{
    std::string cad;
    char letra;
    std::cout << "Enter the string: ";
    std::cin >> cad;
    std::cout << "Enter the letter to modify: ";
    std::cin >> letra;

    to_upper_case_letter(cad, letra);

    std::cout << "The result screen of uppercasing \"" << letra << "\" is: " << cad << std::endl;

    return 0;
}