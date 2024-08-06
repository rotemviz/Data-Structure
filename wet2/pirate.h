#ifndef EX1_Pirate_H
#define EX1_Pirate_H

#include "fleet.h"

class Pirate {
    
    int m_id;
    int m_coin;
    int m_rank;
    Fleet* m_fleet;

public:
    Pirate(int id, Fleet* givenFleet, int rank);
    void setCoin(int change);
    int getCoin() const;
    int getId() const;
    int getRank()const;
    void setRank(int rank)const;
    Fleet* getPtrFleet() const;
};

#endif //EX3_Pirate_H