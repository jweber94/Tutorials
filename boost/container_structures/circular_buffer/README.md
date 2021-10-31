# Boost CircularBuffer
+ The boost circular buffer is a ring buffer datastructure which has two main properties
    - The capacity of the buffer remains constant
    - We can push_back data to the ring buffer as often as we want, even if the maximum capacity of the ring buffer is already filled with data - if this is the case, the fifo principle will be used in order to rewrite the data
+ Use case: 
    - ***Restricted amount of available Memory:*** Fixed amound of memory is defined and it should ne be possable to newly allocate more memory. 
    - ***Old data is obsolete:*** Old data is not needed after enough new data was received/calculated/stored in the container. Therefore, the old data can be discarded. --> Old data will get overwritten, after  
+ circular_buffer is implemented as a template - therefore, it is able to store an arbitrary kind of datatypes
+ The amount of memory of the ringbuffer is determined during construction of the individual instance by handing over the datatype that should be stored via the template argument, as well as the constructor that wants to have the number of elements that should be stored in the circular_buffer instance. 
+ (1) Beginning and end of a ringbuffer are ***not*** strictly defined!
    - In contrast to a vector container-datastructure, where the smallest memory address corresponds to the first inserted data element within the vector and the greatest memory address corresponds to the last inserted data element
    - Even if this memory-dataelement correspondence is not given, a circular_buffer has an iterator class attached to it and you can get the "first" and "last" iterator by calling the cb.begin() and cb.end() methods


## Ringbuffer specific functionallities
+ Because the beginning and end of the ringbuffer is not properly defined, like in (1) described, it is recommend to access ringbuffer-elements with the iterator-class of the ```boost::circular_buffer<T>```. 
    - If you want to access ringbuffer elements with their indices, you have to check, how the current pointers for the .begin() instance and .end() instance are located within the memory.
+ Special Methods: 
    - ```cb.is_linearized()```: Returns ```true```, if the smallest memory address corresponds to the .begin() pointer of the memory and return ```false``` if that is not the case.
        - In the case of a ```true``` return statement, you can access the elements of the ringbuffer with the indices ```0``` to ```.cb.size-1``` like you would do with a standart C-style array. A ```false``` return value emerges, if you insert a data element to the ringbuffer after the capacity is completly used. Then, the end pointer goes to the first element of the ringbuffer and the end pointer is the second index within the allocated memory. 
    - ```cb.array_one()```: returns a ```std::pair<T, K>```, which has as .first() a pointer to the array and as .second() the size of the array that starts at the smallest address within the circulat buffer
    - ```cb.array_two()``` returns a ```std::pair<T, K>``` with a pointer and a size that ends on the greatest memory address. If the circular_buffer is linearized, the array_two contains zero elements. 
    - ```cb.linearize()``` rearranges the circular_buffer such that we can access all elements within the ringbuffer with ```.array_one()```. 
        ==> For seeing how to access the data by index with the array_one() and array_two() methods, see circular_buffer_example_2.cpp


## Important extension 
+ ```boost::cicular_buffer_space_optimized```: 
    - Is used like the common ```boost::circular_buffer``` but allocates memory dynamically until the maximum defined capacity is reached. 
    - If you pop elements out of the optimized ringbuffer, memory also gets deallocated. 
+ the memory optimized version is useful, if the ringbuffer size is big and the program does not necessarily need the complete buffer size. 