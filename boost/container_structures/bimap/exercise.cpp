#include <boost/optional.hpp>
#include <string>
#include <vector>
#include <iostream>

#include <boost/bimap.hpp>

typedef boost::bimap<boost::bimaps::set_of<std::string>, boost::bimaps::set_of<int>> bimap_type; 

struct animal
{
    std::string name;
    int legs;

    animal(std::string n, int l) : name(n), legs(l) {}
};

class animals_container
{
public:
    void add(animal & a)
    {
        // hand over by reference
        // DONE
        m_animals.insert({a.name, a.legs}); 
    }

    void add(animal && a)
    {
        // NEW: overload for rvalue reference
        // DONE
        m_animals.insert({a.name, a.legs}); 
    }

    boost::optional<animal> find_by_name(const std::string &name) const
    {
        // DONE
        auto it = m_animals.left.find(name); 
        return std::move(animal{it->first, it->second});
    }

    std::vector<animal> find_by_legs(int from, int to) const
    {
        // DONE
        std::vector<animal> result; 
        
        auto start_it = m_animals.right.lower_bound(from); 
        auto end_it = m_animals.right.upper_bound(to);  
        
        for (;start_it != end_it; start_it++)
        {
            result.push_back(std::move(animal{start_it->second, start_it->first})); 
        }

        return std::move(result);
    }
private: 
    bimap_type m_animals; 

};

int main()
{
    animals_container animals;
    animals.add({ "cat", 4 });
    animals.add({ "ant", 6 });
    animals.add({ "spider", 8 });
    animals.add({ "shark", 0 });

    auto shark = animals.find_by_name("shark");
    if (shark)
        std::cout << "shark has " << shark->legs << " legs\n";

    auto animals_with_4_to_6_legs = animals.find_by_legs(4, 7);
    for (auto animal : animals_with_4_to_6_legs)
        std::cout << animal.name << " has " << animal.legs << " legs\n";
}