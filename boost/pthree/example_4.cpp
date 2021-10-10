#include <iostream>
#include <utility>
#include <boost/property_tree/ptree.hpp>

int main()
{
    boost::property_tree::ptree pt; 
    pt.put("home.jens.Schreibtisch", "20 files");

    // get optional trys to get the value from the key and if the key does not exist, it delivers an empty object. Therefore it needs to be an std::options/boost::optional as the corresponding lvalue. 
    boost::optional<std::string> c = pt.get_optional<std::string>("home");
    std::cout << "The requested key is initialized: " << std::boolalpha << c.is_initialized() << "\n"; 

    // add sub-ptrees to the pt base tree
    pt.put_child("etc.systemd", boost::property_tree::ptree{"50 files"});
        // adds the value to an existing node/ptree if it 
    pt.add_child("etc.systemd", boost::property_tree::ptree{"60 files"});  
        // adds a new key-value, independent of if there is already a node with the key

    // get the subtree for etc from the complete pt ptree
    boost::property_tree::ptree etc = pt.get_child("etc"); 

    // iterate over the added subtree
    for (const std::pair<std::string, boost::property_tree::ptree> & p : etc)
    {
        std::cout << p.second.get_value<std::string>() << "\n";  
    }

    boost::optional<boost::property_tree::ptree &> sys = pt.get_child_optional("sys"); 
    std::cout << "The sys folder exists: " << sys.is_initialized() << "\n"; 

    std::cout << "Finished program\n"; 
    return 0; 
}