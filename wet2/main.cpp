#include <iostream>
#include "UnionFind.h"


int main() {
    UnionFind uf;
    NodeGroup grp1(20);
    NodeGroup grp2(12);
    Fleet f1(20,&grp1);
    Fleet f2(12,&grp2);
    grp1.setRootFleet(&f1);
    grp2.setRootFleet(&f2);
    uf.makeSet(&f1,&grp1);
    uf.makeSet(&f2,&grp2);
    uf.uniteGroups(&grp1,&grp2);
    int x = grp1.getNumOfShips();
    int y = grp1.getNumOfPirates();
    int z = f2.getExtraRank();
    bool check = (f2.getNextFleet() == &f1);
    std::cout << x << std::endl;
    std::cout << y << std::endl;
    std::cout << z << std::endl;
    std::cout << check << std::endl;


    

    
}