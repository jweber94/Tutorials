#include <iostream>
#include <string>

#include <boost/tokenizer.hpp>

int main()
{   
    std::cout << "Started program\n"; 

    std::string s = "Hello World, this is the Boost C++ Library!"; 

    boost::char_separator<char> separator_instance{" "};
        // No punctuation marks are used for separation except of the (surpessed) separation mark 'space'
        // Therefore, the , and the ! are added to the tokens of the words before them

    boost::tokenizer<boost::char_separator<char>> tok {s, separator_instance}; 

    for (const auto & it : tok)
    {
        std::cout << it << '\n'; 
    }

    std::cout << "Finished program\n";
    return 0; 
}