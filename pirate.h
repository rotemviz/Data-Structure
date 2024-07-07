#ifndef EX1_Pirate_H
#define EX1_Pirate_H

#include "linkedList.h"
#include "ship.h"

class Pirate{
    int m_id;
    int m_coin;
    Ship* m_ship;
    Node<Pirate>* m_ptrShip;


public:
    Pirate(int id, int coin);
    void setPtrShip(Node<Pirate>* ptr);
    void setShip(Ship* ptr);
    bool setCoin(int change);
    int getCoin() const;
    int getId() const;
    Node<Pirate>* getPtrShip() const;
    
};

#endif //EX3_Pirate_H