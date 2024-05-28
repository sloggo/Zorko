//
// Created by Josh Sloggett on 01/05/2024.
//
#include "Observer.h"
#include "Player.h"
#include<iostream>
using namespace std;

Observer::Observer(int idIn) {
    this->id = idIn;
}

bool Observer::equals(Observer o) const {
    return this->id == o.id;
}

void Observer::update(pair<int, int>) {
    cout << "observer base called" << endl;
}

void Observer::update(int) {
    cout << "observer base called" << endl;
}

void Observer::addToPlayer() {
    Player* plyr = Player::getInstance();
    plyr->addObserver(this);
}

void Observer::updateR(Room* r) {
    cout << "observer base called" << endl;
}
