#include <iostream>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>


int main()
{
    boost::property_tree::ptree pt; 

    pt.put("home.jens.Schreibtisch", "20 files");
    pt.put("home.jens.Bilder", "50 files");  

    // write the constructed property tree 
    boost::property_tree::json_parser::write_json("saved_tree.json", pt); 

    // load the ptree from the file
    boost::property_tree::ptree pt2; 
    boost::property_tree::json_parser::read_json("saved_tree.json", pt2);

    std::cout << "The two ptrees equals another: " << (pt == pt2) << "\n"; 

    std::cout << "Finished program\n"; 
    return 0; 
}