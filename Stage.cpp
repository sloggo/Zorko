//
// Created by Josh Sloggett on 02/05/2024.
//
#include "Stage.h"
#include<iostream>
#include"InputHandler.h"
#include"BattleHandler.h"
#include "utils.h"
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
    if(type == "battle"){
        Enemy* enemy = getEnemyFromId(id);
        BattleHandler handler = BattleHandler(id, enemy);
        return handler.battleRound();
    }else if(type != "text"){
        return i->takeInInput(type, id);
    }
    return false;
}

void Stage::runUI() {
    if(type=="battle"){
        //battle logic
    }
    cout << "Stage run" << endl;
}

string Stage::getText(){
    return text;
}

string Stage::getType(){
    return type;
}
