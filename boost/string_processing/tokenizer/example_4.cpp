#include <iostream>
#include <string>

#include <boost/tokenizer.hpp>

int main()
{
    std::cout << "Started program\n"; 

    std::string s = "Hello World, this is the Boost C++ Library!";

    boost::char_separator<char> sep{" ", "+", boost::keep_empty_tokens}; 

    boost::tokenizer<boost::char_separator<char>> tok{s, sep}; 

    for (const auto & it : tok)
    {
        std::cout << it << "\n"; 
    }
        // Between the first and second + is an empty partial expression and between the 
        // + and the space is an empty partial expression. By default, they are surpressed 
        // but with the boost::keep_empty_tokens they are added as individual tokens, which you 
        // can see in this example

    std::cout << "Finished program\n"; 
    return 0; 
}