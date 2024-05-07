//
// Created by Josh Sloggett on 05/05/2024.
//
#include "../Headers/BattleHandler.h"
#include "../Headers/InputHandler.h"
#include "../Headers/Player.h"
#include <iostream>
#include <random>

using namespace std;

BattleHandler::BattleHandler(int roomIdI, Enemy* enemyI) {
    roomId = roomIdI;
    enemy = enemyI;
    cout << "Battle Started!" << endl;
}

void BattleHandler::battleRound() {
    // let player go first
    InputHandler* input = InputHandler::getInstance();
    Player* plyr = Player::getInstance();

    int round = 1;
    while(plyr->getHp() > 0 && enemy && enemy->getHp() > 0) { // Check if enemy is not null
        cout << "Round: " << round << endl;
        cout << "-------------------------" << endl;
        cout << "Player - " << plyr->getHp();
        cout << " Enemy - " << enemy->getHp() << endl;
        string userInput = input->takeInInput("battle");
        bool validInput = false;
        while(!validInput){
            if(userInput == "attack"){
                plyr->attack(enemy);
                validInput = true;
            } else if(userInput == "block"){
                plyr->block();
                validInput = true;
            } else if(userInput == "pass"){
                validInput = true;
            } else{
                cout << "Invalid move!" << endl;
            }
        }

        if(enemy && enemy->getHp() > 0) { // Check if enemy is not null
            double randNum = ((double) rand() / (RAND_MAX)) + 1;
            if(randNum <= 0.25){
                enemy->block();
            } else {
                enemy->attack(plyr);
            }
        } else {
            delete enemy;
        }
        round++;
    }

    if(plyr->getHp() <= 0){
        cout << "You died!" << endl;
    } else{
        cout << "You defeated " + enemy->getName() + "!" << endl;
    }
}
