#include <iostream>
#include <array>

template <typename T, std::size_t N>
void sort(std::array<T, N>& arr)
{
    T aux;
    for (std::size_t i{0} ; i<(N-1) ; ++i)
    {
        for (std::size_t j{i+1} ; j<N ; ++j)
        {
            if (arr[i]>arr[j])
            {
                aux = arr[i];
                arr[i] = arr[j];
                arr[j] = aux;
            }
        }
    }
}

int main()
{
    std::array<int, 5> my_ints {10, 9, 3, 21, 2};
    std::array<float, 5> my_floats {9.53f, 2.32f, 1.02f, 12.4f, 0.01f};
    
    // PRINT VALUES
    //
    std::cout << "Without sort:\n";
    std::cout << "  > Ints: ";
    for (auto i : my_ints)
        std::cout << i << ", ";
    std::cout << '\n';

    std::cout << "  > Floats: ";
    for (auto i : my_floats)
        std::cout << i << ", ";
    std::cout << '\n';

    // SORT
    //
    sort(my_ints);
    sort(my_floats);

    // PRINT VALUES
    //
    std::cout << "\nWith sort:\n";
    std::cout << "  > Ints: ";
    for (auto i : my_ints)
        std::cout << i << ", ";
    std::cout << '\n';

    std::cout << "  > Floats: ";
    for (auto i : my_floats)
        std::cout << i << ", ";
    std::cout << '\n';

    return 0;
}
