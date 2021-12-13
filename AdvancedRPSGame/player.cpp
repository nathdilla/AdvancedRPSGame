//
//  player.cpp
//  AdvancedRPSGame
//
//  Created by Nathan Dilla on 12/8/21.
//

#include "player.hpp"

Player::Player(){}

Player::Player(string n, int m, int e)
{
    setName(n);
    money=m;
    exp=e;
    
    item * i;
    i=new item("rock",15,"Weapon", "Upon the right hand- is a rock. Pointed edges and rough faces appear all over..");
    addToBackpack(i);
    i=new item("paper",15,"Weapon", "In the left hand, there appears to be a sheet of paper. The paper appears thin and razor sharp.");
    addToBackpack(i);
    i=new item("scissors",15,"Weapon","On their back are scissors, capable of cutting through any sheet. They sparkle in the presence of the sunlight..");
    addToBackpack(i);
}

int Player::getMoney()
{
    return money;
}

int Player::getExp()
{
    return exp;
}

int Player::getZone1Progress()
{
    return zone1progress;
}

int Player::getZone2Progress()
{
    return zone2progress;
}

int Player::getZone3Progress()
{
    return zone3progress;
}

int Player::getZone4Progress()
{
    return zone4progress;
}

void Player::setMoney(int m)
{
    money=m;
}

void Player::setExp(int e)
{
    exp=e;
}

void Player::setZone1Progress(int p)
{
    zone1progress=p;
}

void Player::setZone2Progress(int p)
{
    zone2progress=p;
}

void Player::setZone3Progress(int p)
{
    zone3progress=p;
}

void Player::setZone4Progress(int p)
{
    zone4progress=p;
}

item* Player::numToWeapon(int shot)
{
    item*itemptr;
    switch (shot)
    {
        case 1:
            itemptr=getItem("rock");
            break;
        case 2:
            itemptr=getItem("paper");
            break;
        case 3:
            itemptr=getItem("scissors");
            break;
        default:
            itemptr=NULL;
    }
    return itemptr;
}

int Player::shoot()
{
    item*itemptr;
    
    int rockAmt=0;
    int paperAmt=0;
    int scissorsAmt=0;
    itemptr=getItem("rock");
    rockAmt=itemptr->getQuantity();
    itemptr=getItem("paper");
    paperAmt=itemptr->getQuantity();
    itemptr=getItem("scissors");
    scissorsAmt=itemptr->getQuantity();
    
    if (rockAmt==0&&paperAmt==0&&scissorsAmt==0)
    {
        return 0;
    }
    
    cout << "\n\nENTER YOUR THROW:" <<endl
    << "1. ROCK (" << rockAmt << ")"<< endl
    << "2. PAPER (" << paperAmt << ")"<< endl
    << "3. SCISSORS (" << scissorsAmt << ")"<< endl;
    
    int shot=0;
    while(shot<=0||shot>=4)
    {
        cin >> shot;
        if(numToWeapon(shot)->getQuantity()==0)
        {
            shot=0;
        }
    }
    itemptr=numToWeapon(shot);
    itemptr->addQuantity(-1);
    return shot;
}

void Player::taunt()
{
    cout<<"\n\n"<<getName()<<" says: TAKE THIS!\n";
}
