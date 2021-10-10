#include <iostream>
#include <boost/property_tree/ptree.hpp> // includes everything that is needed for working and creating property trees
#include <string>

int main()
{
    // initialize the datastructure
    boost::property_tree::ptree pt;
    // insert nodes and the stored value behind the "Schreibtisch" node (the edges of the ptree are initialized implicitly) 
    pt.put("home.jens.Schreibtisch", "2 files"); 

    // The following ptrees are just references, since the basic ptree pt exists and the references access subset of the complete ptree
    boost::property_tree::ptree & home = pt.get_child("home");
        // the root of the property tree is empty, so we need to get its first level of child nodes
    boost::property_tree::ptree & jens = home.get_child("jens");
    boost::property_tree::ptree & desktop = jens.get_child("Schreibtisch"); 

    std::cout << "This is the number of files within the Schreibtisch folder: " << desktop.get_value<std::string>() << "\n";
        // ptree::get_value<T> converts the value behind the node into the requested data format via the template argument (i.e. we want to convert it to a std::string, which is in this case possable. If you want to convert the value into an int, it would be a problem, since "20 files" could not directly be converted to an int)  
    return 0; 
}

/*
* Compile Command: 
*   $ g++ example_1.cpp 
*/