#include <iostream>
#include <string>

#include <boost/bimap.hpp>

int main()
{   
    boost::bimap<boost::bimaps::set_of<std::string>, boost::bimaps::set_of<int>> animals; 
        // bimap calls implicitly boost::bimaps::set_on<T> - defines a container that is equivivalent to a std::map
        // you could use other boost::bimaps::* if you want to use another container on a side

    animals.insert({"cat", 4}); 
    animals.insert({"shark", 0});

    auto it_el = animals.right.find(4); 
    std::cout << "The animal with " << it_el->first << " legs is: " << it_el->second << "\n";  

    return 0; 
}