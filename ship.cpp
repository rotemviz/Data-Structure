#include "ship.h"

int min(int a, int b){
    return a > b? b : a;
}

Ship::Ship(int id, int cannos):m_id(id),m_cannons(cannos),m_numOfPirates(0),m_amount(0)
                ,m_piratesList(),m_piratesAVL(){}

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
    AVL_Tree<int,int>& temp = m_piratesAVL.getFarRight();
    int richestPirate = temp.getFarRight();
    return richestPirate;
}
void Ship::removePirate(Pirate* pirate){
    int id = pirate->getId();
    int treasure = pirate->getCoin();
    m_piratesList.remove(pirate->getPtrShipNode());
    AVL_Tree<int,int>* temp = this->m_piratesAVL.getData(treasure);
    temp->remove(id);
    if(temp->isEmpty()){
        m_piratesAVL.remove(treasure);
    }
    m_numOfPirates--;
}

int Ship::getPower()const{
    return min(m_cannons,m_numOfPirates);
}

void Ship::setAmount(int change){
    m_amount += change;
}

void Ship::addPirate(Pirate* pirate){
    int id = pirate->getId();
    pirate->setCoin(-(m_amount));
    int treasure = pirate->getCoin();
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
    m_piratesAVL.insert(pirate->getCoin(),newTree);
    m_numOfPirates++;
    //copy ctor operator==
}