#include <iostream>
#include <string>

#include <boost/bimap.hpp>
#include <boost/bimap/vector_of.hpp>

int main()
{
    std::cout << "Started program\n"; 

    boost::bimap<boost::bimaps::set_of<std::string>, boost::bimaps::vector_of<int>> animals; 

    animals.insert({"cat", 4}); 
    animals.insert({"spider", 8});
    animals.insert({"ant", 6});

    auto el_it = animals.right; 
    auto el_left = animals.left; 

    std::cout << "The size of the right vector is: " << el_it.size() << "\n"; 

    el_it.sort(); 

    for (auto it = el_it.begin(); it != el_it.end(); it++)
    {
        std::cout << "The " << it->first << " has " << it->second << " legs\n";
    }
    std::cout << "Finished program\n"; 
    return 0; 
}
