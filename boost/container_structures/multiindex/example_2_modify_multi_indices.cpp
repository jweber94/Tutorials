#include <iostream>
#include <string>

#include <boost/multi_index/hashed_index.hpp>
#include <boost/multi_index/member.hpp>
#include <boost/multi_index_container.hpp>

struct animal
{
    std::string name{}; 
    int legs{0}; 
}; 

typedef boost::multi_index_container // create a mutli_index container definition (from a template based implementation to an actual container) 
    < 
        animal, // argument 1 of multi_index_container: the datastructure that should be stored in them
        boost::multi_index::indexed_by // argument 2 of multi_index_container: the definition of indices for the multi_index - this needs to be a indexed_by class (which in itself is template based)
        <
            boost::multi_index::hashed_non_unique // first index
                <
                    boost::multi_index::member
                        <
                            animal, std::string, &animal::name
                        >
                >,
            boost::multi_index::hashed_non_unique // seoncd index
                <
                    boost::multi_index::member
                        <
                            animal, int, &animal::legs
                        >
                >
        >
    > animal_multiindex; 


int main()
{
    std::cout << "Started program\n"; 

    // create and fill up the multi_index container
    animal_multiindex animals; 

        // CAUTION: If you fill up the multi_index_container container, you insert elements of the defined datastructure with their constructors and NOT like a common hash map (or any different container structure) by key (, index, ...)! 
    animals.insert({"Spider", 8}); 
    animals.insert({"Pig", 4});
    animals.insert({"Bird", 2});

    // change the values of an element of the mutli_index_container
    auto &legs_index = animals.get<1>(); 
    auto it = legs_index.find(4); 

    legs_index.modify(it, [](animal & a){
        a.name="Dog";
    }); 
        // the modify() method notifys all indices (aka interfaces), that the data behind the accessed data element has changed and updates their access-functionallity if this is necessary

    std::cout << "How many Dogs are in the multi_index_container? " << animals.count("Dog") << "\n"; 
    std::cout << "How many Pigs are in the multi_index_container? " << animals.count("Pig") << "\n";

    std::cout << "Finished program\n";
    return 0; 
}

/*
* Complile Command: 
*   $ g++ example_2_modify_multi_indices.cpp
*/