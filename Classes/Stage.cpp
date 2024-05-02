//
// Created by Josh Sloggett on 02/05/2024.
//
#include "../Headers/Stage.h"
#include<iostream>
#include"../Headers/InputHandler.h"
using namespace std;

Stage::Stage(int idI, std::string textI, std::string typeI) : Runnable() {
    id = idI;
    text = textI;
    type = typeI;
}

void Stage::run() {
    cout << text << endl;
    InputHandler* i = InputHandler::getInstance();

    // type execution
    if(type == "item"){
        i->takeInInput(type, id);
    }else if(type != "text"){
        i->takeInInput(type, id);
    }
}