//
//  game.hpp
//  AdvancedRPSGame
//
//  Created by Nathan Dilla on 12/9/21.
//

#ifndef game_hpp
#define game_hpp

#include <stdio.h>
#include "player.hpp"
#include "round.hpp"
#include <string>
#include <fstream>
using namespace std;

class Game
{
private:
    Player currentPlayer;
public:
    Game();
    Player getPlayer();
    void begin();
    void newGame();
    int validateInput(int,int);
    void saveGame();
    void loadGame();
    void hub();
    void store();
    void store_weapons();
    void store_clothes();
    void store_inspect(int,int);
    void embark();
    void embark_explore();
    void embark_fight();
    void inventory();
};

#endif /* game_hpp */
