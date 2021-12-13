//
//  enemy.hpp
//  AdvancedRPSGame
//
//  Created by Nathan Dilla on 12/8/21.
//

#ifndef enemy_hpp
#define enemy_hpp

#include <stdio.h>
#include "character.hpp"

class Enemy : public Character
{
private:
    int loot;
    double stealPercentage;
    int rockPntge;
    int scissorsPntge;
    int paperPntge;
public:
    Enemy(string,double,int,int,int);
    Enemy();
    int getLoot();
    double getStealPntge();
    int getRockPntge();
    int getPaperPntge();
    int getScissorsPntge();
    void setStealPntge(double);
    void setRockPntge(double);
    void setPaperPntge(double);
    void setScissorsPntge(double);
    int shoot();
    void taunt();
};

#endif /* enemy_hpp */
