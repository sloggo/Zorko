//
// Created by Josh Sloggett on 30/04/2024.
//

#ifndef UNTITLED2_ITEM_H
#define UNTITLED2_ITEM_H
#include<string>

using namespace std;

class Item{
protected:
    string name;
    string description;
public:
    Item(string, string);
    virtual void use();
};

#endif //UNTITLED2_ITEM_H
