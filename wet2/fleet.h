#ifndef fleet
#define fleet

class Fleet{
    int m_ID;
    Fleet* m_nextFleet;
    int m_extraToRank;
    int m_totalPirates;
    int m_updateId;
    int m_numOfShips;

public:
    Fleet(int id): m_ID(id), m_nextFleet(nullptr), m_extraToRank(0),
                 m_totalPirates(0),m_updateId(id),m_numOfShips(1){}
    void setNextFleet(Fleet* givenFleet){
        m_nextFleet = givenFleet;
    }
    
    Fleet* getNextFleet()const{
        return m_nextFleet;
    }

    void setExtraRank(int num){
        m_extraToRank = num;
    }

    void addExtraRank(int num){
        m_extraToRank += num;
    }
    int getExtraRank()const{
        return m_extraToRank;
    }

    int getID()const{
        return m_ID;
    }

    int getTotalPirates()const{
        return m_totalPirates;
    }

    void setTotalPirates(int numToAdd){
        m_totalPirates += numToAdd;
    }

    int getNumOfShips()const{
        return m_numOfShips;
    }

    void setNumOfShips(int num){
        m_numOfShips += num;

    }
    
    int getUpdateID()const{
        return m_updateId;
    }

    void setUpdateID(int id){
        m_updateId = id;
    }

    bool isEmpty()const{
        return m_totalPirates == 0;
    }
};




#endif
