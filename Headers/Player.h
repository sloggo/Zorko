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
    static Player* instance;
    string name;
    Item[] inventory;
    int[] loc;
public:
    static Player* getInstance();
    Player(string);

    string getName();
    void setName(string);

    int[] getLoc();
    void move(int, int);

    void pickup(Item);
    void drop(Item);
};


#endif //UNTITLED2_PLAYER_H
