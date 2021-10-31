#include <iostream>
#include <string>

#include <boost/multi_index_container.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/sequenced_index.hpp>
#include <boost/multi_index/random_access_index.hpp>
#include <boost/multi_index/member.hpp>

struct animal
{
    std::string name{}; 
    int legs{0}; 
}; 

typedef boost::multi_index_container
    <
        animal, 
        boost::multi_index::indexed_by
            <
                boost::multi_index::sequenced<>, // linked list
                boost::multi_index::ordered_non_unique // sorted list / min or max heap
                    <
                        boost::multi_index::member
                            <
                                animal, int, &animal::legs // sorting by the number of legs while inserting new instances in the multi_index_container
                            >
                    >, 
                boost::multi_index::random_access<> // array/vector
            >
    > animals_multi;  


int main()
{
    std::cout << "Started program\n"; 

    animals_multi animals; 

    animals.push_back({"Spider", 8}); 
    animals.push_back({"Chicken", 2});
    animals.push_back({"Cat", 4});
    animals.push_back({"Snake", 0}); 

    // The ordered list keeps track of the order, defined by an attribute
    // get the ordered list from the multi_index_container
    auto & legs_index = animals.get<1>(); 

    // lower and upper bound is a standart functionallity of a ordered list / min/max heap 
    auto it = legs_index.lower_bound(2); 
    auto end = legs_index.upper_bound(8); 

    // go over all elements by the iterator from 2 to 8 legs in a ordered manner
    std::cout << "The animals with 2 to 8 legs are:\n"; 
    for (; it!=end; it++)
    {
        std::cout << it->name << "\n"; 
    }

    // The vector indice of the multi index keeps track of the order how elements are inserted
    auto & vector_index = animals.get<2>(); 
    std::cout << "The first inserted element is: " << vector_index[0].name << "\n"; 

    std::cout << "Finished program\n"; 
    return 0; 
}