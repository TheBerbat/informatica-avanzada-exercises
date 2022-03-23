#include <iostream>
#include <vector>

template <typename T>
std::size_t printVector(std::vector<T> v)
{
    std::cout << "[ ";
    if (v.size() == 0)
        std::cout << "vector vacio";
    else
    {
        for (const T& it : v)
            std::cout << it << " ";
    }
    std::cout << "]\n";
    return v.size();
}

int main()
{
    std::vector<int> int_vec {3, 5, 7, 1};
    std::vector<double> double_vec {10.2, 4.4, 7.8, 4.1};

    printVector(int_vec);
    printVector(double_vec);

    return 0;
}