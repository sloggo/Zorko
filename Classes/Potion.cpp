//
// Created by Josh Sloggett on 03/05/2024.
//
#include "../Headers/Potion.h"
#include "../Headers/Player.h"
#include "../Headers/Item.h"

Potion::Potion(int id, std::string name, std::string desc, int healIn) : Item(id, name, desc){
    heal = healIn;
}
void Potion::use() {
    Player* plyr = Player::getInstance();
    plyr->heal(heal);
    plyr->drop(*this);
}