//
// Created by Josh Sloggett on 02/05/2024.
//

#include "../Headers/InputHandler.h"
#include<string>
#include<iostream>
#include <sstream>

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
