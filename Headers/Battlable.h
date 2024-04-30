//
// Created by Josh Sloggett on 30/04/2024.
//

#ifndef UNTITLED2_BATTLABLE_H
#define UNTITLED2_BATTLABLE_H
#include "Weapon.h";

using namespace std;

class Battlable{
private:
    int hp;
    Weapon weapon;
public:
    void takeDmg(int);
    void heal(int);
    void attack();
    void block();
};

#endif //UNTITLED2_BATTLABLE_H