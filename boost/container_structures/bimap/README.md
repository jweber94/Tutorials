# ```boost::bimap```
+ Is a basic container that enables us to access the keys and values in a reciprocal manner
    - You can use the key to get the value that is behind it 
    - But you can also use the value to get back the key that is associated with it
+ A ```boost::bimap``` contains two containers of the type ```std::map```. Besides from the access from one side (key-side or value-side) of the container, you can show a bimap as a relational container
    - The two template arguments of the ```boost::bimap``` define container types for the right and the left side of the container
+ Limitations for the container structure is, that you can only have one value behind one key (in opposite to a std::multimap which can store multiple values behind one key.)
+ The implementation is based on ```boost::multi_index```
    - Therefore, you can apply the ```boost::multi_index::modify_key()``` function to change the key for values (which would not be possable within a ```std::map```)

## Other container types
+ You can use other container types for the ```.left``` and ```.right``` side of the ```boost::bimap``` by using the following bimaps container types: 
    - ```boost::bimaps::unordered_set_of```
    - ```boost::bimaps::unordered_multiset_of```
    - ```boost::bimaps::list_of```
    - ```boost::bimaps::vector_of```
    - ```boost::bimaps::unconstrained_set_of```
+ If you choose one of them, you can access the ```.left``` or ```.right``` iterator elements by the methods that are the same as the corresponding containers from the STL
    - Example: If you choose ```boost::bimaps::vector_of```, you can ```.sort()``` the vector and return all the iterator elements in the correct order. 
==> The container structure is how you can access the left or right side of the bimap and _NOT_ what container type you use to store your actual data in. (If you would like to do this, you have to define the bimap side with ```boost::bimaps::vector_of<std::vector>```)   

## Reference
+ https://dieboostcppbibliotheken.de/boost.bimap
+ https://newbedev.com/how-to-construct-boost-bimap-from-static-list
+ http://boost.cowic.de/rc/pdf/bimap.pdf
+ https://www.py4u.net/discuss/112034