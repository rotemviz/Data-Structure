#include "pirate.h"

Pirate::Pirate(int id, int coin) : m_id(id),m_coin(coin),m_ship(nullptr),m_ptrShipNode(nullptr){}
void Pirate::setPtrShipNode(Node<Pirate>* ptr){
    m_ptrShipNode = ptr;
}
bool Pirate::setCoin(int change){
    m_coin += change;
}
int Pirate::getCoin()const{
    return m_coin;
}
int Pirate::getId()const{
    return m_id;
}
Node<Pirate>* Pirate::getPtrShipNode()const{
    return m_ptrShipNode;
}

void Pirate::setShip(Ship* ptr){
    m_ship = ptr;
}
Ship* Pirate::getPtrShip()const{
    return m_ship;
}