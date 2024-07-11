#include "ship.h"
#include <iostream>

int main() {
    Ship s1(2,3);
    int x = s1.getCannons();
    std::cout << x << std::endl;
    Pirate p1(3,10);
    Pirate p2(4,10);
    Pirate p5(7,12);
    Pirate p3(6,10);
    Pirate p4(1,12);
    s1.addPirate(&p1);
    s1.addPirate(&p2);
    s1.addPirate(&p3);
    s1.addPirate(&p4);
    s1.addPirate(&p5);
    s1.removePirate(&p1);
    s1.removePirate(&p2);
    // s1.removePirate(&p3);
    s1.removePirate(&p5);
    s1.removePirateAVL(&p3);
    s1.addPirateAVL(&p3);
    s1.m_piratesAVL.print();

    x = s1.getRichestPirate();
    //int y = s1.get_numOfPirates();
    std::cout << std::endl;
    std::cout << x << std::endl;
    
    

}
