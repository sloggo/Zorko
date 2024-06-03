//
// Created by Josh Sloggett on 30/04/2024.
//

#ifndef UNTITLED2_WEAPON_H
#define UNTITLED2_WEAPON_H
#include "Item.h"

using namespace std;

class Weapon: public Item {
private:
    int durability;
    union{
        int dmg;
        int dmgMultiplied;
    };
public:
    Weapon(int,string,string,int,int);
    void use() override;
    int getDmg();
    int returnUIValue() override;
};

#endif //UNTITLED2_WEAPON_H
