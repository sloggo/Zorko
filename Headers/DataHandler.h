//
// Created by Josh Sloggett on 02/05/2024.
//

#ifndef UNTITLED2_DATAHANDLER_H
#define UNTITLED2_DATAHANDLER_H

#include "Room.h"
#include<iostream>
using namespace std;

class DataHandler{
public:
    static vector<Room> importRoomData();
    static vector<Item> importItemData();
};

#endif //UNTITLED2_DATAHANDLER_H
