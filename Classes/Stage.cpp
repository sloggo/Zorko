//
// Created by Josh Sloggett on 02/05/2024.
//
#include "../Headers/Stage.h"
#include<iostream>
#include"../Headers/InputHandler.h"
#include"../Headers/BattleHandler.h"
#include "../utils.h"
using namespace std;

Stage::Stage(int idI, std::string textI, std::string typeI) : Runnable() {
    id = idI;
    text = textI;
    type = typeI;
}

bool Stage::runStage() {
    cout << text << endl;
    InputHandler* i = InputHandler::getInstance();
    if(type == "text"){
        return true;
    }

    // type execution
    if(type == "item"){
        return i->takeInInput(type, id);
    }else if(type == "battle"){
        Enemy* enemy = getEnemyFromId(id);
        BattleHandler handler = BattleHandler(id, enemy);
        return handler.battleRound();
    }else if(type != "text"){
        return i->takeInInput(type, id);
    }
    return false;
}