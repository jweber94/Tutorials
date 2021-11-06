#include <iostream>

#include <boost/accumulators/accumulators.hpp>
#include <boost/accumulators/statistics.hpp>

int main()
{
    std::cout << "Started program\n"; 

    boost::accumulators::accumulator_set
        <double, 
        boost::accumulators::features
            <
                boost::accumulators::tag::mean, 
                boost::accumulators::tag::variance
            >, 
        int> acc; 

    acc(8, boost::accumulators::weight = 1);
    acc(9, boost::accumulators::weight = 1);
    acc(10, boost::accumulators::weight = 4);
    acc(11, boost::accumulators::weight = 1); 
    acc(12, boost::accumulators::weight = 1);
        // To hand over weights to the accumulator, we need to specify boost::parameter elements when we insert new numbers to the accumulator_set

    std::cout << "The weighted mean is: " << boost::accumulators::mean(acc) << "\n"; 
    std::cout << "The weighted variance is: " << boost::accumulators::variance(acc) << "\n"; 
    
    std::cout << "Finished program\n"; 
    return 0; 
}