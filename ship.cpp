#include "ship.h"

int min(int a, int b){
    return a > b? b : a;
}

Ship::Ship(int id, int cannos) : m_id(id), m_cannons(cannos), m_numOfPirates(0), m_amount(0), m_richestPirateId(0), m_richestPirateCoins(0) {}

int Ship::getCannons()const{
    return m_cannons;
}
int Ship::get_numOfPirates()const{
    return m_numOfPirates;
}
int Ship::getAmount()const{
    return m_amount;
}
int Ship::getRichestPirate()const{
    return m_richestPirateId;
}
void Ship::removePirate(Pirate* pirate){
    int id = pirate->getId();
    int treasure = pirate->getCoin();
    m_piratesList.remove(pirate->getPtrShipNode());
    AVL_Tree<int,int>* temp = m_piratesAVL.getData(treasure);
    temp->remove(id);
    m_numOfPirates--;
    if(temp->isEmpty()){
        m_piratesAVL.remove(treasure);
        if(m_piratesAVL.isEmpty()) {
            m_richestPirateCoins = 0;
            m_richestPirateId = 0;
        }
        return;
    }
    if(m_richestPirateId == id) {
        m_richestPirateCoins = m_piratesAVL.getFarRightKey();
        temp = m_piratesAVL.getData(m_richestPirateCoins);
        m_richestPirateId = temp->getFarRightKey();
    }
}

int Ship::getPower()const{
    return min(m_cannons, m_numOfPirates);
}

void Ship::setAmount(int change){
    m_amount += change;
}

void Ship::addPirate(Pirate* pirate){
    int id = pirate->getId();
    pirate->setCoin(-(m_amount));
    int treasure = pirate->getCoin();
    if(treasure > m_richestPirateCoins) {
        m_richestPirateCoins = treasure;
        m_richestPirateId = id;
    }
    if(treasure == m_richestPirateCoins && id > m_richestPirateId) {
        m_richestPirateId = id;
    }
    m_piratesList.insert(*pirate);
    pirate->setPtrShipNode(m_piratesList.ptrToTail());
    pirate->setShip(this);
    AVL_Tree<int,int>* temp = m_piratesAVL.getData(treasure);
    if(temp){
        temp->insert(id,id);
        m_numOfPirates++;
        return;
    }
    AVL_Tree<int,int> newTree;
    newTree.insert(id,id);
    m_piratesAVL.insert(treasure,newTree);
    m_numOfPirates++;
    //copy ctor operator==
}

bool Ship::isEmpty()const{
    return m_numOfPirates == 0;
}

