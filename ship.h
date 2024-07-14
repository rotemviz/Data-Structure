#ifndef EX1_Ship_H
#define EX1_Ship_H
//#include "linkedList.h"
#include "pirate.h"
#include "AVL_Tree.h"
class Pirate;
class Ship{
//public:    
    int m_id;
    int m_cannons;
    int m_numOfPirates;
    int m_amount;
    int m_richestPirateId;
    int m_richestPirateCoins;
    List<Pirate> m_piratesList;
    AVL_Tree<int,AVL_Tree<int,int>*> m_piratesAVL;

public:
    Ship(int id, int cannos);
    ~Ship();
    int getCannons()const;
    int get_numOfPirates()const;
    int getAmount()const;
    int getRichestPirate()const;
    void removePirate(Pirate* pirate);
    void removePirateAVL(Pirate* pirate);
    int getPower()const;
    void setAmount(int change);
    void addPirate(Pirate* pirate);
    void addPirateAVL(Pirate* pirate);
    bool isEmpty()const;
    int getPirateID()const;
};

#endif //EX3_Ship_H

