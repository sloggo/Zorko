#include <iostream>
#include "Headers/InputHandler.h"
#include "Headers/Room.h"

Room currentRoom;

int main() {
    InputHandler* i = InputHandler::getInstance();

    i->processInput("go north");
    vector<string> testForce = i->getProcessedInput();

    cout << testForce[1] << endl;

    return 0;
}
