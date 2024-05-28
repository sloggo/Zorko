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
public:
    static vector<Room*> importRoomData();
    static vector<Item*> importItemData();
    static vector<Enemy*> importEnemyData();

};

#endif //UNTITLED2_DATAHANDLER_H
