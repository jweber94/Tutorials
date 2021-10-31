#include <iostream>
#include <string>
#include <utility>

#include <boost/multi_index_container.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/hashed_index.hpp>
#include <boost/multi_index/identity.hpp>
#include <boost/multi_index/mem_fun.hpp>

class animal
{
    public:
        animal(std::string && name, int && num_legs) : name_(std::move(name)), legs_(num_legs)
        {
            // initialization just with rvalues possable
            std::cout << "Constructor of animal " << name_ << " was called\n";
        } 

        bool operator<(const animal & a) const 
        {
            // compare the number of legs with the legs of the handed over animal 
            return this->legs_ < a.legs_; 
        }

        const std::string & name() const
        {
            // const reference so that the caller could NOT modify the name accidentially
            return name_; 
        }

    private:
        std::string name_;
        int legs_;
};

typedef boost::multi_index_container
    <
        animal,
        boost::multi_index::indexed_by
            <
                boost::multi_index::ordered_unique // ordered list
                    <
                        boost::multi_index::identity 
                        <
                            animal // sorting element defined by the < operator of the animal class - this is possable since the identity accesses the < operator to sort by default - a class is sortable as long as the < operator for the comparison with itself is defined
                        >
                    >,
                boost::multi_index::hashed_unique // unique hash table
                    <
                        boost::multi_index::const_mem_fun // key defined by the name method
                            <
                                animal, const std::string &, &animal::name
                            >
                    >
            >
    
    > animal_multi; 


int main()
{
    std::cout << "Started program\n"; 

    animal_multi animals; 

    animals.emplace("Cat", 4); 
    animals.emplace("Shark", 0);
    animals.emplace("Spider", 8);
    animals.emplace("Shark", 0); // Gets ignored for the hash table, since it is a unique hash table for the name key 

    std::cout << "The number of elements in the list is: " << animals.size() << "\n"; 
        // In a multi_index_container, elements that are contradicting insertion policy in for one container are completly ignored for all other containers - the second shark is not even inserted into the sorted list, even if it just contradicts the hash maps policy

    std::cout << "The animal with the least number of legs is: " << animals.begin()->name() << "\n"; 

    // access the hashmap
    auto & hash_index = animals.get<1>(); 

    std::cout << "The number of sharks in the list is: " << hash_index.count("Shark") << "\n";

    std::cout << "Finished program\n"; 
    return 0; 
}