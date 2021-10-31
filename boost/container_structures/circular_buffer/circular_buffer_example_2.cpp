#include <iostream>
#include <boost/circular_buffer.hpp>

int main()
{
    std::cout << "Example two started\n"; 

    boost::circular_buffer<int> cb{3};

    cb.push_back(5);  
    cb.push_back(6);
    cb.push_back(7);
    cb.push_back(8);

    std::cout << std::boolalpha << cb.is_linearized() << "\n"; 

    boost::circular_buffer<int>::array_range ar1; 
    boost::circular_buffer<int>::array_range ar2;

    ar1 = cb.array_one(); 
    ar2 = cb.array_two(); 
    std::cout << "array one size: " << ar1.second << " ; array two size" << ar2.second << "\n";
    std::cout << "Compared to the capacity: " << std::boolalpha << ((ar1.second + ar2.second) == cb.capacity()) << "\n"; 

    for (auto it : cb)
    {
        std::cout << it << "\n"; 
    } 

    // .array_one() returns the pair for accessing the start pointer of the ringbuffer until the end of memory of the ringbuffer 
    std::cout << "ar1.first: " << ar1.first << ", ar2.first: " << ar2.first << "\n"; 
    auto ar1_test = ar1.first; 
    auto ar2_test = ar2.first;
    std::cout << "ar1.first:\n"; 
    for (int i = 0; i < ar1.second; i++)
    {
        std::cout << ar1_test[i] << "\n"; 
    }
    std::cout << std::endl; 
    // .array_two() returns the pair for accessing the start of the memory until the end of the ringbuffer
    std::cout << "ar2.first:\n"; 
    for (int i = 0; i < ar2.second; i++)
    {
        std::cout << ar2_test[i] << "\n"; 
    }

    std::cout << "Linearizeing the circular buffer\n"; 
    cb.linearize(); 
    
    ar1 = cb.array_one(); 
    ar2 = cb.array_two(); 
    std::cout << "array one size: " << ar1.second << " ; array two size: " << ar2.second << "\n";

    std::cout << "Finished program\n"; 
    return 0; 
}

/*
* Compile Command
*   $ g++ circular_buffer_example_2.cpp
*/