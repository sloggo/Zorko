//
// Created by Josh Sloggett on 01/05/2024.
//

#ifndef UNTITLED2_INPUTHANDLER_H
#define UNTITLED2_INPUTHANDLER_H
#include<string>
#include"Item.h"
#include <vector>

using namespace std;

class InputHandler{
private:
    static InputHandler* instance; // Singleton
    vector<string> processedInput;
    bool processMovement(string);
public:
    static void forceInput(string); // for ui in future

    static InputHandler* getInstance();

    bool takeInInput(string, int);
    string takeInInput(string);
    bool processInput(string, string, int);

    vector<string> getProcessedInput();
    void processPickup(int);
    bool processUI(string);
};

#endif //UNTITLED2_INPUTHANDLER_H
