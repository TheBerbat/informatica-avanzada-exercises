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
        for (typename std::vector<T>::iterator it { v.begin() } ; it != v.end() ; ++it)
            std::cout << *it << " ";
    }
    std::cout << "]\n";
    return v.size();
}

template <typename T>
void invert(typename std::vector<T>::iterator begin, typename std::vector<T>::iterator end)
{
    typename std::vector<T>::iterator n_end {end-1};
    if (begin >= n_end)
        return;

    T aux = *n_end;
    *n_end = *begin;
    *begin = aux;

    invert<T>(begin+1, n_end);
}

int main()
{
    std::vector<int> vec;
    std::vector<int> removed_elems;

    // Insert to vector [1..10]
    for(int n {1} ; n<=15 ; ++n)
        vec.push_back(n);

    // Removes odds numbers
    for(std::vector<int>::iterator it {vec.begin()} ; it != vec.end() ; ++it)
    {
        if ((*it % 2) == 0)
        {
            removed_elems.push_back(*it);
            it = vec.erase(it);
        }
    }

    // Invert the vector
    invert<int>(vec.begin(), vec.end());

    for(std::vector<int>::iterator it {vec.begin()} ; it != vec.end() ; ++it)
    {
        if (*it < removed_elems.back())
        {
            it = vec.insert(it, removed_elems.back());
            removed_elems.pop_back();
        }
    }

    // Print the vector final
    printVector(vec);

    return 0;
}