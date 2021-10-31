#include <iostream>
#include <boost/property_tree/ptree.hpp>

int main()
{   
    typedef boost::property_tree::basic_ptree<std::string, int> ptree; 
        // redefine the datatype for the ptree datastructure from <std::string, std::string> to <std::string, int> as the <key, value> template arguments for the ptree nodes
        // this redefines the default behaviour, but it is also possable to store it as other datatypesl 

    // create ptree
    boost::property_tree::ptree pt; 
    pt.put(boost::property_tree::ptree::path_type{"home/jens/Schreibtisch", '/'}, 3); 
    pt.put(boost::property_tree::ptree::path_type{"home/jens/Downloads", '/'}, 5);
    pt.put(boost::property_tree::ptree::path_type{"home/jens/Bilder", '/'}, "20"); 
    /*
    Creates the followning tree structure

    * (empty)
    |
    * (home)
    |
    ________________________
    |                      |
    * (Schreibtisch - 3)   * (Downloads - 5)

    */

    boost::property_tree::ptree & jens = pt.get_child(ptree::path_type{"home/jens", '/'}); // get child creates a new ptree datastructure with the requested child as the root node

    std::size_t num_all_files = 0; 
    // the iterator is a std::pair because ptree delivers an iterator of the std::pair<T1, boost::property_tree::ptree>, where T1 is the key of the ptree and the second template argument is the ptree that is under the subtree
    for (const std::pair<std::string, boost::property_tree::ptree> & p : jens)
    {
        num_all_files += p.second.get_value<int>(); 
            // second is an attribute of std::pair
    }

    std::cout << "The number of files in the ptree directory tracker is: " << num_all_files << "\n"; 

    return 0; 
}