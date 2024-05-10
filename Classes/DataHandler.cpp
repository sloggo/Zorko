//
// Created by Josh Sloggett on 02/05/2024.
//
#include "../Headers/DataHandler.h"
#include "../json.hpp"
#include<fstream>
#include<iostream>
#include"../Headers/Stage.h"
#include"../Headers/Room.h"
#include "../Headers/Weapon.h"
#include "../Headers/Potion.h"
#include "../Headers/Enemy.h"

using namespace std;
using json = nlohmann::json; // Alias for nlohmann::json

vector<Room*> DataHandler::importRoomData() {
    ifstream file("../rooms.json");

    if (!file.is_open()) {
        cerr << "Error: Unable to open rooms.json" << endl;
        return {}; // Return an empty vector to indicate failure
    }

    json jsonData;

    file >> jsonData;
    file.close();

    vector<Room*> rooms;

    for (json::iterator room = jsonData.begin(); room != jsonData.end(); ++room) {
        // Each room
        vector<Stage> stages;
        for (json::iterator stage = (*room)["stages"].begin(); stage != (*room)["stages"].end(); ++stage) {
            // Each stage

            Stage newStg = Stage((*stage)["id"], (*stage)["text"], (*stage)["type"]);
            stages.push_back(newStg);
        }

        Room* newRoom = new Room((*room)["id"], stages, make_pair((*room)["x"], (*room)["y"]));
        rooms.push_back(newRoom);
    }

    return rooms;
}

vector<Item> DataHandler::importItemData(){
    ifstream file("../items.json");

    if (!file.is_open()) {
        cerr << "Error: Unable to open items.json" << endl;
        return {}; // Return an empty vector to indicate failure
    }

    json jsonData;

    file >> jsonData;
    file.close();

    vector<Item> items;

    for (json::iterator item = jsonData.begin(); item != jsonData.end(); ++item) {
        // Each room
        if((*item)["type"] == "weapon"){
            Weapon newItem = Weapon((*item)["id"],(*item)["name"], (*item)["description"], (*item)["dmg"], (*item)["durability"]);
            items.push_back(newItem);
        } else if((*item)["type"] == "item"){
            Item newItem = Item((*item)["id"],(*item)["name"], (*item)["description"]);
            items.push_back(newItem);
        } else if((*item)["type"] == "heal"){
            Potion newItem = Potion((*item)["id"],(*item)["name"], (*item)["description"], (*item)["hp"]);
            items.push_back(newItem);
        }
    }

    return items;
}

vector<Enemy> DataHandler::importEnemyData(){
    ifstream file("../enemies.json");

    if (!file.is_open()) {
        cerr << "Error: Unable to open items.json" << endl;
        return {}; // Return an empty vector to indicate failure
    }

    json jsonData;

    file >> jsonData;
    file.close();

    vector<Enemy> enemies;

    for (json::iterator enemy = jsonData.begin(); enemy != jsonData.end(); ++enemy) {
        //destructor pointer example
        Weapon enemyWeapon = Weapon((*enemy)["weapon"]["id"],(*enemy)["weapon"]["name"], (*enemy)["weapon"]["description"], (*enemy)["weapon"]["dmg"], (*enemy)["weapon"]["durability"]);

        vector<string> attkDialog;
        for (json::iterator dialog = (*enemy)["attack_dialog"].begin(); dialog != (*enemy)["attack_dialog"].end(); ++dialog) {
            attkDialog.push_back(*dialog);
        }

        vector<string> hurtDialog;
        for (json::iterator dialog = (*enemy)["hurt_dialog"].begin(); dialog != (*enemy)["hurt_dialog"].end(); ++dialog) {
            hurtDialog.push_back(*dialog);
        }

        vector<string> deathDialog;
        for (json::iterator dialog = (*enemy)["death_dialog"].begin(); dialog != (*enemy)["death_dialog"].end(); ++dialog) {
            deathDialog.push_back(*dialog);
        }

        Enemy newEnemy = Enemy(enemyWeapon, (*enemy)["id"], (*enemy)["name"], attkDialog, hurtDialog, deathDialog);
        enemies.push_back(newEnemy);
    }

    return enemies;
}