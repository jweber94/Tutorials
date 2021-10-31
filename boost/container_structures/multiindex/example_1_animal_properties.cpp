#include <iostream>
#include <string>

#include <boost/multi_index_container.hpp>
#include <boost/multi_index/hashed_index.hpp>
#include <boost/multi_index/member.hpp>

struct animal
{
    std::string name{}; 
    int legs{0}; 
};


typedef boost::multi_index::multi_index_container
    <animal, 
    boost::multi_index::indexed_by // definition of the interfaces of the multi_index
        <
            boost::multi_index::hashed_non_unique // first interface - in this case, this is the interface of a std::unorder_map
                <
                boost::multi_index::member // needed to define which membervariable should be used as the key of the "simulated" hashmap (multi_index interface of the std::unorder_map)
                    <
                    animal, std::string, &animal::name // the member needs three template arguments: class, datastructure, membervariable as reference
                    >
                >,
                boost::multi_index::hashed_non_unique // second interdace - this is also a std::unorder_map
                    <
                        boost::multi_index::member
                        <
                            animal, int, &animal::legs
                        >
                    >
        > 
    > animal_multi; 

int main()
{
    std::cout << "Started animal lookup program\n"; 
    animal_multi animals; 

    animals.insert({"cat", 4}); // implicitly calls the constructor of the animal struct with the curly brackets
    animals.insert({"cat", 3});
    animals.insert({"snake", 0});
    animals.insert({"spider", 8});   

    std::cout << "Number of animals: " << animals.count("cat") << "\n"; // count returns the number of elements in the unordered_map, that have the given key (we could have inserted multiple "cat" instances)

    const animal_multi::nth_index<1>::type &legs_index = animals.get<1>();  // By default, the multi_index_container will use the first defined index (aka interface), 
                                                                            //which is in this case the name. If you want to access another index, you need to get an 
                                                                            // iterator element from the multi_index_container and then call the individual access functionallity. The indices are encountered by the number of the template arguments for the indice (aka interface) in the typedef and starts with index 0 for the default indice (aka interface)
    std::cout << "The number of animals with the 8 legs is: " << legs_index.count(8) << "\n"; 
    std::cout << "The 8 legged animals name is: " << legs_index.find(8)->name << "\n"; 
    auto test = animals.find("spider"); 
    std::cout << "The spider has " << test->legs << " legs\n"; 
    return 0; 
}

/*
* Compile Command: 
*   $ g++ example_1_animal_properties.cpp
*/