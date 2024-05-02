//
// Created by Josh Sloggett on 02/05/2024.
//

#include "../Headers/InputHandler.h"
#include<string>
#include<iostream>
#include <sstream>
#include "../Headers/Player.h"

using namespace std;

InputHandler* InputHandler::instance = nullptr;

InputHandler* InputHandler::getInstance() {
    if (instance == nullptr) {
        instance = new InputHandler(); // Allocate memory for the instance
    }
    return instance;
}

void InputHandler::takeInInput() {
    string input;
    getline(cin, input);
    processInput(input);
}

void InputHandler::processInput(string inputWords) {
    stringstream ss(inputWords);

    vector<string> words;
    string word;

    while(ss >> word){
        words.push_back(word);
    }

    processedInput = words;
}

vector<string> InputHandler::getProcessedInput() {
    return processedInput;
}

void InputHandler::processMovement(){
    Player* plyr = Player::getInstance();
    string direction = processedInput[1];
    int[] currentLoc = plyr->getLoc();

    if(direction == "north"){
        plyr->move(currentLoc[0], currentLoc[1]+1)
    }else if(direction == "south"){
        plyr->move(currentLoc[0], currentLoc[1]-1)
    }else if(direction == "east"){
        plyr->move(currentLoc[0]+1, currentLoc[1])
    }else if(direction == "west"){
        plyr->move(currentLoc[0]-1, currentLoc[1])
    }
}