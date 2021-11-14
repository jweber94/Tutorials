#include <iostream>
#include <string>

#include <boost/tokenizer.hpp>

int main()
{
    std::cout << "Started program\n"; 

    std::string s = "Hello World, this is the Boost C++ Library!"; 

    boost::tokenizer<boost::char_separator<char>> tok{s}; 
        // a tokenizer instance is initialized with the string that it should process
    
    for (boost::tokenizer<boost::char_separator<char>>::iterator it = tok.begin(); it != tok.end(); it++)
    {
        std::cout << *it << "\n"; 
    }
        // The two + of C++ get separatly printed since they are interpreted as punctuation marks for the 
        // sepatation but did NOT get ignored, since the base implementation of char_separator<char> just 
        // ignores spaces

    std::cout << "Finished program\n"; 
    return 0; 
}