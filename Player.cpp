//
// Created by Josh Sloggett on 02/05/2024.
//

#include "Player.h"
#include "Subject.h"
#include<iostream>

using namespace std;

Player* Player::instance = nullptr;

Player* Player::getInstance() {
    if (instance == nullptr) {
        Weapon* starterWeapon = new Weapon(0,"Starter Sword", "A sword given to you by your father", 5, 10);
        instance = new Player(starterWeapon); // Allocate memory for the instance
    }
    return instance;
}

Player::Player(Weapon* weaponIn) : Battlable(weaponIn), Subject(), showInventoryAbstract() {
    inventory.push_back(weaponIn);
    loc = make_pair(0,0);
}

pair<int,int> Player::getLoc() {
    return loc;
}

vector<Item*> Player::getInventory() {
    return inventory;
}

void Player::move(pair<int, int> l) {
    loc = l;
    update(l);
}

void Player::pickup(Item* i) {
    cout << "Picked up "+i->getName()+"!" << endl;
    inventory.push_back(i);
}

void Player::drop(Item* dropping) {

    for (auto it = inventory.begin(); it != inventory.end(); ++it) {
        if (*it == dropping) {
            inventory.erase(it);
            cout <<"Dropped "+dropping->getName()+"!"<<endl;
            break;
        }
    }
}

void Player::showInventory() {
    for(Item* i: inventory){
        cout << i->getName() << endl;
        cout << i->getDescription() << endl;
        cout << "-------" << endl;
    }
}

void Player::attack(Battlable *target) {
    cout << "Player attacks for "<< weapon->getDmg()<< "!"<<endl;
    if(!target->isBlocked()){
        target->takeDmg(weapon->getDmg());
    } else{
        cout<< "Enemy blocked your attack!" << endl;
        target->block();
    }
}

void Player::takeDmg(int dmg) {
    if(hp-dmg <= 0){
        hp = 0;
    } else{
        hp -= dmg;
    }
    cout << "You took "<<dmg<<" damage!" << endl;
}

void Player::block() {
    if(blocked){
        blocked = false;
        cout << "Your block has been broken!" << endl;
    } else{
        blocked = true;
        cout << "You blocked!" << endl;
    }
}

void Player::equipWeapon(Weapon* w){
    weapon = w;
}
