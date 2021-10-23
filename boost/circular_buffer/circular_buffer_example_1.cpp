#include <iostream>
#include <boost/circular_buffer.hpp>

int main()
{
    boost::circular_buffer<int> cb{3}; // creates a ring buffer with the capacity of three int values 

    // access properties of a circular buffer instance
    std::cout << "The capacity of the ringbuffer is: " << cb.capacity() << "\n"; 
    std::cout << "The size of the ringbuffer before insertion of elements is: " << cb.size() << "\n"; 
        // If no data was inserted, the capacity (= allocated memory) is 3 but the size of the ringbuffer is zero --> The size describes the currently used amount of elements within the ringbuffer (can be reduced with pop_back() or pop_front() after data was inserted)
    // insert some data
    cb.push_back(0);
    cb.push_back(1);
    cb.push_back(5);

    std::cout << "The size of the ringbuffer after the insertion of the data is: " << cb.size() << "\n";

    // Add more data then the capacity to the ringbuffer
    cb.push_back(8); 
    cb.push_back(9);
    cb.push_back(10);

    std::cout << "The size of the ringbuffer after the second data insertion (which exceeds the maximum amount of available memory) is: " << cb.size() << "\n"; 

    // print out the data from the ringbuffer
    std::cout << "This is the data within the ringbuffer:\n"; 
    for (auto it : cb)
    {
        // the boost::circular_buffer implements an iterator class
        std::cout << it << "\n";
            // The first inserted data was overwritten by the new data after the front pointer of the ringbuffer has reached the end of the memory
    }

    std::cout << "Finished program\n"; 
    return 0; 
}

/*
* Compile Command:
*   $ g++ cicular_buffer_example_1.cpp 
*/