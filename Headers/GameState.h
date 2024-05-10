//
// Created by Josh Sloggett on 02/05/2024.
//

#ifndef UNTITLED2_GAMESTATE_H
#define UNTITLED2_GAMESTATE_H

#include "Room.h"
#include "Observer.h"
#include "../utils.h"

class GameState : public Observer{
private:
    Room* currentRoom;
    Stage* currentStage;
public:
    GameState();
    Room* getCurrentRoom();
    void update(pair<int,int>) override;
    void update(int) override;
};

#endif //UNTITLED2_GAMESTATE_H
