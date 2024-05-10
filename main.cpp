#include <iostream>
#include "Headers/InputHandler.h"
//#include "Headers/Room.h"
#include "Headers/Player.h"
#include "Headers/DataHandler.h"
#include "utils.h"
#include "Headers/GameState.h"

void printInv(vector<Item> inv){
    bool equipped = false;
    for(Item i: inv){
        cout << i.getName() << endl;
        cout << i.getDescription() << endl;
        cout << "-------" << endl;
    }
}

int main() {
    GameState state = GameState();
    state.addToPlayer();
    state.update(make_pair(0,0));
    state.update(0);

    while(true){
        Room* current = state.getCurrentRoom();
        current->run();
    }
    return 0;
}


