//
// Created by Josh Sloggett on 02/05/2024.
//
#include <utility>
#include<iostream>
#include "../Headers/Weapon.h"

using namespace std;

Weapon::Weapon(int id, string nameI, string descI, int damage, int dur) : Item(std::move(id), std::move(nameI),std::move(descI)) {
    dmg = damage;
    durability = dur;
}

void Weapon::use() {
    cout << "Attacked!" << endl;
}