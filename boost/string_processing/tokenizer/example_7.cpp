#include <iostream>
#include <string>

#include <boost/tokenizer.hpp>

int main()
{
    std::string s = "Hello World, this is the Boost C++ Library"; 
    int offsets[3]{5, 5, 9}; 

        // create a separator instance 
    boost::offset_separator sep{offsets, offsets + 3}; 
    auto offsets_test {offsets + 3}; 
    std::cout << "This is offsets + 3:\n" << offsets_test[0] << "\n" << offsets_test[1] << "\n" << offsets_test[2] << "\n";   

        // create the tokenizer instance by handing over the string and the separator instance 
    boost::tokenizer<boost::offset_separator> tok{s, sep}; 

    for (const auto &t : tok)
    {
        std::cout << t << "\n"; 
    }

    return 0; 
}