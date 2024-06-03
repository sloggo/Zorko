//
// Created by Josh Sloggett on 05/05/2024.
//
#include "BattleHandler.h"
#include "InputHandler.h"
#include "Player.h"
#include <iostream>
#include <random>

using namespace std;

BattleHandler::BattleHandler(int roomIdI, Enemy* enemyI) : roomId(roomIdI), enemy(enemyI) {
    cout << "Battle Started!" << endl;
}

bool BattleHandler::battleRound() {
    // let player go first
    InputHandler* input = InputHandler::getInstance();
    Player* plyr = Player::getInstance();
    string enemyName = enemy->getName();

    int round = 1;
    while(plyr->getHp() > 0 && enemy && enemy->getHp() > 0) { // Check if enemy is not null
        cout << "" << endl;
        cout << "Round: " << round << endl;
        cout << "-------------------------" << endl;
        cout << "Player - " << plyr->getHp() << " ";
        cout << "| Enemy - " << this->enemy->getHp() << endl;
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
        return false;
    } else{
        delete enemy;
        cout << "You defeated " << enemyName << "!" << endl;
        return true;
    }
}

vector<string> BattleHandler::initBattleUI(){
    Player* plyr = Player::getInstance();
    vector<string> texts;

    texts.push_back("");
    texts.push_back("Battle Started!");
    texts.push_back("-------------------------");
    texts.push_back("Player - "+to_string(plyr->getHp()) + " | "+" Enemy - "+to_string(enemy->getHp()));
    return texts;
}

tuple<vector<string>, bool> BattleHandler::playerMoveUI(string input){
    Player* plyr = Player::getInstance();
    vector<string> dialog;
    dialog.push_back("");
    bool died = false;

    if(input == "attack"){
        if(enemy->isBlocked()){
            dialog.push_back(enemy->getName()+" has blocked your attack!");
            dialog.push_back("Their block has been broken!");
            enemy->block();
        } else{
            dialog.push_back("You attacked "+enemy->getName()+"!");
            plyr->attack(enemy);
            dialog.push_back(enemy->getName()+": "+enemy->getRandomHurtDialog());
            if(enemy->getHp()<=0){
                dialog.push_back("You win!");
                return make_tuple(dialog, died);
                //end?
            }
        }
    } else if(input == "block"){
        plyr->block();
        dialog.push_back("You blocked! If you block again without someone breaking it, you will cancel out your own block!");
    }

    dialog.push_back("");

    // enemy attack
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_real_distribution<double> dis(0.0, 1.0);
    double randNum = dis(gen);

    if(randNum <= 0.25){
        enemy->block();
        dialog.push_back(enemy->getName()+" puts up a solid guard!");
    } else{
        dialog.push_back(enemy->getName()+" attacks!");
        if(plyr->isBlocked()){
            dialog.push_back("You blocked the attack! Your block has been broken!");
            plyr->block();
        } else{
            enemy->attack(plyr);
            dialog.push_back(enemy->getName()+": "+enemy->getRandomAttackDialog());
            if(plyr->getHp() <= 0){
                dialog.push_back("GAME OVER! Better luck next time!");
                died = true;
                return make_tuple(dialog, died);
            }
        }
    }

    dialog.push_back("");

    dialog.push_back("Player - "+to_string(plyr->getHp()) + " | "+" Enemy - "+to_string(enemy->getHp()));

    return make_tuple(dialog, died);
}
