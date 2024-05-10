//
// Created by Josh Sloggett on 30/04/2024.
//

#ifndef UNTITLED2_BATTLABLE_H
#define UNTITLED2_BATTLABLE_H
#include "Weapon.h"

using namespace std;

class Battlable{
protected:
    int hp;
    Weapon weapon;
    bool blocked;
    Battlable(Weapon);

public:
    void takeDmg(int);
    void heal(int);
    void attack(Battlable* target);
    void block();
    int getHp();
    bool isBlocked();
};

#endif //UNTITLED2_BATTLABLE_H
