//
// Created by Josh Sloggett on 02/05/2024.
//
#include <utility>
#include <iostream>
#include"../Headers/Item.h"

using namespace std;

Item::Item(std::string nameI, std::string desc) {
    name = std::move(nameI);
    description = std::move(desc);
}

string Item::getName() {
    return name;
}

string Item::getDescription() {
    return description;
}

void Item::use() {
    cout << "Used "+name+"!" << endl;
}

bool Item::equals(const Item& i) const {
    return this->name == i.name && this->description == i.description;
}
