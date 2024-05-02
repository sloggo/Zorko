#include <iostream>
#include "Headers/InputHandler.h"
//#include "Headers/Room.h"
#include "Headers/Player.h"
#include "Headers/DataHandler.h"

//Room currentRoom;

void printInv(vector<Item> inv){
    bool equipped = false;
    for(Item i: inv){
        cout << i.getName() << endl;
        cout << i.getDescription() << endl;
        cout << "-------" << endl;
    }
}

int main() {
    Player* plyr = Player::getInstance();

    Item i = *new Item("Potion", "Used to heal self.");

    plyr->pickup(i);
    vector<Item> inv = plyr->getInventory();
    printInv(inv);

    plyr->drop(i);
    inv = plyr->getInventory();
    printInv(inv);

    DataHandler d = DataHandler();
    vector<Room> data = d.importRoomData();

    data[0].run();

    return 0;
}


