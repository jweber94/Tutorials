# Theory about the ptree Datastructure
+ Is the same datastructure that the UNIX file system is using
+ It is a tree structure that is used to store key-value pairs
    - Every node can have an arbitrary number of edges
+ Jeder Knoten hat neben den nachfolgenden Zweigen auch noch ein Attribut
    - Example: Filesystem
        * /home/jens/Documents contains 20 Files and subfolders
        * home, jens and Documents are nodes within the tree
        * the folder "/" represent the edges of the tree 
        * The 20 is the stored attribut for the node "Documents"
+ Is a recursiv datastructure, which mean that every node that is not a root node, can be interpreted as an individual ptree datastructure
    - This is the same functionallity like mounting filesystems into your linux file system
+ The ptree datastructure is mainly used to store and manage data during runtime, but it can be used to store and load data to/from disc. 
    - The focus of the implementation is meant to store and manage data during runtime
+ Two nodes in the same layer of a ptree CAN have the same key!
    - Can be inserted by .add_child()

## Documentation: 
+ https://www.boost.org/doc/libs/1_65_1/doc/html/property_tree.html
+ Introduction: https://dieboostcppbibliotheken.de/boost.propertytree

## Logical dependencies

* --> root node (empty)
_____________
| edge_1_1  | edge_1_2  
* node_1_1  * node_1_2 (eg. "home") --> data: (e.g.) 2 files
____________ ____________
|           |           |
*           *           *
                        _________
                        |       |
                        *       *

+ Every child node can be the root of a new ptree datastructure (this is shown as an example by the deepest three nodes)
    - If you create a new ptree based on another ptree, the root node (or more commonly said, all individual addressed nodes) does not know its key. It just knows its assigned values behind the key. 
        - Therefore, it is best practice to name the newly created tree with the name of the node for that it was created. (At least as long as this is possable)
    - You can use the .get_value() method with a root node, but there is NO method for accessing/reading out the key of a (root-)node. --> The keys are just known to the next upper layer of the ptree datastructure
    - See example_3.cpp

## Syntax
+ In order to separate strings for node names, boost::property_tree::ptree uses the '.' literal to separate the names of the given string
    - If you want to use your own separator for node names, you need to hand over a boost::property_tree::ptree::path_type object. It takes two arguments:  
        * path/the key that should be created within the ptree datastructure and the separator literal
        * e.g. pt.put(boost::property_tree::ptree::path_type{"home/jens/Schreibtisch", '/'}, 3);
    - After the key with the custom separator literal, the value behind the node is given. In the example above, this is 3 
+ boost::property_tree::ptree is a template datastructure, but it is predefined with std::string, since the most common use case of ptrees are with strings as keys and values 
    - It is based on the boost::property_tree::basic_ptree
    - If you want to use a different datatype for keys and values, you need to redefine it. This is shown in example_2.cpp in the 6th line. 
+ boost::property_tree::ptree has the methods .begin() and .end(), like all other STL/boost container datastructures
    - In contrast to other containers, we just can iterate over one layer of nodes within a ptree strucure. I.e. we can ***not*** iterate over the complete ptree with all its nodes
+ .get<T>()
    - You can request the value from an absolute path of the ptree
+ .get_value<T>() 
    - Requests the value from the current root node
### Translators
+ Translators can be used with .get<T>(key, transl) and .get_value<T>(key, transl)
+ Translators are delivered by default with the boost::property_tree::ptree library. But you can define your own, depending on what template arguments for the keys and values were defined (i.e. for the boost::property_tree::basic_ptree<Key, Value>)
    - You can see a custom translator in example 3
    - Ref.: https://www.boost.org/doc/libs/1_65_1/doc/html/property_tree/reference.html#header.boost.property_tree.id_translator_hpp, https://stackoverflow.com/questions/9745716/change-how-boostproperty-tree-reads-translates-strings-to-bool
    - Custom translators MUST define an internal_type and an external_type
## put vs put_child/add_child
+ .put() adds just one key-value pair
+ .put_child() adds a complete ptree as a child node - the second parameters is therfore a boost::property_tree::ptree
    - .put_child() trys to add the tree to an existing key in the "this"-ptree 
    - .add_child() adds a new key for the added ptree to the "this"-ptree