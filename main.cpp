#include "pirates24b1.h"
#include <iostream>

int main() {
    Ocean o1;
    o1.add_ship(2,4);
    o1.add_pirate(7,2,12);
    o1.add_pirate(3,2,4);
    o1.add_pirate(4,2,10);
    o1.add_pirate(6,2,10);
    o1.add_pirate(1,2,12);
    o1.add_ship(5,7);
    o1.add_pirate(10,5,2);
    o1.add_pirate(12,5,2);
    o1.add_pirate(11,5,2);
    int x = (o1.get_treasure(4)).ans();
    std::cout << x << std::endl;
    o1.update_pirate_treasure(4,5);
    x = (o1.get_treasure(4)).ans();
    std::cout << x << std::endl;
    o1.ships_battle(2,5);
    x = (o1.get_treasure(4)).ans();
    std::cout << x << std::endl;
    
    //int x = (o1.get_richest_pirate(2)).ans();
    //std::cout << x << std::endl;
    //o1.treason(2,5);
    //o1.remove_pirate(1);
    //x = (o1.get_richest_pirate(5)).ans();
    //std::cout << x << std::endl;
    //x = (o1.get_richest_pirate(2)).ans();
    //std::cout << x << std::endl;



    //x = (o1.get_richest_pirate(2)).ans();
    //std::cout << x << std::endl;
    


    /*
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
