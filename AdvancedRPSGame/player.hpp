//
//  player.hpp
//  AdvancedRPSGame
//
//  Created by Nathan Dilla on 12/8/21.
//

#ifndef player_hpp
#define player_hpp

#include <stdio.h>
#include "character.hpp"

class Player : public Character
{
private:
    int money;
    int exp;
    int zone1progress=0;
    int zone2progress=0;
    int zone3progress=0;
    int zone4progress=0;
public:
    Player(string,int,int);
    Player();
    int getMoney();
    int getExp();
    int getZone1Progress();
    int getZone2Progress();
    int getZone3Progress();
    int getZone4Progress();
    void setZone1Progress(int p);
    void setZone2Progress(int p);
    void setZone3Progress(int p);
    void setZone4Progress(int p);
    void setMoney(int);
    void setExp(int);
    int shoot();
    void taunt();
    item* numToWeapon(int shot);
};

#endif /* player_hpp */
