#ifndef EX1_Pirate_H
#define EX1_Pirate_H

#include "linkedList.h"

class Pirate{
    int m_id;
    int m_coin;
    Node<Pirate>* m_ptrShip;

public:
    Pirate(int id, int coin);
    void setPtrShip(Node<Pirate>* ptr);
    bool setCoin(int change);
    int getCoin() const;
    int getId() const;
    Node<Pirate>* getPtrShip() const;
    
};

#endif //EX3_Pirate_H