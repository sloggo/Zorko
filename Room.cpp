//
// Created by Josh Sloggett on 02/05/2024.
//
#include <utility>
#include <iostream>

#include "Room.h"
#include "Stage.h"
#include "Player.h"
using namespace std;

Room::Room(int idI, vector<Stage*> stgs, pair<int, int> loc) : Runnable() {
    completed = false;
    id=idI;
    stages=stgs;
    location=loc;
    counter = 0;
}

void Room::run()  {
    Player* plyr = Player::getInstance();
    if(!completed){
        for(counter; counter<stages.size()-1; counter++){
            //cout << counter << "-" << stages.size()<< endl; debug
            plyr->update(counter);
            bool complete = false;
            while(!complete){
                complete = stages[counter]->runStage();
                if(complete){
                    continue;
                }
            }
        }
        completed = true;
    } else{
        plyr->update(stages.size()-1);
        bool complete = false;
        while(!complete){
            complete = stages[stages.size()-1]->runStage();
            if(complete){
                continue;
            }
        }
    }
}

void Room::runUI()  {
    Player* plyr = Player::getInstance();
    if(!completed){
        cout << counter << stages.size()-2 << endl;
        if(stages[counter+1]->getText().find("return") != string::npos){
            completed = true;
            cout << completed << endl;
            getStage(counter)->runUI();
        }else{
            getStage(counter)->runUI();
        }
    } else{
        cout << "final stage" << endl;
        getStage(stages.size()-1)->runUI();
    }
}

void Room::nextStage(){
    if(getCurrentStage()->getType() == "item"){
        InputHandler* handler = InputHandler::getInstance();
        handler->processPickup(getCurrentStage()->id);
    }
    if(getCurrentStage()->id == stages[stages.size()-2]->id){
        completed = true;
        counter++;
    } else if(getCurrentStage()->id != stages[stages.size()-1]->id){
        counter++;
    }
}

pair<int,int> Room::getLoc() {
    return location;
}

Stage* Room::getStage(int index) {
    return stages[index];
}

Stage* Room::getCurrentStage(){
    return stages[counter];
}

vector<Stage*> Room::getAllStages(){
    return stages;
}
