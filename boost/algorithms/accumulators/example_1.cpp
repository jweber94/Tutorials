#include <iostream>

#include <boost/accumulators/accumulators.hpp>
#include <boost/accumulators/statistics.hpp> // To access the standart accumulators, delivered by the library

int main()
{   
    std::cout << "Started program\n"; 

    // create accumulator
    boost::accumulators::accumulator_set<int, boost::accumulators::features<boost::accumulators::tag::count>> acc; 
        // The count tag says that we want to count the number of elements that we have inserted to the accumulator set, therefore the result is 3

    // fill up the accumulator
    acc(4); 
    acc(-6); 
    acc(9); 
    
    std::cout << "The number of elements in the accumulator set is: " << boost::accumulators::count(acc) << "\n"; 

    std::cout << "Finished program\n"; 
    return 0; 
}