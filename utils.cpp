//
// Created by Josh Sloggett on 02/05/2024.
//

#include "utils.h"

vector<Item> items = DataHandler::importItemData(); // Definition

Item getItemFromId(int id){
    for(Item i: items){
        if(i.getId() == id){
            return i;
        }
    }
    return items[0];
}

vector<Room> rooms = DataHandler::importRoomData();
Room getRoomFromLocation(pair<int,int> loc){
    for(Room room: rooms){
        if(room.getLoc().first == loc.first && room.getLoc().second == loc.second){
            return room;
        }
    }
    return rooms[0];
}