//
// Created by Josh Sloggett on 02/05/2024.
//
#include "../Headers/DataHandler.h"
#include "../json.hpp"
#include<fstream>
#include<iostream>
#include"../Headers/Stage.h"
#include"../Headers/Room.h"

using namespace std;
using json = nlohmann::json; // Alias for nlohmann::json

vector<Room> DataHandler::importRoomData() {
    ifstream file("../rooms.json");

    if (!file.is_open()) {
        cerr << "Error: Unable to open rooms.json" << endl;
        return {}; // Return an empty vector to indicate failure
    }

    json jsonData;

    file >> jsonData;
    file.close();

    vector<Room> rooms;

    for (json::iterator room = jsonData.begin(); room != jsonData.end(); ++room) {
        // Each room
        cout << (*room) << endl;

        vector<Stage> stages;
        for (json::iterator stage = (*room)["stages"].begin(); stage != (*room)["stages"].end(); ++stage) {
            // Each stage
            cout << (*stage) << endl;
            Stage newStg = Stage((*stage)["id"], (*stage)["text"], (*stage)["type"]);
            stages.push_back(newStg);
        }

        Room newRoom = Room((*room)["id"], stages, make_pair((*room)["x"], (*room)["y"]));
        rooms.push_back(newRoom);
    }

    return rooms;
}