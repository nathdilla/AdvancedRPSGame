//
//  round.hpp
//  AdvancedRPSGame
//
//  Created by Nathan Dilla on 12/8/21.
//

#ifndef round_hpp
#define round_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include "player.hpp"
#include "enemy.hpp"
#include "hand.hpp"
#include "game.hpp"
using namespace std;

class Round{
private:
    int playerLife=3;
    int enemyLife=3;
    int zone;
    Enemy enemy;
public:
    Round();
    Round(int);
    void setEnemyLife(int);
    void play(Player &player);
    Enemy generateEnemy(int);
};

#endif /* round_hpp */
