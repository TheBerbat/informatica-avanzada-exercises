#include "dictionary.h"
#include <iostream>

Dictionary::Dictionary()
  : data{}
{}

void Dictionary::insert(std::string word, std::string meaning)
{
    words_t::iterator w = data.find(word);
    if (w == data.end())
        data.insert( std::make_pair( word, std::vector{meaning} ) );
    else
        w->second.push_back(meaning);
}

void Dictionary::insert(std::string word, std::initializer_list<std::string> meanings)
{
    words_t::iterator w = data.find(word);
    if (w == data.end())
        data.insert( std::make_pair( word, std::vector(meanings) ) );
    else
        w->second.insert(w->second.end(), meanings);
}

const Dictionary::meanings_t& Dictionary::search(std::string word) const
{
    return data.at(word);
}
Dictionary::meanings_t& Dictionary::search(std::string word)
{
    return data.at(word);
}

std::size_t Dictionary::print_meanings(std::string word) const
{
    std::size_t i {0};
    std::cout << " > " << word << ":\n";
    try
    {
        const Dictionary::meanings_t m { search(word) };

        for(Dictionary::meanings_t::const_iterator it {m.begin()} ; it!=m.end() ; ++it)
            std::cout << "   " << ++i << ". " << *it << '\n';
    }
    catch (const std::out_of_range& e)
    {
        std::cout << "   No esta indexada\n";
    }
    return i;
}
