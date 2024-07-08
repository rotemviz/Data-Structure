#ifndef EX1_Pirate_H
#define EX1_Pirate_H

#include "linkedList.h"
#include "ship.h"

class Pirate{
    int m_id;
    int m_coin;
    Ship* m_ship;
    Node<Pirate>* m_ptrShipNode;


public:
    Pirate(int id, int coin);
    void setPtrShipNode(Node<Pirate>* ptr);
    void setShip(Ship* ptr);
    bool setCoin(int change);
    int getCoin() const;
    int getId() const;
    Node<Pirate>* getPtrShipNode() const;
    Ship* getPtrShip()const;
    
};

#endif //EX3_Pirate_H