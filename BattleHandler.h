//
// Created by Josh Sloggett on 05/05/2024.
//

#ifndef UNTITLED2_BATTLEHANDLER_H
#define UNTITLED2_BATTLEHANDLER_H

#include "Enemy.h"
#include "QString"

class BattleHandler{
private:
    int roomId;
    Enemy* enemy;
public:
    BattleHandler(int, Enemy*);
    void battleLoop();
    bool battleRound();

    vector<string> initBattleUI();
    vector<string> playerMoveUI(string);
};

#endif //UNTITLED2_BATTLEHANDLER_H
