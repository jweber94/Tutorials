#include <iostream>

#include <boost/accumulators/accumulators.hpp>
#include <boost/accumulators//statistics/stats.hpp>
#include <boost/accumulators/statistics/rolling_mean.hpp>

int main()
{   
    std::cout << "Started program\n"; 
    int window = 3; 
    boost::accumulators::accumulator_set<double, boost::accumulators::stats<boost::accumulators::tag::rolling_mean> > acc(boost::accumulators::tag::rolling_window::window_size = window); 

    acc(5); 
    acc(7); 
    acc(1); 
    acc(6);
    acc(17);

    std::cout << "Mean of the last three elements: " << boost::accumulators::rolling_mean(acc) << "\n"; 

    std::cout << "Finished program\n"; 
    return 0; 
}