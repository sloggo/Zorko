//
// Created by Josh Sloggett on 02/05/2024.
//

#include "../Headers/Player.h"
#include "../Headers/Subject.h"
#include<iostream>

using namespace std;

Player* Player::instance = nullptr;

Player* Player::getInstance() {
    if (instance == nullptr) {
        Weapon starterWeapon = *new Weapon("Starter Sword", "A sword given to you by your father", 10, 10);
        instance = new Player(starterWeapon); // Allocate memory for the instance
    }
    return instance;
}

Player::Player(Weapon weaponIn) : Battlable(weaponIn), Subject() {
    inventory.push_back(weaponIn);
    loc = make_pair(0,0);
}

pair<int,int> Player::getLoc() {
    return loc;
}

vector<Item> Player::getInventory() {
    return inventory;
}

void Player::move(pair<int, int> l) {
    loc = l;
    for(Observer o: observers){
        o.update(l);
    }
}

void Player::pickup(Item i) {
    cout << "Picked up "+i.getName()+"!" << endl;
    inventory.push_back(i);
}

void Player::drop(Item dropping) {

    for (auto it = inventory.begin(); it != inventory.end(); ++it) {
        if (*it == dropping) {
            inventory.erase(it);
            cout <<"Dropped "+dropping.getName()+"!"<<endl;
            break;
        }
    }
}

