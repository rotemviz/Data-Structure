#include "pirate.h"

Pirate::Pirate(int id, int coin) : m_id(id),m_coin(coin),m_ptrShip(nullptr){}
void Pirate::setPtrShip(Node<Pirate>* ptr){
    m_ptrShip = ptr;
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
Node<Pirate>* Pirate::getPtrShip()const{
    return m_ptrShip;
}