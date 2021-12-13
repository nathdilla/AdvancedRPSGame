//
//  hand.cpp
//  AdvancedRPSGame
//
//  Created by Nathan Dilla on 12/9/21.
//

#include "hand.hpp"

Hand::Hand(int v)
{
    setValue(v);
}

int Hand::getValue()
{
    return value;
}

string Hand::getType()
{
    return type;
}

string Hand::getBeatenBy()
{
    return beatenBy;
}

string Hand::getDestroyedBy()
{
    return destroyedBy;
}

void Hand::setType(string t)
{
    type=t;
}

void Hand::setBeatenBy(string b)
{
    beatenBy=b;
}

void Hand::setDestroyedBy(string d)
{
    destroyedBy=d;
}

void Hand::setValue(int v)
{
    value=v;
    switch (v)
    {
        case 0:
            setType("forfeit");
            break;
        case 1:
            setType("rock");
            setBeatenBy("paper");
            setDestroyedBy("brick");
            break;
        case 2:
            setType("paper");
            setBeatenBy("scissors");
            setDestroyedBy("pencil");
            break;
        case 3:
            setType("scissors");
            setBeatenBy("rock");
            setDestroyedBy("screwdriver");
            break;
    }
}

