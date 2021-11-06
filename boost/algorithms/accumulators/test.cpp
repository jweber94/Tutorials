#include <iostream>

#include <boost/accumulators/accumulators.hpp>
#include <boost/accumulators/statistics/stats.hpp>
#include <boost/accumulators/statistics/rolling_mean.hpp>
#include <boost/accumulators/framework/accumulator_set.hpp>
#include<boost/accumulators/framework/extractor.hpp>
#include <boost/fusion/functional.hpp>


using namespace boost::accumulators;

int main()
{

    
accumulator_set<int, stats<tag::rolling_mean> > acc2(tag::rolling_window::window_size = 5);

acc2(1);
acc2(2);
acc2(3);

std::cout<<"rolling mean:"<<rolling_mean(acc2)<<"\n";
// (1+2+3)/3=6/3=2
acc2(4);
acc2(5);
acc2(6);
acc2(7);
//(3+4+5+6+7)/5=25/5
std::cout<<"rolling mean:"<<rolling_mean(acc2)<<"\n\n";
    

    return 0;
}
