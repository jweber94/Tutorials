#include <iostream>

struct Entity
{
    int x, y; 

    int * GetPosition()
    {
        return &x; 
    }
};

int main()
{
    Entity e = {5, 8}; 

    // Access the Enity entrys like e is an array
    int * array_e = (int*)&e; // cast the Entity struct to an int pointer to access it as an array
    std::cout << "x is: " <<  array_e[0] << ", y is: " << array_e[1] << std::endl; 

    int * pos = e.GetPosition(); 
    pos[1] = 9; 
    // pos[2] = 10; // CAUTION: We are out of the allocated memory (aka stack smashing) 
    std::cout << "y is " << e.y << std::endl; 
    return 0; 
}