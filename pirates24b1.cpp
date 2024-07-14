#include "pirates24b1.h"
#include "ship.h"


static const int MIN_ID = 1;
static const int MIN_CANNONS = 0;

Ocean::Ocean():m_pirates(),m_ships(){}

Ocean::~Ocean(){
    this->m_pirates.deleteData(m_pirates.getRoot());
    this->m_ships.deleteData(m_ships.getRoot());
}

StatusType Ocean::add_ship(int shipId, int cannons){
    if(shipId < MIN_ID || cannons < MIN_CANNONS){
        return StatusType::INVALID_INPUT;
    }
    Ship** check = m_ships.getData(shipId);
    if(check && (*check)){
        return StatusType::FAILURE;
    }
    Ship* newShip = nullptr;
    try{
        newShip = new Ship(shipId,cannons);
        m_ships.insert(shipId,newShip); 
    }
    catch(...){
        if(newShip){
            delete newShip;
        }
        return StatusType::ALLOCATION_ERROR;
    }
    return StatusType::SUCCESS;
}

StatusType Ocean::remove_ship(int shipId)
{
    if(shipId < MIN_ID){
        return StatusType::INVALID_INPUT;
    }
    Ship** check = m_ships.getData(shipId);
    if(!check ||!(*check) || !(*check)->isEmpty()){
        return StatusType::FAILURE;
    }
    delete (*check);
    m_ships.remove(shipId);
    return StatusType::SUCCESS;
}

StatusType Ocean::add_pirate(int pirateId, int shipId, int treasure)
{
    if(shipId < MIN_ID || pirateId < MIN_ID){
        return StatusType::INVALID_INPUT;
    }
    Pirate** checkPirate = m_pirates.getData(pirateId);

    Ship** checkShip = m_ships.getData(shipId);

    if(!checkShip || !(*checkShip) || (checkPirate && (*checkPirate))){
        return StatusType::FAILURE;
    }
    Pirate* newPirate = nullptr;
    try{
        newPirate = new Pirate(pirateId,treasure);
        m_pirates.insert(pirateId,newPirate);
        (*checkShip)->addPirate(newPirate);
    }
    catch(...){
        if(newPirate){
            delete newPirate;
        }
        return StatusType::ALLOCATION_ERROR;
    }
    return StatusType::SUCCESS;
}

StatusType Ocean::remove_pirate(int pirateId)
{
    if(pirateId < MIN_ID){
        return StatusType::INVALID_INPUT;
    }
    Pirate** check = m_pirates.getData(pirateId);
     if(!check ||!(*check)){
        return StatusType::FAILURE;
    }
    Ship* ship = (*check)->getPtrShip();
    ship->removePirate((*check));
    delete (*check);
    m_pirates.remove(pirateId);
    return StatusType::SUCCESS;
}

StatusType Ocean::treason(int sourceShipId, int destShipId)
{
    if(destShipId < MIN_ID || sourceShipId < MIN_ID || destShipId == sourceShipId){
        return StatusType::INVALID_INPUT;
    }
    Ship** checkShipDest = m_ships.getData(destShipId);
    Ship** checkShipSource = m_ships.getData(sourceShipId);
    if(!checkShipDest || !(*checkShipDest) || !checkShipSource || !(*checkShipSource) || (*checkShipSource)->isEmpty()){
        return StatusType::FAILURE;
    }
    int pirateId = (*checkShipSource)->getPirateID();
    Pirate** pirateToMove = m_pirates.getData(pirateId);
    Pirate* pirate = *pirateToMove;
    pirate->setCoin((*checkShipSource)->getAmount());
    (*checkShipSource)->removePirate(pirate);
    (*checkShipDest)->addPirate(pirate);
    return StatusType::SUCCESS;
}

StatusType Ocean::update_pirate_treasure(int pirateId, int change)
{
    if(pirateId < MIN_ID){
        return StatusType::INVALID_INPUT;
    }
    Pirate** check = m_pirates.getData(pirateId);
    if(!check ||!(*check)){
        return StatusType::FAILURE;
    }
    Ship* pirateShip = (*check)->getPtrShip();
    pirateShip->removePirateAVL(*check);
    (*check)->setCoin(pirateShip->getAmount() + change);
    pirateShip->addPirateAVL(*check);
    return StatusType::SUCCESS;
}

output_t<int> Ocean::get_treasure(int pirateId)
{
    if(pirateId < MIN_ID){
        return output_t<int>(StatusType::INVALID_INPUT);
    }
    Pirate** check = m_pirates.getData(pirateId);
    if(!check ||!(*check)){
        return output_t<int>(StatusType::FAILURE);
    }
    Pirate* pirate = *check;
    int temp = pirate->getCoin();
    int treasure = temp + (pirate->getPtrShip())->getAmount();
    return output_t<int>(treasure);
}

output_t<int> Ocean::get_cannons(int shipId)
{
    if(shipId < MIN_ID){
        return output_t<int>(StatusType::INVALID_INPUT);
    }
    Ship** check = m_ships.getData(shipId);
    if(!check ||!(*check)){
        return output_t<int>(StatusType::FAILURE);
    }
    Ship* ship = *check;
    int numOfCannons = ship->getCannons();
    return output_t<int>(numOfCannons);
}

output_t<int> Ocean::get_richest_pirate(int shipId)
{
    if(shipId < MIN_ID){
        return output_t<int>(StatusType::INVALID_INPUT);
    }
    Ship** check = m_ships.getData(shipId);
    if(!check ||!(*check)|| (*check)->isEmpty()){
        return output_t<int>(StatusType::FAILURE);
    }
    int richestId = (*check)->getRichestPirate();
    return output_t<int>(richestId);
    
}

StatusType Ocean::ships_battle(int shipId1,int shipId2)
{
    if(shipId1 < MIN_ID || shipId2 < MIN_ID || shipId1 == shipId2){
        return StatusType::INVALID_INPUT;
    }
    Ship** ship1 = m_ships.getData(shipId1);
    Ship** ship2 = m_ships.getData(shipId2);
    if(!ship1 || !(*ship1) || !ship2 || !(*ship2)){
        return StatusType::FAILURE;
    }
    int power1 = (*ship1)->getPower();
    int power2 = (*ship2)->getPower();
    if(power1 > power2){
        (*ship1)->setAmount((*ship2)->get_numOfPirates());
        (*ship2)->setAmount(-((*ship1)->get_numOfPirates()));
    }
    else if(power2 > power1){
        (*ship1)->setAmount(-((*ship2)->get_numOfPirates()));
        (*ship2)->setAmount((*ship1)->get_numOfPirates());
    }
    
    return StatusType::SUCCESS;
}



