//
// Created by Josh Sloggett on 02/05/2024.
//
#include <utility>

#include "../Headers/Room.h"
#include "../Headers/Stage.h"
#include "../Headers/DataHandler.h"
#include "../Headers/Player.h"


Room::Room(int idI, vector<Stage> stgs, pair<int, int> loc) : Runnable() {
    completed = false;
    id=idI;
    stages=std::move(stgs);
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
                complete = stages[counter].runStage();
                if(complete){
                    continue;
                }
            }
        }
        completed = true;
    } else{
        bool complete = false;
        while(!complete){
            complete = stages[stages.size()-1].runStage();
            if(complete){
                continue;
            }
        }
    }
}

pair<int,int> Room::getLoc() {
    return location;
}

vector<Stage> Room::getStages() {
    return stages;
}