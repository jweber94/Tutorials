# Container Structures

+ Container structures are wrappers around datastructures, to store multiple instances of a datastructure and access the properties of the containers as well as applying algorithms on the container structure. 
+ Different container structures has different possabilies to access their datastructure elements (random access, linear access, ...)

## Main Datastructures
+ ```boost::multiindex```: Enables the use of multiple access-interfaces that are used by other container types (e.g. arrays, linked lists, unordered maps, ...) and concatinate the advantages of all of the other containers
+ ```boost::bimap```: Like a hash map, but they can be accessed form both sides to get the underlying values. This means, that you can take a value and lookup their key, which is not possable in a classic hashmap like ```std::unordered_map```
+ ```boost::array```: Array, like ```std::array```
+ ```boost::unordered_map```: hasmap, like ```std::unordered_map```
```boost::unordered_set```: Array, like ```std::set```
+ ```boost::circular_buffer```: Ringbuffer instance to read, write and pop from. If you exceed the capacity, you will override the first inserted instance 
+ ```boost::heap```: Is a heap datastructure that acts like a ```std::priority_queue```
+ ```boost::intrusive```: Container that avoids copying or moving. But in order to insert elements in a ```boost::intrusive```, some conditions for the datastructure must be fulfilled
+ ```boost::multiarray```: Realizes a basic matrix class (mutlidimensional array)
+ The boost container library contains all container structures, that are provided by the STL. The advantage of using the boost container library is, that you will not have different implementations for different target systems where you compile your code, which might be the case for the STL