//
//  character.cpp
//  AdvancedRPSGame
//
//  Created by Nathan Dilla on 12/8/21.
//

#include "character.hpp"

string Character::getName()
{
    return name;
}

vector<item *> Character::getBackpack()
{
    return backpack;
}

void Character::setName(string s)
{
    name=s;
}

void Character::addToBackpack(item * i)
{
    backpack.push_back(i);
}

item* Character::getItem(int i)
{
    return backpack.at(i);
}

item*Character::getItem(string type)
{
    for(int i=0;i<backpack.size();i++)
    {
        if(backpack.at(i)->getName()==type)
        {
            return backpack.at(i);
        }
    }
    return NULL;
}
