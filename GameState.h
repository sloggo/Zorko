//
// Created by Josh Sloggett on 02/05/2024.
//

#ifndef UNTITLED2_GAMESTATE_H
#define UNTITLED2_GAMESTATE_H

#include "Room.h"
#include "Observer.h"
#include "Subject.h"

class GameState : public Observer, public Subject{
private:
    bool cmdBased;
    Room* currentRoom;
    Stage* currentStage;
public:
    GameState(bool);
    Room* getCurrentRoom();
    void update(pair<int,int>) override;
    void update(int) override;
    void runGame();
    void update(Room*) override;
    void runNextRoom();
};

#endif //UNTITLED2_GAMESTATE_H
