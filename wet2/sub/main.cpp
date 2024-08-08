#include <iostream>
#include "UnionFind.h"


int main() {
    UnionFind uf;

    
    Fleet f1(1);
    Fleet f2(2);
    Fleet f3(3);
    Fleet f4(4);
    Fleet f5(5);
    Fleet f6(6);
    Fleet f7(7);
    f1.setTotalPirates(3);
    f2.setTotalPirates(5);
    f3.setTotalPirates(1);
    f4.setTotalPirates(100);
    f5.setTotalPirates(10);
    uf.makeSet(&f1);
    uf.makeSet(&f2);
    uf.makeSet(&f3);
    uf.makeSet(&f4);
    uf.makeSet(&f5);
    uf.makeSet(&f6);
    uf.makeSet(&f7);
    uf.uniteGroups(&f2,&f1);
    uf.uniteGroups(&f2,&f3);
    uf.uniteGroups(&f4,&f5);
    uf.uniteGroups(&f4,&f2);
    Fleet* check = uf.find(1);
    Fleet* check1 = uf.find(3);

    std::cout << check << std::endl;

    bool lala = (check == check1);
    std::cout << lala << std::endl;
    int id = check->getUpdateID();
    std::cout << id << std::endl;
    int x = f4.getExtraRank();
    std::cout << x << std::endl;
    
    



    // int x = .getNumOfShips();
    // int y = grp1.getNumOfPirates();
    // int z = f2.getExtraRank();
    // bool check = (f2.getNextFleet() == &f1);
    // std::cout << x << std::endl;
    // std::cout << y << std::endl;
    // std::cout << z << std::endl;
    // std::cout << check << std::endl;
}