//
// Created by Josh Sloggett on 02/05/2024.
//
#include <unistd.h>
#include "DataHandler.h"
#include "json.hpp"
#include<fstream>
#include<iostream>
#include "Stage.h"
#include "Room.h"
#include "Weapon.h"
#include "Potion.h"
#include "Enemy.h"
#include "jsonloadexception.h"
using namespace std;
using json = nlohmann::json;
DataHandler::LoadStatus DataHandler::loadStatus;


vector<Room*> DataHandler::importRoomData() {
    ifstream file("/Users/joshsloggett/Zorko2/rooms.json");

    if (!file.is_open()) {
        cerr << "Error: Unable to open rooms.json" << endl;
        throw JsonLoadException("Failed to parse the rooms JSON file.");
        // Get the current working directory
        char cwd[PATH_MAX];
        if (!getcwd(cwd, sizeof(cwd))) {
            perror("getcwd() error");
            return {};
        }
        cout << "Current working directory: " << cwd << endl;
        return {}; // Return an empty vector to indicate failure
    }




    json jsonData;

    file >> jsonData;
    file.close();

    vector<Room*> rooms;

    for (json::iterator room = jsonData.begin(); room != jsonData.end(); ++room) {
        // Each room
        vector<Stage*> stages;
        for (json::iterator stage = (*room)["stages"].begin(); stage != (*room)["stages"].end(); ++stage) {
            // Each stage

            Stage* newStg = new Stage((*stage)["id"], (*stage)["text"], (*stage)["type"]);
            stages.push_back(newStg);
        }

        Room* newRoom = new Room((*room)["id"], stages, make_pair((*room)["x"], (*room)["y"]));
        rooms.push_back(newRoom);
    }

    loadStatus.roomsLoaded = 1;
    printLoadStatus();

    return rooms;
}

vector<Item*> DataHandler::importItemData(){
    ifstream file("/Users/joshsloggett/Zorko2/items.json");

    if (!file.is_open()) {
        cerr << "Error: Unable to open items.json" << endl;
        throw JsonLoadException("Failed to parse the items JSON file.");
        return {}; // Return an empty vector to indicate failure
    }

    json jsonData;

    file >> jsonData;
    file.close();

    vector<Item*> items;

    for (json::iterator item = jsonData.begin(); item != jsonData.end(); ++item) {
        // Each room
        if((*item)["type"] == "weapon"){
            Weapon* newItem = new Weapon((*item)["id"],(*item)["name"], (*item)["description"], (*item)["dmg"], (*item)["durability"]);
            items.push_back(newItem);
        } else if((*item)["type"] == "item"){
            Item* newItem = new Item((*item)["id"],(*item)["name"], (*item)["description"]);
            items.push_back(newItem);
        } else if((*item)["type"] == "heal"){
            Potion* newItem = new Potion((*item)["id"],(*item)["name"], (*item)["description"], (*item)["hp"]);
            items.push_back(newItem);
        }
    }

    loadStatus.itemsLoaded = 1;
    printLoadStatus();

    return items;
}

vector<Enemy*> DataHandler::importEnemyData(){
    ifstream file("/Users/joshsloggett/Zorko2/enemies.json");

    if (!file.is_open()) {
        cerr << "Error: Unable to open enemies.json" << endl;
        throw JsonLoadException("Failed to parse the enemies JSON file.");
        return {}; // Return an empty vector to indicate failure
    }

    json jsonData;

    file >> jsonData;
    file.close();

    vector<Enemy*> enemies;

    for (json::iterator enemy = jsonData.begin(); enemy != jsonData.end(); ++enemy) {
        //destructor pointer example
        Weapon* enemyWeapon = new Weapon((*enemy)["weapon"]["id"],(*enemy)["weapon"]["name"], (*enemy)["weapon"]["description"], (*enemy)["weapon"]["dmg"], (*enemy)["weapon"]["durability"]);

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

        Enemy* newEnemy = new Enemy(enemyWeapon, (*enemy)["id"], (*enemy)["name"], attkDialog, hurtDialog, deathDialog);
        enemies.push_back(newEnemy);
    }

    loadStatus.enemiesLoaded = 1;
    printLoadStatus();
    return enemies;
}

void DataHandler::printLoadStatus(){
    cout << "Rooms loaded: "<< loadStatus.roomsLoaded << endl;
    cout << "Enemies loaded: "<< loadStatus.enemiesLoaded << endl;
    cout << "Items loaded: "<< loadStatus.itemsLoaded << endl;
}
