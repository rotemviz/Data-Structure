#ifndef EX1_Pirate_H
#define EX1_Pirate_H

#include "linkedList.h"

class Pirate{
    int m_id;
    int m_coin;
    Node<Pirate>* m_ptrShip;

public:
    Pirate(int id, int coin) : m_id(id),m_coin(coin),m_ptrShip(nullptr){}
    void setPtrShip(Node<Pirate>* ptr){
        m_ptrShip = ptr;
    }
    bool setCoin(int change){
        m_coin += change;
    }
    int getCoin()const{
        return m_coin;
    }
    int getId()const{
        return m_id;
    }
    Node<Pirate>* getPtrShip()const{
        return m_ptrShip;
    }
    //check;
};

#endif //EX3_Pirate_H