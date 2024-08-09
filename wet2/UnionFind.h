#ifndef UF
#define UF
#include "HashTable.h"
#include "fleet.h"

class UnionFind{
public:

    HashTable<Fleet*> m_fleets;

    bool makeSet(Fleet* givenFleet){
        int id = givenFleet->getID();
        return m_fleets.insert(id,givenFleet);
    }
    
    //check if group1 and group2 is exits with rootFleet.
    void uniteGroups(Fleet* group1, Fleet* group2){
        int numOfPiratesGroup1 = group1->getTotalPirates();
        int numOfPiratesGroup2 = group2->getTotalPirates();
        int numOfShipGroup1 = group1->getNumOfShips();
        int numOfShipGroup2 = group2->getNumOfShips();

        if(numOfPiratesGroup1 >= numOfPiratesGroup2){
            if(numOfShipGroup1 >= numOfShipGroup2){
                group2->addExtraRank(group1->getTotalPirates() - group1->getExtraRank());
                group1->setTotalPirates(numOfPiratesGroup2);
                group2->setNextFleet(group1);
                group1->setNumOfShips(numOfShipGroup2);
            }
            else{
                group2->addExtraRank(numOfPiratesGroup1);
                group1->addExtraRank(-(group2->getExtraRank()));
                group2->setTotalPirates(numOfPiratesGroup1);
                group1->setNextFleet(group2);
                group2->setNumOfShips(numOfShipGroup1);
                group2->setUpdateID(group1->getUpdateID());
            }
        }
        else{
            if(numOfShipGroup2 >= numOfShipGroup1){
                group1->addExtraRank(group2->getTotalPirates() - group2->getExtraRank());
                group2->setTotalPirates(numOfPiratesGroup1);
                group1->setNextFleet(group2);
                group2->setNumOfShips(numOfShipGroup1);
            }
            else{
                group1->addExtraRank(numOfPiratesGroup2);
                group2->addExtraRank(-(group1->getExtraRank()));
                group1->setTotalPirates(numOfPiratesGroup2);
                group2->setNextFleet(group1);
                group1->setNumOfShips(numOfShipGroup2);
                group1->setUpdateID(group2->getUpdateID());
            }
        }
    }

    Fleet* find(int id){
        Node<Fleet*>* fleetNode = m_fleets.find(id);
        if(!fleetNode){
            return nullptr;
        }
        int sum = 0;
        Fleet* temp = fleetNode->getData();
        Fleet* root = temp;
        if(temp->getNextFleet() != nullptr){
            while((temp->getNextFleet())->getNextFleet() != nullptr){
                sum += temp->getExtraRank();
                temp = temp->getNextFleet();
            }
            sum += temp->getExtraRank();
            root = temp->getNextFleet();
        }

        temp = fleetNode->getData();
        Fleet* tempNext = temp->getNextFleet();
        while(tempNext != root && tempNext != nullptr){
            temp->setNextFleet(root);
            int subNum = temp->getExtraRank();
            temp->setExtraRank(sum);
            sum -= subNum;
            temp = tempNext;
            tempNext = tempNext->getNextFleet();
        }
        return root;
    }

    int getRankExtra(Fleet* givenFleet)const{
        int sum = 0;
        while(givenFleet != nullptr){
            sum += givenFleet->getExtraRank();
            givenFleet = givenFleet->getNextFleet();
        }
        return sum;
    }

};

#endif //UF

