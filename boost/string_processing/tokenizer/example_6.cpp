#include <iostream>
#include <string>

#include <boost/tokenizer.hpp>

int main(int argc, char * argv [])
{
    std::cout << "Start program\n"; 

    std::string s = "Hello World,this is\nthe Boost C++ library"; 
        // Iterate over comma separated values
        // Also new line commands are identified as a comma
    boost::tokenizer<boost::escaped_list_separator<char> > tok{s}; 

    for (const auto & t : tok)
    {
        std::cout << t << "\n"; 
    }

    std::cout << "Finished program\n";  
    return 0; 
}