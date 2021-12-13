//
//  item.hpp
//  AdvancedRPSGame
//
//  Created by Nathan Dilla on 12/8/21.
//

#ifndef item_hpp
#define item_hpp

#include <stdio.h>
#include <string>
using namespace std;

class item
{
private:
    int quantity;
    string name;
    string category;
    string desc;
    bool onBody=false;
public:
    item();
    item(string n, int q, string c, string d);
    string getCategory();
    int getQuantity();
    bool isOnBody();
    string getDesc();
    string getName();
    void setName(string);
    void setCategory(string c);
    void setDesc(string);
    void setOnBody(bool);
    void dawn();
    void setQuantity(int);
    void addQuantity(int);
    void operator ++();
    void operator --();
};

#endif /* item_hpp */
