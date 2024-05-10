//
// Created by Josh Sloggett on 02/05/2024.
//
#include "../Headers/Battlable.h"
#include<iostream>

using namespace std;

Battlable::Battlable(Weapon w) : weapon(w), hp(100), blocked(false) {
}

void Battlable::block() {
    if(blocked){
        blocked = false;
    } else{
        blocked = true;
    }
}

void Battlable::heal(int hpUp) {
    hp += hpUp;
}

void Battlable::takeDmg(int dmg) {
    if(hp-dmg <= 0){
        hp = 0;
    } else{
        hp -= dmg;
    }
}

void Battlable::attack(Battlable* target) {
    if(!target->blocked){
        target->takeDmg(weapon.getDmg());
    } else{
        target->block();
    }
}

int Battlable::getHp() {
    return this->hp;
}

bool Battlable::isBlocked() {
    return blocked;
}