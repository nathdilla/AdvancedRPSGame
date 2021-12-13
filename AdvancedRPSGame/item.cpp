//
//  item.cpp
//  AdvancedRPSGame
//
//  Created by Nathan Dilla on 12/8/21.
//

#include "item.hpp"

item::item(){}

item::item(string n, int q, string c, string d)
{
    setName(n);
    setQuantity(q);
    setCategory(c);
    setDesc(d);
}

string item::getName()
{
    return name;
}

int item::getQuantity()
{
    return quantity;
}

string item::getCategory()
{
    return category;
}

bool item::isOnBody()
{
    return onBody;
}

string item::getDesc()
{
    return desc;
}

void item::setQuantity(int q)
{
    quantity=q;
}

void item::addQuantity(int a)
{
    quantity=quantity+a;
}

void item::setName(string n)
{
    name=n;
}

void item::setCategory(string c)
{
    category=c;
}

void item::setDesc(string s)
{
    desc=s;
}

void item::setOnBody(bool b)
{
    onBody=b;
}

void item::dawn()
{
    if(onBody){onBody=false;}else{onBody=true;}
}
