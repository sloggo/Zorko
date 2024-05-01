//
// Created by Josh Sloggett on 30/04/2024.
//

#ifndef UNTITLED2_PLAYER_H
#define UNTITLED2_PLAYER_H

#include<string>
#include<vector>
#include "Subject.h"
#include "Item.h"
#include "Battlable.h"

using namespace std;

class Player : public Subject, public Battlable {
private:
    string name;
    Item[] inventory;
public:
    Player(string);
    string getName();
    void setName(string);

    void move(int, int);
    void pickup(Item);
    void drop(Item);
};


#endif //UNTITLED2_PLAYER_H
