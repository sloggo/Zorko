//
// Created by Josh Sloggett on 02/05/2024.
//

#include "utils.h"

DataHandler dh = DataHandler();
vector<Item*> items = dh.importItemData();

Item* getItemFromId(int id){
    for(Item* i: items){
        if(i->getId() == id){
            return i; // copy constructor
        }
    }
    return items[0];
}

vector<Room*> rooms = dh.importRoomData();
Room* getRoomFromLocation(pair<int,int> loc){
    for(Room* room: rooms){
        if(room->getLoc().first == loc.first && room->getLoc().second == loc.second){
            return room;
        }
    }
    return nullptr;
}

vector<Enemy*> enemies = dh.importEnemyData();
Enemy* getEnemyFromId(int id) {
    vector<Enemy*> foundEnemies;
    for (Enemy* enemy : enemies) {
        if (enemy->getId() == id) {
            return new Enemy(*enemy); // all attrivutes of enemy are on the stack, therefore this is a deep copy
        }
    }
    return nullptr;
}

Stage* getStage(pair<int,int> room, int stageIndex){
    Room* roomIsIn = getRoomFromLocation(room);
    Stage* stage = roomIsIn->getStage(stageIndex);
    return stage;
}

