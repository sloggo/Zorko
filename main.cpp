#include <iostream>
#include "Headers/InputHandler.h"
//#include "Headers/Room.h"
#include "Headers/Player.h"

//Room currentRoom;

void printInv(const vector<Item>& inv){
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

    return 0;
}


