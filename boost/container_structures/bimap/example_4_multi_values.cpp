#include <iostream>
#include <string>

#include <boost/bimap.hpp>
#include <boost/bimap/multiset_of.hpp>
    // boost/bimap/set_of is the default and therefore it is implicitly included by boost/bimap.hpp

int main()
{
    std::cout << "Started program\n"; 
    boost::bimap<boost::bimaps::set_of<std::string>, boost::bimaps::multiset_of<int>> animals; 
        // enables the multiple existance of a value - The "key" for .right now does not need to be unique
    
    animals.insert({"shark", 0});
    animals.insert({"cat", 4}); 
    animals.insert({"ant", 6});  
    animals.insert({"dog", 4}); 

    std::cout << "There are " << animals.right.count(4) << " animals with 4 legs\n"; 

    std::cout << "Finished program\n"; 
    return 0; 
}