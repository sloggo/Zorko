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
#include "InputHandler.h"

using namespace std;

class Player : public Subject, public Battlable {
private:
    friend InputHandler;
    static Player* instance;
    vector<Item*> inventory;
    pair<int,int> loc;
    int stageIndex;
    void move(pair<int,int>); // CALL UPDATE
public:
    static Player* getInstance();
    explicit Player(Weapon*);
    void attack(Battlable*) override;
    void takeDmg(int) override;
    void block() override;

    pair<int,int> getLoc();
    vector<Item*> getInventory();
    void showInventory();

    void pickup(Item*);
    void drop(Item*);
    void equipWeapon(Weapon*);
};


#endif //UNTITLED2_PLAYER_H
