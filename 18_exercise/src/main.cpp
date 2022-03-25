#include <iostream>
#include <vector>
#include <map>
#include <utility>

struct Dictionary
{
    using meanings_t = std::vector<std::string>;
    using words_t = std::map<std::string, meanings_t>;

    words_t data;

    explicit Dictionary()
      : data{}
    {}

    void insert(std::string word, std::string meaning)
    {
        words_t::iterator w = data.find(word);
        if (w == data.end())
            data.insert( std::make_pair( word, std::vector{meaning} ) );
        else
            w->second.push_back(meaning);
    }

    void insert(std::string word, std::initializer_list<std::string> meanings)
    {
        words_t::iterator w = data.find(word);
        if (w == data.end())
            data.insert( std::make_pair( word, std::vector(meanings) ) );
        else
            w->second.insert(w->second.end(), meanings);
    }

    const meanings_t& search(std::string word) const 
    {
        return data.at(word);
    }

    std::size_t print_meanings(std::string word) const
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
};



int main()
{
    Dictionary d{};

    d.insert("hola", { "como salutación familiar",
                       "para denotar extrañeza, placentera o desagradable.",
                       "para llamar a los inferiores." });

    d.insert("adios", "despide");
    d.insert("adios", "palabra bonita");

    d.print_meanings("hola");
    d.print_meanings("por");
    d.print_meanings("adios");

    return 0;
}