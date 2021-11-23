#include <iostream>

struct Vec2
{
    float x, y; 
}; 

struct Vec4
{
    union 
    {
        // anonymous union to not define a concrete instance, since the instance should be Vec4
        struct 
        {
            // anonymous struct of floats to access the data
            float x, y, z, w; 
        };
        struct 
        {
            // anonymous struct of Vec2 to access the data
            Vec2 a, b; 
        }; 
    };
}; 

void PrintVec2(const Vec2 & vec)
{
    std::cout << vec.x << ", " << vec.y << std::endl; 
}

int main()
{
    Vec4 my_vec{1.f, 2.f, 3.f, 4.f}; 
    
    // we can access the data (behind the memory addresses) as the vector or as the float representation by the union 
    PrintVec2(my_vec.a); 
    PrintVec2(my_vec.b);  
    my_vec.w = 500.f; 
    my_vec.b.x = 22.2; 
    std::cout << "-------------------" << std::endl; 
    PrintVec2(my_vec.a); 
    PrintVec2(my_vec.b);

    return 0; 
}