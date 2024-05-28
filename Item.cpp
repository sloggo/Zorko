//
// Created by Josh Sloggett on 02/05/2024.
//
#include <utility>
#include <iostream>
#include"Item.h"

using namespace std;

Item::Item(int idI, std::string nameI, std::string desc) {
    id = idI;
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

int Item::getId() {
    return id;
}

int Item::returnUIValue(){
    return 0;
}

Item::~Item(){
    cout << "item deleted" << endl;
}
