#include <iostream>

int main()
{
    int a = 50; 
    double value = a; 
    std::cout << "The address of a is " << &a << " with the value " << a << std::endl; 
    std::cout << "The address of value is " << &value << " with the value " << value << std::endl; 

    double type_pun = *(double*)&a;
        // (double*)&a = cast the int pointer to a double pointer 
        // *(...)... = dereference the resulting double pointer to an actual value
        // This is type punning from double to int
    std::cout << "The address of type_pun is " << &type_pun << " with the value " << type_pun << std::endl; 

    // if you want to access the memory address of the int a , you need to do the following
    double & tp_2 = *(double*)&a; 
    std::cout << "The address of tp_2 is " << &tp_2 << " with the value " << tp_2 << std::endl; 
        // Interpret the value behind the allocated memory of a like a double 
    // CAUTION: This might crash in a runtime error, since we try to write 8 bytes (for double instead of 4 for an int) with the dp_2 accessor
    tp_2 = 6.66;
    std::cout << "a is " << a << std::endl;    
}