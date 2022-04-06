#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <vector>
#include <map>
#include <string>

struct Dictionary
{
    using meanings_t = std::vector<std::string>;
    using words_t = std::map<std::string, meanings_t>;

    words_t data;

    explicit Dictionary();

    void insert(std::string word, std::string meaning);
    void insert(std::string word, std::initializer_list<std::string> meanings);
    const meanings_t& search(std::string word) const;
    meanings_t& search(std::string word);
    std::size_t print_meanings(std::string word) const;
};


#endif // DICTIONARY_H
