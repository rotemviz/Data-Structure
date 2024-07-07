#ifndef EX1_Ship_H
#define EX1_Ship_H

#include "pirate.h"
#include "AVL_Tree.h"

class Ship{
    int m_id;
    int m_cannons;
    int m_numOfPirates;
    int m_ammount;
    List<Pirate> m_piratesList;
    AVL_Tree<int,AVL_Tree<int,int>> m_piratesAVL;
    
    



};

#endif //EX3_Ship_H