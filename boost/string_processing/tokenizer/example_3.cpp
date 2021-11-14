#include <iostream>
#include <string>

#include <boost/tokenizer.hpp>

int main()
{
    std::cout << "Started program\n"; 

    std::string s = "Hello World, this is the Boost C++ Library!"; 

    boost::char_separator<char> sep_instance{" ", "+"};
        // Separate space and + but the + gets printed while the space gets not printed

    boost::tokenizer<boost::char_separator<char>> tok{s, sep_instance};  

    for (boost::tokenizer<boost::char_separator<char>>::iterator it = tok.begin(); it != tok.end(); it++)
    {  
        std::cout << *it << "\n"; 
    }
        // The +es get printed individually since they are used as separators but should NOT get surpressed

    std::cout << "Finished program\n"; 
    return 0;   
}