//
// Created by Josh Sloggett on 02/05/2024.
//

#include "GameState.h"
#include "utils.h"
#include "Player.h"
#include "mainwindow.h"
#include "QString"
using namespace std;

GameState::GameState(bool cmd) : Observer(0), Subject(), cmdBased(cmd), currentRoom(nullptr), currentStage()  {
}


Room* GameState::getCurrentRoom() {
    return currentRoom;
}

void GameState::update(pair<int, int> loc) {
    currentRoom = getRoomFromLocation(loc);
    update(currentRoom);
}

void GameState::update(int loc) {
    if (currentRoom == nullptr) {
        cerr << "Error: currentRoom pointer is null." << endl;
        return;
    }

    currentStage = getStage(currentRoom->getLoc(), loc);
    if (currentStage == nullptr) {
        cerr << "Error: getStage function returned a null pointer." << endl;
        return;
    }

    update(currentRoom);
}

void GameState::runGame(){
    if(cmdBased){
        while(true){
            currentRoom->run();
        }
    } else{
        update(currentRoom);
        currentRoom->runUI();
    }
}

void GameState::update(Room* room){
    cout << "gamestate being cllaed" << endl;
    for(Observer* w: observers){
        w->updateR(room);
    }
}

void GameState::runNextRoom(){
    currentRoom->nextStage();
    runGame();
}
