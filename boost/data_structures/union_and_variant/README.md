# Unions
+ Unions can be implemented like structs by defining member methods for them. Also you can tell a union to have more then one members. The difference between a struct and a union is that the allocated and addressed memory by all member variables is the same in a union!
    - You can not define virtual and pure virtual methods!
    - If you have a struct 
+ Unions are used to do implicit type punning!
+ Unions are C++ standart keywords (NO INCLUDES NECESSARY)
+ Unions are used to realize CHOICE definitons in ASN.1 coded data

## Type Punning
+ By type punning we mean to work around the type safty of C++ 
+ Since you can access memory addresses directly in C++, you can get around the type system easily 
+ CAUTION: Please do type punning only if you really need to do this!
+ Idea behind it: 
    - Get the data in the memory and do what the f... you want with it ;-) 
    - Access memoryaddresses and interpret the bytes like you need to
+ Realization strategy: 
    - Take a pointer from an instance, cast its pointer to a different type of pointer and therefore the memory will get interpreted as the new type

# References
+ https://www.youtube.com/watch?v=6uqU9Y578n4
+ https://dieboostcppbibliotheken.de/boost.variant