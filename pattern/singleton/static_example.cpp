#include <iostream>


void counter() {
    static int j = 0;
    std::cout << "j is " << j << std::endl;
    j++;
}

int main() {
    for (int i = 0; i < 5; i++) {
        counter();
    }
    return 1;
}