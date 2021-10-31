#include <iostream>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <string>

bool check_logging_status(boost::property_tree::ptree & pt)
{
    // check the logging level
    boost::property_tree::ptree & logging_tree = pt.get_child(boost::property_tree::ptree::path_type{"log.all"});
    return logging_tree.get_value<bool>();   
}

void read_and_print_data(boost::property_tree::ptree & pt, bool logging)
{
    boost::property_tree::ptree & animals = pt.get_child(boost::property_tree::ptree::path_type{"animals"});

    std::size_t animal_counter = 1; 
    for (const std::pair<std::string, boost::property_tree::ptree> & node_in_layer : animals)
    {
        // The cornered brackets get interpreted as an empty root-key. Therefore, no std::string argument will be accessable. In the example, there are two new trees under the animals key
        for (const std::pair<std::string, boost::property_tree::ptree> & st : node_in_layer.second){
            // The two subtrees has three keys of the keyless sub-root-tree. Therefore, the pair::first element contains the name of the key-value pair of the .json file 
            if (logging == true)
            {
                if (st.first == "name"){
                    std::cout << "Animal no " << animal_counter << " is: " << st.second.get_value<std::string>() << ", with the attributes:\n"; 
                    animal_counter++; 
                }
                else
                {
                    std::cout << st.first << ": " << st.second.get_value<std::string>() << "\n"; 
                }
            }
            else 
            {
                // Default case
                if (st.first == "name")
                {
                    std::cout << "Animal no. " << animal_counter << " is: " << st.second.get_value<std::string>() << "\n"; 
                    animal_counter++;
                }
                
            }
        }
        std::cout << "\n"; 
    } 
}


int main(int argc, char * argv [])
{
    
    // parse command line arguments and block invalid arguments
    if (argc != 2){
        std::cerr << "Wrong number of argumants. Usage:\n\t./a.out path_to.json\n"; 
        return 1; 
    }
    std::string path_to_file(argv[1]);
    std::cout << "Try to read " << path_to_file  << "\n";

    // create the tree
    boost::property_tree::ptree pt;
    try
    {
        boost::property_tree::json_parser::read_json(path_to_file, pt);    
    }
    catch(const std::exception& e)
    {
        std::cerr << "ERROR: An error occured during the read out of the json file: " << e.what() << '\n';
    }
    std::cout << "Read out successful. Start analyzing the data...\n\n"; 

    // get the logging status
    bool logging_status = check_logging_status(pt);   

    // read and print the json data with a boost::property_tree::ptree
    read_and_print_data(pt, logging_status);     

    std::cout << "Finished program.\n"; 
    return 0; 
}