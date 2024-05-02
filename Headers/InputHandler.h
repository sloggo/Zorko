//
// Created by Josh Sloggett on 01/05/2024.
//

#ifndef UNTITLED2_INPUTHANDLER_H
#define UNTITLED2_INPUTHANDLER_H
#include<string>
#include"../Headers/Item.h"

using namespace std;

class InputHandler{
private:
    static InputHandler* instance; // Singleton
    vector<string> processedInput;
    void processMovement();
public:
    static void forceInput(string); // for ui in future

    static InputHandler* getInstance();

    void takeInInput(string, int);
    void processInput(string, string, int);

    vector<string> getProcessedInput();
    void processPickup(int);
};

#endif //UNTITLED2_INPUTHANDLER_H