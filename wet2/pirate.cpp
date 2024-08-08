#include "pirate.h"

Pirate::Pirate(int id, Fleet* givenFleet, int rank) : m_id(id),m_coin(0),m_rank(rank),m_fleet(givenFleet){}
void Pirate::setCoin(int change){
    m_coin += change;
}
int Pirate::getCoin()const{
    return m_coin;
}
int Pirate::getId()const{
    return m_id;
}

int Pirate::getRank()const{
    return m_rank;
}

void Pirate::setRank(int rank){
    m_rank = rank;
}

Fleet* Pirate::getPtrFleet()const{
    return m_fleet;
}
