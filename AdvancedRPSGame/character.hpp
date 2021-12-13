//
//  character.hpp
//  AdvancedRPSGame
//
//  Created by Nathan Dilla on 12/8/21.
//

#ifndef character_hpp
#define character_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include "item.hpp"
using namespace std;

class Character
{
private:
    string name;
    vector<item *> backpack;
public:
    string getName();
    vector<item*> getBackpack();
    item* getItem(int);
    item* getItem(string);
    void setName(string);
    virtual int shoot()=0;
    virtual void taunt()=0;
    void addToBackpack(item *);
    void toString();
};


#endif /* character_hpp */
