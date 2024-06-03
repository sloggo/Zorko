//
// Created by Josh Sloggett on 02/05/2024.
//

#ifndef UNTITLED2_DATAHANDLER_H
#define UNTITLED2_DATAHANDLER_H

#include "Room.h"
#include<iostream>
#include "Enemy.h"
using namespace std;

class DataHandler{
private:
    struct LoadStatus {
        unsigned int roomsLoaded : 1;
        unsigned int itemsLoaded : 1;
        unsigned int enemiesLoaded : 1;

        LoadStatus() : roomsLoaded(0), itemsLoaded(0), enemiesLoaded(0) {} // Initialize all to 0
    };

    static LoadStatus loadStatus;
public:
    static vector<Room*> importRoomData();
    static vector<Item*> importItemData();
    static vector<Enemy*> importEnemyData();
    static void printLoadStatus();
};

#endif //UNTITLED2_DATAHANDLER_H
