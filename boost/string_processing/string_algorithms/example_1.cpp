#include <iostream>
#include <string>

#include <boost/algorithm/string.hpp>

int main()
{   
    std::string s = "Hello World, this is the Boost C++ Library"; 
    std::string test = boost::algorithm::to_upper_copy(s); 
    std::cout << "orignal: " << s << "\n"; 
    std::cout << test << "\n"; 
    boost::algorithm::to_lower(s);
    std::cout << "original: " << s << "\n"; 
    return 0; 
}