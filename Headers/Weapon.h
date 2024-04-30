//
// Created by Josh Sloggett on 30/04/2024.
//

#ifndef UNTITLED2_WEAPON_H
#define UNTITLED2_WEAPON_H
#include "Item.h"

using namespace std;

class Weapon: public Item {
private:
    int dmg;
    int durability;
public:
    void use() override;
};

#endif //UNTITLED2_WEAPON_H
