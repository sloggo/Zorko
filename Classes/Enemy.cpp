//
// Created by Josh Sloggett on 05/05/2024.
//
#include <utility>

#include "../Headers/Enemy.h"
#include<iostream>

using namespace std;

Enemy::Enemy(Weapon w, int idI, std::string nameIn, vector<std::string> ad, vector<std::string> hd, vector<std::string> dd) : Battlable(std::move(w)) {
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
    cout << deathDialog[0] << endl;
}

string Enemy::getName(){
    return name;
}