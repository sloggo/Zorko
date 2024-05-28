//
// Created by Josh Sloggett on 03/05/2024.
//
#include "Potion.h"
#include "Player.h"
#include "Item.h"
#include<iostream>

Potion::Potion(int id, std::string name, std::string desc, int healIn) : Item(id, name, desc){
    heal = healIn;
}
void Potion::use() {
    Player* plyr = Player::getInstance();
    plyr->heal(heal);
    plyr->drop(this);
}

int Potion::returnUIValue(){
    return heal;
}

