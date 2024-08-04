#include <iostream>
#include "Array.h"

int main() {
    
    Array<int> arr(5, -1);
    arr.store(0,3);
    arr.store(1,2);
    
    int x = arr.get(0);
    int y = arr.get(1);

    std::cout << x << std::endl << y << std::endl << arr.get(4) << std::endl;


    
}