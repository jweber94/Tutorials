#include <iostream>
#include <string>

#include <boost/bimap.hpp>

int main()
{   
    std::cout << "Started program\n"; 
    boost::bimap<std::string, int> animals; 

    animals.insert({"cat", 4});
    animals.insert({"ant", 6});
    animals.insert({"shark", 0});   

    for (auto it = animals.begin(); it != animals.end(); ++it)
    {
        std::cout << "The " << it->left << " has " << it->right << " legs\n"; 
    }

    std::cout << "Finished program\n"; 
    return 0; 
}