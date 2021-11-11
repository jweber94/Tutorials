#include <iostream>
#include <string>

#include <boost/bimap.hpp>

int main()
{   
    std::cout << "Started program\n"; 
    boost::bimap<std::string, int> animals; 
        // name, number_of_legs

    animals.insert({"cat", 4});
    animals.insert({"shark", 0});
    animals.insert({"spider", 8});
    animals.insert({"ant", 6});
    animals.insert({"dog", 4}); // gets ignored since it violaes the container uniqueness condition

    std::cout << "There are " << animals.left.count("cat") << " cats\n"; 
    std::cout << "There are " << animals.right.count(8) << " animals with 8 legs\n"; 
    std::cout << "There are " << animals.left.count("dogs") << " dogs\n";

    std::cout << "Finished program\n"; 
    return 0; 
}