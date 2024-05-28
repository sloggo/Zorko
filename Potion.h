//
// Created by Josh Sloggett on 03/05/2024.
//

#ifndef UNTITLED2_POTION_H
#define UNTITLED2_POTION_H

#include "Item.h"

class Potion: public Item{
private:
    int heal;
public:
    Potion(int id,string name, string desc, int healIn);
    void use() override;
    int returnUIValue() override;
};

#endif //UNTITLED2_POTION_H
