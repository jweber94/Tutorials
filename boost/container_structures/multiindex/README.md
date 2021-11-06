# ```boost::multiindex```
+ Enables the definition of containers that are able to implement multiple interfaces - you can imagine that a multiindex data container enables to combine the advantages of multiple container classes from the STL in one container structure
    - Example: A multiindex container can be accessed by index like a std::vector as well as a sorted list like a std::set
+ The ```boost::muliindex``` container is especially useful, if you want to access the data in different ways in your code. 
    - Without a ```boost::multiindex```, you would need to save the elements in two different container structures and synchronize them during runtime. With a multiindex, you can just use one container for this. Therefore it is much more memory efficient then two containers and a little more calculation efficient, since the synchronization between the containers is not necessary 
    - Also it is useful, if you want to access the datastructures within the container based on different properties within your project. E.g. if you want to lookup names with their properties and also want to lookup the names behind the properties. This would require two hashmaps that need to be synchronized. 
    + ***==> Use ```boost::multiindex``` if you would need to store the same data in different containers to properly access them for your usecase***

## Creating ```boost::multi_index``` containers
+ You first have to decide, which containers-access interfaces you need
    - For every interface, you need to define how they should look like and then, ```boost::multi_index::multi_index_container``` will create a container structure in the backgroud, that deliver the defined interfaces.
    - ```boost::multi_index``` calls the defined interfaces "index", which gives the container structure its name
+ The basic container is the ```boost::multi_index::multi_index_container```, which is a template class that accepts at least two template arguments
    - first: datastructure that should be stored within the multi_index container
    - second: define, which indices should be suppored by the container 
    - third: next index definition - the ```multi_index_container``` is a variadic template
+ ==> This means, that you must know in advance, which interfaces the multi_index container should have.
+ The definition of the interfaces that should be used is defined by the ```boost::multi_index::indexed_by``` class. 
    - Is a variadic template, from which every template argument defines an interface
    - If we do not have trivial datastructure (e.g. self defined classes or structs), every template argument of ```boost::multi_index::indexed_by``` needs to be a ```boost::multi_index::member```, which is a helper class to provide attributes for the indexing complex datatypes, like self defined structs or classes. 
        - Here, you can define which property of a class should be used for the hash map key.
+ In the ```example_1_animal_properties.cpp```, the multi_index enables the access to the container of the datastructure "animal" through the number of legs OR the name. This is advantagous, if you have an application that looks up animals based on one of the defined indices.
    - The key of the "simulated" hash map is depended of what we use as the key!

## CAUTION by using multi_index containers
+ You can ***not*** change the value behind a used key of the multi_index container in an easy way, like rewriting the data that lies behind the key if they are used by another index, since this would change the hash-value in the case of a hashmap based indexing of the multi_index container. 
    - you need to inform the other indices that you want to change the value behind a key and if you do this, it will be save to change the value behind a key, that is used as a key for another index. 
    - Therefore, the ```.modify()``` method is used. See example_2_modify_indices.cpp
+ You fill up the ```multi_index_container``` with instances of the handed over datastructures by inserting instances of the defined datastructure (by calling the constructor of handing over (copy or moving) instances of the datastructure) and ***NOT*** by filling up by the common way of the requested container interfaces (aka indices) of the multi_index_container!
+ You can not save/use datastructures with all multi_index indices (aka interfaces), if the datastructure does not support the requested container interface
    - This can also apply to contradictory values within datastructures that should be stored within the ```multi_index_container```, see ```example_3_contradictory_elements.cpp``` and ```example_5_other_key_extractors.cpp```
        - Here, a hased_unique and a hashed_non_unique is used. So we can insert multiple cats in the mutli_index_container, but they can _NOT_ have the same number of legs (which is in this example a little unfortunat choosen)
+ If you want to look for an instance in a multi_index_container, you can use the ```container.find(key) != container.end()``` syntax, since the mutli_index_container delivers iterator instances back in the most cases 

## Accessing container elements
+ By default, you use the first definition of the indice (aka interface) of the ```boost::multi_index::multi_index_container``` typedef
    - If you want another interface, you need to get it from the container by using the ```.get<num_index>()``` method. ```num_index``` starts at 0 with the default interface. If you take ```num_index=1```, you access the second index (aka interface) definition
    - If you want to access the mutli_index_container by another index then <0>, you want to store it in an ```auto & second_index = container.get<1>()```, since the reference to the container avoids copying or moving it (which is memory and calculation intense)
+ If you access an element by (e.g.) ```.find("spider")``` (dependend on the index-definition that you have choosen in the typedef), you receive an boost iterator instance, which is a pointer to the conrete instance of the datastructure, so you can access the indidual components of the instance by using a pointer dereference (-> or *iterator.member)

## Other indices/interfaces for the multi_index_container
+ You can use ```boost::multi_index::sequenced``` (linked list), ```boost::multi_index::ordered_non_unique``` (ordered list, aka min heap) or ```boost::multi_index::random_access``` and all of them keep track of the individual indexing and provide the corresponding functionionallities/member functions
    - See example_4_sequenced_index.cpp
    - Caution: It does not make sense to insert ```boost::multi_index::sequenced``` if you also use ```boost::multi_index::random_access```, since ```sequenced``` is a subset of ```random_access```

## Key Extractors
+ Besides from ```boost::multi_index::member``` there are other functions to define a key or an element to do the sorting like we have seen before!
+ Key extractors define which element of the used datastructure should be used in order to fulfill the individual container properties
+ Other key extractors are
    - ```boost::multi_index::identity```: Says, that the given datastructure should define how it is ordered or accessed itself. In the case of a ordered list, it is necessary that the datastructure has a < operator defined
    - ```boost::multi_index::const_mem_fun``` and ```boost::multi_index::mem_fun```: Says what function should be used in order to fulfil the index definition (the return type of the function is therefore important). The const version is used if the method is also const
    - ```boost::multi_index::global_fun``` and ```boost::multi_index::composite_key``` are based on the same idea like ```boost::multi_index::const_mem_fun```/```boost::multi_index::mem_fun``` but with global or combined functions-look this up in the documentation if needed


### References
+ https://dieboostcppbibliotheken.de/boost.multiindex
+ http://doc.crossplatform.ru/boost/1.36.0/libs/multi_index/doc/tutorial/index.html
+ https://www.boost.org/doc/libs/1_75_0/libs/multi_index/doc/tutorial/indices.html
+ https://www.caichinger.com/boost-range/boost-make_iterator_range.html
