#ifndef UF
#define UF
#include "HashTable.h"
#include "fleet.h"

class UnionFind{
public:

    HashTable<Fleet*> m_fleets;
    HashTable<NodeGroup*> m_groups;

//public:
    bool makeSet(Fleet* givenFleet, NodeGroup* group){
        int id = givenFleet->getID();
        bool check = m_fleets.insert(id,givenFleet);
        if(check){
            m_groups.insert(id,group);
        }
        return check;
    }
    
    //check if group1 and group2 is exits with rootFleet.
    void uniteGroups(NodeGroup* group1, NodeGroup* group2){
        int numOfPiratesGroup1 = group1->getNumOfPirates();
        int numOfPiratesGroup2 = group2->getNumOfPirates();
        Fleet* rootGroup2 = group2->getFleetPtr();
        Fleet* rootGroup1 = group1->getFleetPtr();
        if(numOfPiratesGroup1 >= numOfPiratesGroup2){
            rootGroup2->setExtraRank(numOfPiratesGroup1);
            group1->setNumOfPirates(numOfPiratesGroup2);
            group1->setNumOfShips(group2->getNumOfShips());
            rootGroup2->setNextFleet(rootGroup1);
            rootGroup2->setGroup(nullptr);
            group2->resetRootFleet();
            return;
        }
        rootGroup1->setExtraRank(numOfPiratesGroup2);
        group2->setNumOfPirates(numOfPiratesGroup1);
        group2->setNumOfShips(group1->getNumOfShips());
        rootGroup1->setNextFleet(rootGroup2);
        rootGroup1->setGroup(nullptr);
        group1->resetRootFleet();
    }

    

 

};

#endif //UF