//
// Created by Josh Sloggett on 02/05/2024.
//
#include <utility>

#include "../Headers/Weapon.h"

using namespace std;

Weapon::Weapon(string nameI, string descI, int damage, int dur) : Item(std::move(nameI),std::move(descI)) {
    dmg = damage;
    durability = dur;
}