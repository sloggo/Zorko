//
// Created by Josh Sloggett on 01/05/2024.
//
#include "../Headers/Observer.h"

Observer::Observer(int idIn) {
    this->id = idIn;
}

bool Observer::equals(Observer o) const {
    return this->id == o.id;
}