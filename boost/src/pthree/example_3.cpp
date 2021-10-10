#include <iostream>
#include <cstdlib>
#include <boost/optional.hpp>
#include <boost/property_tree/ptree.hpp>
#include <string>

struct string_to_int_translator
{
    typedef std::string internal_type; 
    typedef int external_type; 

    boost::optional<int> get_value(const std::string & str)
    {
        char * c; 
        long l = std::strtol(str.c_str(), &c, 10); // string to long
            // convert string to a decimal number (which is defined by the number base of 10 in the last parameter)

        return boost::make_optional(c != str.c_str(), static_cast<int>(l)); 
            // check if the conversion was successful and if it is, cast the long to an int and return 
            // c != str.c_str() means that the string that is handed over must not contain a letter as a char
    }

}; 


int main()
{
    typedef boost::property_tree::iptree ptree;
        // whenever we use ptree, we get an iptree 
        // iptree is the same datastructure as a ptree but the keys are independend of capital letters in std::strings, so home/jens/Schreibtisch will be used the same way, like Home/Jens/Schreibtisch would do

    // initialize and create the (i)ptree 
    ptree pt; 

    pt.put(ptree::path_type{"home/jens/Schreibtisch", '/'}, "20 files");
    pt.put(ptree::path_type{"home/jens/Bilder", '/'}, "30 files");

    // create a function pointer to the self defined value translator function 
    string_to_int_translator tr; 

    // get the values behind the keys of the ptree
    int num_files = pt.get<int>(ptree::path_type{"home/jens/Schreibtisch", '/'}, tr) + pt.get<int>(ptree::path_type{"home/jens/Bilder", '/'}, tr); 

    std::cout << "The number of files in the looked up file structure is: " << num_files << "\n";  
    return 0; 
}