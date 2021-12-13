//
//  hand.hpp
//  AdvancedRPSGame
//
//  Created by Nathan Dilla on 12/9/21.
//

#ifndef hand_hpp
#define hand_hpp

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class Hand
{
private:
    int value = 1; // 1. rock, 2. paper, 3. scissors
    string type;
    string beatenBy;
    string destroyedBy;
public:
    Hand(int v);
    int getValue();
    string getType();
    string getBeatenBy();
    string getDestroyedBy();
    void setValue(int);
    void setType(string);
    void setBeatenBy(string);
    void setDestroyedBy(string);
};

#endif /* hand_hpp */
