#ifndef EX1_Ship_H
#define EX1_Ship_H

#include "pirate.h"
#include "AVL_Tree.h"

class Ship{
    int m_id;
    int m_cannons;
    int m_numOfPirates;
    int m_amount;
    List<Pirate> m_piratesList;
    AVL_Tree<int,AVL_Tree<int,int>> m_piratesAVL;

public:
    Ship(int id, int cannos);
    int getCannons()const;
    int get_numOfPirates()const;
    int getAmount()const;
    int getRichestPirate()const;
    void removePirate(Pirate* pirate);
    int getPower()const;
    void setAmount(int change);
    void addPirate(Pirate* pirate);
};

#endif //EX3_Ship_H