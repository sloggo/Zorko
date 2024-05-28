//
// Created by Josh Sloggett on 02/05/2024.
//

#ifndef UNTITLED2_UTILS_H
#define UNTITLED2_UTILS_H

#include "Item.h"
#include "DataHandler.h"

Item* getItemFromId(int id);
Room* getRoomFromLocation(pair<int,int>);
Enemy* getEnemyFromId(int id);
Stage* getStage(pair<int,int>, int);


#endif //UNTITLED2_UTILS_H
