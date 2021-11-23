#include <iostream>

struct MyUnion
{
    union 
    {
        float a; 
        int b; 
    };
}; 

int main()
{   
    MyUnion u;
    u.a = 2.0f; 
    std::cout << "a is " << u.a << ", b is " << u.b << std::endl; 
        // b is the interpretation of the float memory address, threaded as an int (if the read out from the memory is beginning at the same start index)
    std::cout << "address of a is " << &u.a << ", address of b is " << &u.b << std::endl; 
    return 0; 
}