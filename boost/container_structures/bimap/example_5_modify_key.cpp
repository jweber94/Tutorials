#include <iostream>
#include <string>

#include <boost/bimap.hpp>
#include <boost/bimap/unconstrained_set_of.hpp>
#include <boost/bimap/support/lambda.hpp>

int main()
{
    std::cout << "Started program\n"; 

    boost::bimap<boost::bimaps::set_of<std::string>, boost::bimaps::unconstrained_set_of<int>> animals; 
        // with boost::bimaps::unconstrained_set_of you disable the accessing of the corresponding side (left or right) for the bimap

    animals.insert({"cat", 4}); 
    animals.insert({"shark", 0});
    animals.insert({"spider", 8});

    auto it_el = animals.left.find("cat"); 
    animals.left.modify_key(it_el, boost::bimaps::_key = "dog"); 
        // This would not be possable in a std::map

    std::cout << "The key is " << it_el->first << "\n"; 

    std::cout << "Finished program\n";
    return 0; 
}