//
// Created by Josh Sloggett on 05/05/2024.
//
#include <utility>

#include "Enemy.h"
#include "Player.h"

#include<iostream>

using namespace std;

Enemy::Enemy(Weapon* w, int idI, std::string nameIn, vector<std::string> ad, vector<std::string> hd, vector<std::string> dd) : Battlable(w) {
    id = idI;
    name = nameIn;
    attackDialog = ad;
    hurtDialog = hd;
    deathDialog = dd;
}

int Enemy::getId() {
    return id;
}

Enemy::~Enemy() {
    cout << name << ": " <<getRandomDeathDialog() << endl;
}

string Enemy::getName(){
    return name;
}

void Enemy::attack(Battlable *target) {
    cout << name << " attacks for "<< weapon->getDmg()<< "!"<<endl;
    if(!target->isBlocked()){
        cout << name << ": " <<getRandomAttackDialog() << endl;
        target->takeDmg(weapon->getDmg());
    } else{
        cout<< "Player blocks the attack!" << endl;
        cout << name << ": " <<getRandomHurtDialog() << endl;
        target->block();
    }
}

void Enemy::takeDmg(int dmg) {
    if(hp-dmg <= 0){
        hp = 0;
    } else{
        hp -= dmg;
    }
    cout << name << " took "<<dmg<<" damage!" << endl;
    cout << name << ": " << getRandomHurtDialog() << endl;
}

string Enemy::getRandomAttackDialog() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    int randomNumber = std::rand() % attackDialog.size(); // Gives a number between 0 and 10
    return attackDialog[randomNumber];
}

string Enemy::getRandomHurtDialog() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    int randomNumber = std::rand() % hurtDialog.size(); // Gives a number between 0 and 10
    return hurtDialog[randomNumber];
}

string Enemy::getRandomDeathDialog() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    int randomNumber = std::rand() % deathDialog.size(); // Gives a number between 0 and 10
    return deathDialog[randomNumber];
}
