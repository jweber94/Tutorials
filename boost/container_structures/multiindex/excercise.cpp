#include <string>
#include <vector>
#include <iostream>

#include <boost/multi_index_container.hpp>
#include <boost/multi_index/member.hpp>
#include <boost/multi_index/hashed_index.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/range.hpp>

struct animal
{
    std::string name;
    int legs;
    bool has_tail;

    bool operator<(animal a)
    {   
        return this->legs < a.legs;   
    }
};

typedef boost::multi_index_container 
    <
        animal, 
        boost::multi_index::indexed_by
            <
                boost::multi_index::hashed_unique
                    <   boost::multi_index::member
                            <
                                animal, std::string, &animal::name
                            > 
                    >,
                boost::multi_index::ordered_non_unique
                    <
                        boost::multi_index::member
                            <
                                animal, int, &animal::legs
                            >
                    >, 
                boost::multi_index::hashed_non_unique
                    <
                        boost::multi_index::member
                            <
                                animal, bool, &animal::has_tail
                            >                        
                    > 
            >
    > animals_cont; 


class animals_container
{
public:
    void add(animal && a)
    {   
        // DONE: Implement this member function.
        m_animals.insert(std::move(a));
    }

    const animal *find_by_name(const std::string &name) const
    {
        // DONE: Implement this member function.
        return &(*(m_animals.find(name)));
    }

    std::vector<animal> find_by_legs(int from, int to) const
    {
        // DONE: Implement this member function.
        auto & legs_index = m_animals.get<1>(); 
        std::vector<animal> searched_animals; 

        auto it = legs_index.lower_bound(from);
        auto end = legs_index.upper_bound(to); 
        for (; it != end; it++)
        {
            searched_animals.push_back(*(it)); 
        }

        return std::move(searched_animals);
    }

    std::vector<animal> find_by_tail(bool has_tail) const
    {
        // DONE: Implement this member function.
        auto & tail_index = m_animals.get<2>();  
        auto values = tail_index.equal_range(has_tail);
        std::vector<animal> result{}; 
        for (auto & value : boost::make_iterator_range(values))
        {
            result.push_back(value); 
        }  
        return result;
    }

private: 
    animals_cont m_animals;     
};

int main()
{
    animals_container animals;
    animals.add({ "cat", 4, true });
    animals.add({ "ant", 6, false });
    animals.add({ "spider", 8, false });
    animals.add({ "shark", 0, false });

    const animal *a = animals.find_by_name("cat");
    if (a)
        std::cout << "cat has " << a->legs << " legs\n";

    auto animals_with_6_to_8_legs = animals.find_by_legs(6, 9);
    for (auto a : animals_with_6_to_8_legs)
        std::cout << a.name << " has " << a.legs << " legs\n";

    auto animals_without_tail = animals.find_by_tail(false);
    for (auto a : animals_without_tail)
        std::cout << a.name << " has no tail\n";
}