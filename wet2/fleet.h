#ifndef fleet
#define fleet

class Fleet;
class NodeGroup{
    int m_ID;
    int m_numOfPirates;
    int m_numOfShips;
    Fleet* m_rootFleet;

public:
    NodeGroup(int id): m_ID(id), m_numOfPirates(0), m_numOfShips(1), m_rootFleet(nullptr){};

    void setNumOfPirates(int numPirates){
        m_numOfPirates += numPirates;
    }

    int getNumOfPirates()const{
        return m_numOfPirates;
    }
    int getNumOfShips()const{
        return m_numOfShips;
    }
    Fleet* getFleetPtr()const{
        return m_rootFleet;
    }

    void resetRootFleet(){
        m_rootFleet = nullptr;
    }

    void setRootFleet(Fleet* givenFleet){
        m_rootFleet = givenFleet;
    }

    void setNumOfShips(int num){
        m_numOfShips += num;

    }

};

class Fleet{
    int m_ID;
    Fleet* m_nextFleet;
    NodeGroup* m_group;
    int m_extraToRank;

public:
    Fleet(int id, NodeGroup* group): m_ID(id), m_nextFleet(nullptr), m_group(group), m_extraToRank(0){}
    void setNextFleet(Fleet* givenFleet){
        m_nextFleet = givenFleet;
    }
    
    void setGroup(NodeGroup* group){
        m_group = group;
    }

    Fleet* getNextFleet()const{
        return m_nextFleet;
    }
    
    NodeGroup* getGroup()const{
        return m_group;
    }

    void setExtraRank(int num){
        m_extraToRank = num;
    }
    int getExtraRank()const{
        return m_extraToRank;
    }

    int getID()const{
        return m_ID;
    }

    
};




#endif
