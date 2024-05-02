//
// Created by Josh Sloggett on 02/05/2024.
//
#include <utility>

#include "../Headers/Room.h"
#include "../Headers/Stage.h"
#include "../Headers/DataHandler.h"

Room::Room(int idI, vector<Stage> stgs, pair<int, int> loc) : Runnable() {
    id=idI;
    stages=std::move(stgs);
    location=loc;
}

void Room::run()  {
    for(Stage stg: stages){
        stg.run();
    }
}

pair<int,int> Room::getLoc() {
    return location;
}