//
// Created by Josh Sloggett on 02/05/2024.
//
#include "../Headers/Stage.h"
#include<iostream>
using namespace std;

Stage::Stage(int idI, std::string textI, std::string typeI) : Runnable() {
    id = idI;
    text = textI;
    type = typeI;
}

void Stage::run() {
    cout << text << endl;

    // type execution
}