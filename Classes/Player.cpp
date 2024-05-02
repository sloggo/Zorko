//
// Created by Josh Sloggett on 02/05/2024.
//

#include "../Headers/Player.h"

using namespace std;

Player* Player::instance = nullptr;

Player* Player::getInstance() {
    if (instance == nullptr) {
        Weapon starterWeapon = *new Weapon("Starter Sword", "A sword given to you by your father", 10, 10);
        instance = new Player(starterWeapon); // Allocate memory for the instance
    }
    return instance;
}

Player::Player(Weapon weaponIn) : Battlable(weaponIn){
    inventory.push_back(weaponIn);
    loc = make_pair(0,0);
}

pair<int,int> Player::getLoc() {
    return loc;
}

