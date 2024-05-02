#include <iostream>
#include "Headers/InputHandler.h"
//#include "Headers/Room.h"
#include "Headers/Player.h"

//Room currentRoom;

int main() {
    Player* plyr = Player::getInstance();

    plyr->pickup(*new Item("Potion", "Used to heal self."));

    vector<Item> inv = plyr->getInventory();

    for(Item i: inv){
        cout << i.getName() << endl;
        cout << i.getDescription() << endl;
        cout << "-------" << endl;
    }
    return 0;
}
