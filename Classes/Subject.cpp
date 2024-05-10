//
// Created by Josh Sloggett on 01/05/2024.
//
#include "../Headers/Subject.h"
#include<iostream>

using namespace std;

void Subject::addObserver(Observer* o) {
    observers.push_back(o);
}

void Subject::removeObserver(Observer* o) {
    for (auto it = observers.begin(); it != observers.end(); ++it) {
        if (*it == o) {
            observers.erase(it);
            break;
        }
    }
}

void Subject::update(pair<int,int> loc){
    for(Observer* o: observers){
        o->update(loc);
    }
}
void Subject::update(int loc){
    for(Observer* o: observers){
        o->update(loc);
    }
}
