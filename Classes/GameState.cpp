//
// Created by Josh Sloggett on 02/05/2024.
//

#include "../Headers/GameState.h"
#include "../utils.h"
#include "../Headers/Player.h"

GameState::GameState() : Observer(0), currentRoom(nullptr), currentStage(nullptr)  {
}


Room* GameState::getCurrentRoom() {
    return currentRoom;
}

void GameState::update(pair<int, int> loc) {
    currentRoom = getRoomFromLocation(loc);
}

void GameState::update(int loc) {
    currentStage = getStage(currentRoom->getLoc(),loc);
}