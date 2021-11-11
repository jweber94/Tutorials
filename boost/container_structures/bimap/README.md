# ```boost::bimap```
+ Is a basic container that enables us to access the keys and values in a reciprocal manner
    - You can use the key to get the value that is behind it 
    - But you can also use the value to get back the key that is associated with it
+ A ```boost::bimap``` contains two containers of the type ```std::map```. Besides from the access from one side (key-side or value-side) of the container, you can show a bimap as a relational container
    - The two template arguments of the ```boost::bimap``` define container types for the right and the left side of the container
+ Limitations for the container structure is, that you can only have one value behind one key (in opposite to a std::multimap which can store multiple values behind one key.)
+ The implementation is based on ```boost::multi_index```
    - Therefore, you can apply the ```boost::multi_index::modify_key()``` function to change the key for values (which would not be possable within a ```std::map```)

## Reference
+ https://dieboostcppbibliotheken.de/boost.bimap
+ https://newbedev.com/how-to-construct-boost-bimap-from-static-list