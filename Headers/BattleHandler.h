//
// Created by Josh Sloggett on 05/05/2024.
//

#ifndef UNTITLED2_BATTLEHANDLER_H
#define UNTITLED2_BATTLEHANDLER_H

#include "Enemy.h"

class BattleHandler{
private:
    int roomId;
    Enemy* enemy;
public:
    BattleHandler(int, Enemy*);
    void battleLoop();
    bool battleRound();
};

#endif //UNTITLED2_BATTLEHANDLER_H
