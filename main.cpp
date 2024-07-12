#include "ship.h"
#include <iostream>

int main() {
    Ship s1(2,3);
    Pirate p1(3,4);
    Pirate p2(4,10);
    // Pirate p5(7,12);
    // Pirate p3(6,10);
    // Pirate p4(1,12);
    s1.addPirate(&p1);
    s1.addPirate(&p2);
    // s1.addPirate(&p3);
    // s1.addPirate(&p4);
    // s1.addPirate(&p5);
    s1.m_piratesAVL.print();
    std::cout << std::endl;
    
    std::cout << "1" << std::endl;
    s1.removePirate(&p2);
    std::cout << "2" << std::endl;
    // s1.removePirate(&p1);
    std::cout << "3" << std::endl;
    // s1.removePirate(&p5);
    std::cout << "4" << std::endl;
    
    
    


    //int y = s1.get_numOfPirates();
    /*
        std::cout << std::endl;
        std::cout << x << std::endl;
    */
    
    
    

}
