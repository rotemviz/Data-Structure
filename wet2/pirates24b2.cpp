#include "pirates24b2.h"
#include <iostream>

oceans_t::oceans_t()
{
	
}

oceans_t::~oceans_t()
{
	
}


StatusType oceans_t::add_fleet(int fleetId)
{
	if(fleetId <= 0){
		return StatusType::INVALID_INPUT;
	}
	Fleet* fleetToInsert = nullptr;
	try{
		fleetToInsert = new Fleet(fleetId);
	}
	catch(...){
		return StatusType::ALLOCATION_ERROR;
	}
	bool check = m_fleets.makeSet(fleetToInsert);
	if(!check){
		delete fleetToInsert;
	}
	return check ? StatusType::SUCCESS : StatusType::FAILURE;
}

StatusType oceans_t::add_pirate(int pirateId, int fleetId)
{
	if(pirateId <= 0 || fleetId <= 0){
		return StatusType::INVALID_INPUT;
	}
	Node<Pirate*>* check = m_pirates.find(pirateId);
	Fleet* root = m_fleets.find(fleetId);
	if(check || !root || root->getUpdateID() != fleetId){
		return StatusType::FAILURE;
	}
	Pirate* pirate = nullptr;
	int rank = root->getTotalPirates();
	try{
		pirate = new Pirate(pirateId,root,rank+1);
		m_pirates.insert(pirateId,pirate);
		root->setTotalPirates(1);
	}
	catch(...){
		return StatusType::ALLOCATION_ERROR;
	}
	return StatusType::SUCCESS;
}

StatusType oceans_t::pay_pirate(int pirateId, int salary)
{
	if(pirateId <= 0 || salary <= 0){
		return StatusType::INVALID_INPUT;
	}
	Node<Pirate*>* check =  m_pirates.find(pirateId);
	if(!check){
		return StatusType::FAILURE;
	}
	Pirate* pirate = check->getData();
	pirate->setCoin(salary);
	return StatusType::SUCCESS;
}

output_t<int> oceans_t::num_ships_for_fleet(int fleetId)
{
    if(fleetId <= 0){
		return output_t<int>(StatusType::INVALID_INPUT);
	}
	Fleet* check = m_fleets.find(fleetId);
	if(!check || check->getUpdateID() != fleetId){
		return output_t<int>(StatusType::FAILURE);
	}
	int numOfShip = check->getNumOfShips();
    return output_t<int>(numOfShip);
}

output_t<int> oceans_t::get_pirate_money(int pirateId)
{
    if(pirateId <= 0){
		return output_t<int>(StatusType::INVALID_INPUT);
	}
	Node<Pirate*>* check =  m_pirates.find(pirateId);
	if(!check){
		return output_t<int>(StatusType::FAILURE);
	}
	Pirate* pirate = check->getData();
	int coins = pirate->getCoin();
	return output_t<int>(coins);
}

StatusType oceans_t::unite_fleets(int fleetId1, int fleetId2)
{
	if(fleetId1 <= 0 || fleetId2 <= 0 || fleetId1 == fleetId2){
		return StatusType::INVALID_INPUT;
	}
	Fleet* check1 = m_fleets.find(fleetId1);
	Fleet* check2 = m_fleets.find(fleetId2);
	if(!check1 || !check2){
		//std::cout << "not found" << std::endl;
		return StatusType::FAILURE;
	}
	int updateID1 = check1->getUpdateID();
	int updateID2 = check2->getUpdateID();
	if(updateID1 != fleetId1 || updateID2 != fleetId2 || check1->isEmpty() || check2->isEmpty()){
		//std::cout << "PROBLEM WITH UPDATEID" << std::endl;
		return StatusType::FAILURE;
	}
	m_fleets.uniteGroups(check1,check2);
    return StatusType::SUCCESS;
}

StatusType oceans_t::pirate_argument(int pirateId1, int pirateId2)
{
    if(pirateId1 <= 0 || pirateId2 <= 0 || pirateId1 == pirateId2){
		return StatusType::INVALID_INPUT;
	}
	Node<Pirate*>* check1 = m_pirates.find(pirateId1);
	Node<Pirate*>* check2 = m_pirates.find(pirateId2);
	if(!check1 || !check2){
		return StatusType::FAILURE;
	}
	Pirate* pirate1 = check1->getData();
	Pirate* pirate2 = check2->getData();
	Fleet* origin_fleet1 = pirate1->getPtrFleet();
	Fleet* origin_fleet2 = pirate2->getPtrFleet();
	Fleet* fleet1 = m_fleets.find(origin_fleet1->getID());
	Fleet* fleet2 = m_fleets.find(origin_fleet2->getID());
	if(fleet1 != fleet2){
		return StatusType::FAILURE;
	}
	int rank1 = pirate1->getRank() + m_fleets.getRankExtra(origin_fleet1);
	int rank2 = pirate2->getRank() + m_fleets.getRankExtra(origin_fleet2);
	int payment = 0;
	if(rank1 > rank2){
		payment = rank1-rank2;
		pirate2->setCoin(payment);
		pirate1->setCoin(-payment);
	}
	else{
		payment = rank2 - rank1;
		pirate1->setCoin(payment);
		pirate2->setCoin(-payment);
	}
    return StatusType::SUCCESS;
}


