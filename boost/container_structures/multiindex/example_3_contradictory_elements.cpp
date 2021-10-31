#include <iostream>
#include <string>

#include <boost/multi_index_container.hpp>
#include <boost/multi_index/hashed_index.hpp>
#include <boost/multi_index/member.hpp>


struct animal
{
    std::string name{};
    int legs{}; 
}; 

// typedefs are evaluated by the compiler, NOT by the precompiler and therefore typesafe
typedef boost::multi_index_container
    <
        animal,
        boost::multi_index::indexed_by
            <
                boost::multi_index::hashed_non_unique
                    <
                        boost::multi_index::member
                            <
                                animal, std::string, &animal::name
                            >
            >, 
                boost::multi_index::hashed_unique
                    <
                        boost::multi_index::member
                            <
                                animal, int, &animal::legs
                            >
                    >
            >
    > animal_multi;



int main(int argc, char * argv [])
{
    std::cout << "Started program\n"; 

    animal_multi animals; 

    animals.insert({"Spider", 8});
    animals.insert({"Cat", 4});
    animals.insert({"Dog", 4}); // gets ignored, since it contradicts the hashed_unique policy for the number of legs

    auto &legs_index = animals.get<1>(); // create a reference to the multi_index_container, that is able to access the second index (aka interface) --> reference, so we do not copy the container  
    std::cout << "The number of animals with four legs is: " << legs_index.count(4) << "\n"; 
    std::cout << "The animal behind the four legs is: " << legs_index.find(4)->name << "\n"; 
        // if you look for a container instance, you need to explicitly say, what member do you want from it! You can NOT simple access an (actually undefined) value behind a key, since there can 
        // (not in this example, but in general it is possable) be more then one remaining member to access by the used key

    std::cout << "The cat has " << animals.find("Cat")->legs << " legs\n"; 
    std::cout << "The dog has " << animals.find("Dog")->legs << " legs\n"; 

    std::cout << "The dog exists? " << (animals.find("Dog") != animals.end()) << "\n"; 
    std::cout << "The cat exists? " << (animals.find("Cat") != animals.end()) << "\n"; 

    std::cout << "Finished program\n"; 
    return 0; 
}