//
// Created by Josh Sloggett on 02/05/2024.
//

#include "InputHandler.h"
#include<string>
#include<iostream>
#include <sstream>
#include "Player.h"
#include"utils.h"

using namespace std;

InputHandler* InputHandler::instance = nullptr;

InputHandler* InputHandler::getInstance() {
    if (instance == nullptr) {
        instance = new InputHandler(); // Allocate memory for the instance
    }
    return instance;
}

bool InputHandler::takeInInput(string type, int stageId) {
    string input;
    getline(cin, input);
    return processInput(input, type, stageId);
}

string InputHandler::takeInInput(string type) {
    string input;
    getline(cin, input);
    return input;
}

bool InputHandler::processInput(string inputWords, string type, int id) {
    stringstream ss(inputWords);

    vector<string> words;
    string word;

    while(ss >> word){
        words.push_back(word);
    }

    processedInput = words;

    if((processedInput[0] == "show" && processedInput[1] == "inventory") || processedInput[0] == "inventory"){
        Player* plyr = Player::getInstance();
        plyr->showInventory();
        return false;
    }else if(processedInput[0] == "go"){
        return processMovement(type);
    } else if(processedInput[0] == "pickup"){
        if(type == "item"){
            processPickup(id);
            return true;
        } else{
            cout << "There's nothing to pickup!" << endl;
            return false;
        }
    }
    return false;
}

vector<string> InputHandler::getProcessedInput() {
    return processedInput;
}

bool InputHandler::processMovement(string type){
    if(processedInput[0] != "go"){
        cout << "Invalid input!" << endl;
        takeInInput("move", 0);
        return false;
    }

    Player* plyr = Player::getInstance();
    string direction = processedInput[1];
    pair<int,int> currentLoc = plyr->loc;
    pair<int,int> newLoc = make_pair(currentLoc.first, currentLoc.second);

    if(direction == "north"){
        newLoc.second = currentLoc.second+1;
        if(getRoomFromLocation(newLoc) != nullptr){
            plyr->move(newLoc); //friendship allows direct access to move func
            return true;
//            if(type == "move"){
//                return true;
//            }else{
//                return false;
//            }
        } else{
            cout << "Invalid move location; no room!" << endl;
        }
    }else if(direction == "south"){
        newLoc.second = currentLoc.second-1;
        if(getRoomFromLocation(newLoc) != nullptr){
            plyr->move(newLoc);
            return true;
//            if(type == "move"){
//                return true;
//            }else{
//                return false;
//            }
        }else{
            cout << "Invalid move location; no room!" << endl;
        }
    }else if(direction == "east"){
        newLoc.first = currentLoc.first+1;
        if(getRoomFromLocation(newLoc) != nullptr){
            plyr->move(newLoc);
            return true;
//            if(type == "move"){
//                return true;
//            } else{
//                return false;
//            }
        }else{
            cout << "Invalid move location; no room!" << endl;
        }
    }else if(direction == "west"){
        newLoc.first = currentLoc.first-1;
        if(getRoomFromLocation(newLoc) != nullptr) {
            plyr->move(newLoc);
            return true;
//            if(type == "move"){
//                return true;
//            }else{
//                return false;
//            }
        }else{
            cout << "Invalid move location; no room!" << endl;
        }
    }
    return false;
}

void InputHandler::processPickup(int id){
    Player* plyr = Player::getInstance();
    plyr->pickup(getItemFromId(id));
}

bool InputHandler::processUI(string key){
    cout << "input handler activated" << endl;
    Player* plyr = Player::getInstance();
    pair<int,int> currentLoc = plyr->loc;
    pair<int,int> newLoc = make_pair(currentLoc.first, currentLoc.second);

    cout << "before direction check" << endl;
    if(key == "north"){
        newLoc.second = currentLoc.second+1;
        cout << "before getroomfromlocation" << endl;
        if(getRoomFromLocation(newLoc) != nullptr){
            cout << "before move plyr" << endl;
            plyr->move(newLoc); //friendship allows direct access to move func
            return true;
        } else{
            cout << "Invalid move location; no room!" << endl;
        }
    }else if(key == "south"){
        newLoc.second = currentLoc.second-1;
        if(getRoomFromLocation(newLoc) != nullptr){
            plyr->move(newLoc);
            return true;
        }else{
            cout << "Invalid move location; no room!" << endl;
        }
    }else if(key == "east"){
        newLoc.first = currentLoc.first+1;
        if(getRoomFromLocation(newLoc) != nullptr){
            plyr->move(newLoc);
            return true;
        }else{
            cout << "Invalid move location; no room!" << endl;
        }
    }else if(key == "west"){
        newLoc.first = currentLoc.first-1;
        if(getRoomFromLocation(newLoc) != nullptr) {
            plyr->move(newLoc);
            return true;

        }else{
            cout << "Invalid move location; no room!" << endl;
        }
    }

    return false;
}
