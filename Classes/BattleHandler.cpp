//
// Created by Josh Sloggett on 05/05/2024.
//
#include "../Headers/BattleHandler.h"
#include "../Headers/InputHandler.h"
#include "../Headers/Player.h"
#include <iostream>
#include <random>

using namespace std;

BattleHandler::BattleHandler(int roomIdI, Enemy* enemyI) : roomId(roomIdI), enemy(enemyI) {
    cout << "Battle Started!" << endl;
}

void BattleHandler::battleRound() {
    // let player go first
    InputHandler* input = InputHandler::getInstance();
    Player* plyr = Player::getInstance();
    string enemyName = enemy->getName();

    int round = 1;
    while(plyr->getHp() > 0 && enemy && enemy->getHp() > 0) { // Check if enemy is not null
        cout << "" << endl;
        cout << "Round: " << round << endl;
        cout << "-------------------------" << endl;
        cout << "Player - " << plyr->getHp();
        cout << " Enemy - " << this->enemy->getHp() << endl;
        bool validInput = false;
        while(!validInput){
            string userInput = input->takeInInput("battle");
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

        cout << "" << endl;

        if(enemy->getHp() > 0) {
            std::random_device rd;
            std::mt19937 gen(rd());

            std::uniform_real_distribution<double> dis(0.0, 1.0);
            double randNum = dis(gen);
            if(randNum <= 0.25){
                cout << "Enemy Blocks"<< endl;
                enemy->block();
            } else {
                cout << "Enemy attacks!" << endl;
                enemy->attack(plyr);
            }
        }
        round++;
    }

    if(plyr->getHp() <= 0){
        cout << "You died!" << endl;
    } else{
        delete enemy;
        cout << "You defeated " << enemyName << "!" << endl;
    }
}
