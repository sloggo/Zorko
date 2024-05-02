//
// Created by Josh Sloggett on 02/05/2024.
//

#include "../Headers/InputHandler.h"
#include<string>
#include<iostream>
#include <sstream>
#include "../Headers/Player.h"
#include"../utils.h"

using namespace std;

InputHandler* InputHandler::instance = nullptr;

InputHandler* InputHandler::getInstance() {
    if (instance == nullptr) {
        instance = new InputHandler(); // Allocate memory for the instance
    }
    return instance;
}

void InputHandler::takeInInput(string type, int stageId) {
    string input;
    getline(cin, input);
    processInput(input, type, stageId);
}


void InputHandler::processInput(string inputWords, string type, int id) {
    stringstream ss(inputWords);

    vector<string> words;
    string word;

    while(ss >> word){
        words.push_back(word);
    }

    processedInput = words;

    if(type == "move"){
        processMovement();
    } else if(type == "item"){
        processPickup(id);
    }
}

vector<string> InputHandler::getProcessedInput() {
    return processedInput;
}

void InputHandler::processMovement(){
    if(processedInput[0] != "go"){
        cout << "Invalid input!" << endl;
        takeInInput("move", 0);
    }

    Player* plyr = Player::getInstance();
    string direction = processedInput[1];
    pair<int,int> currentLoc = plyr->loc;
    pair<int,int> newLoc = make_pair(currentLoc.first, currentLoc.second);

    if(direction == "north"){
        newLoc.second = currentLoc.second+1;
        plyr->move(newLoc); //friendship allows direct access to move func
    }else if(direction == "south"){
        newLoc.second = currentLoc.second-1;
        plyr->move(newLoc);
    }else if(direction == "east"){
        newLoc.first = currentLoc.first+1;
        plyr->move(newLoc);
    }else if(direction == "west"){
        newLoc.first = currentLoc.first-1;
        plyr->move(newLoc);
    }
}

void InputHandler::processPickup(int id){
    Player* plyr = Player::getInstance();
    plyr->pickup(getItemFromId(id));
}