//
//  enemy.cpp
//  AdvancedRPSGame
//
//  Created by Nathan Dilla on 12/8/21.
//

#include "enemy.hpp"
#include <algorithm>

Enemy::Enemy()
{}

Enemy::Enemy(string n,double s,int r,int p,int l)
{
    setName(n);
    stealPercentage=s;
    rockPntge=r;
    paperPntge=p;
    loot=l;
}

double Enemy::getStealPntge()
{
    return stealPercentage;
}

int Enemy::getLoot()
{
    return loot;
}

int Enemy::shoot()
{
    srand(time(0));
    int random=rand()%100;
    
    if(random<rockPntge)
    {
        return 1;
    }
    else if(rockPntge<random&&random<paperPntge)
    {
        return 2;
    }
    else if(paperPntge<random&&random<100)
    {
        return 3;
    }
    return 1;
}

void Enemy::taunt()
{
    cout<<"\n\n"<<getName()<<" says: YOU WILL DIEEEEEE!\n";
}
