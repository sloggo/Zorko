//
// Created by Josh Sloggett on 02/05/2024.
//

#include "../Headers/GameState.h"
#include "../utils.h"
#include "../Headers/Player.h"

GameState::GameState() : Observer(0), currentRoom(getRoomFromLocation(make_pair(0,0)))  {
}

Room GameState::getCurrentRoom() {
    return currentRoom;
}

void GameState::update(pair<int, int> loc) {
    currentRoom = getRoomFromLocation(loc);
}