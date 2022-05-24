#include <iostream>
#include <cstdint>
#include <array>

template <typename T>
struct Apple
{
    T size;

    Apple() : size{0}
    {}

    Apple(T size) : size{size}
    {}

    bool operator>(const Apple& b) const
        { return this->size > b.size; }

    void print() const
        { std::cout << "Manzana: " << this->size << " cm\n"; }
};

//template <typename T>
//bool Apple<T>::operator>(const Apple& a) const
//{}

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
template <typename T, std::size_t N>
void print(std::array<T, N>& arr)
{
    for(int i{0} ; i<N ; ++i)
        arr[i].print();
}

int main()
{
    std::array< Apple<double>, 5 > b{};

    b[0] = Apple<double>{10.2};
    b[1] = Apple<double>{8.3};
    b[2] = Apple<double>{2.5};
    b[3] = Apple<double>{6.3};
    b[4] = Apple<double>{12.1};

    std::cout<< "> Array without sort\n";
    print(b);
    sort(b);
    std::cout<< "> Array with sort\n";
    print(b);

}
