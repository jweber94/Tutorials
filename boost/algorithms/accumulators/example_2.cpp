#include <iostream>

#include <boost/accumulators/accumulators.hpp>
#include <boost/accumulators/statistics.hpp>

int main()
{
    std::cout << "Started program\n"; 

    // create set instance
    boost::accumulators::accumulator_set<double, boost::accumulators::features<boost::accumulators::tag::mean, boost::accumulators::tag::variance>> acc; 

    // fill the accumulator set
    acc(5.5); 
    acc(3.1);
    acc(11); 
    acc(18); 
    acc(0.2); 

    // extract the calculations
    std::cout << "The mean is: " << boost::accumulators::mean(acc) << "\n";
    std::cout << "The variance is: " << boost::accumulators::variance(acc) << "\n"; 

    std::cout << "Finished program\n"; 
    return 0; 
}