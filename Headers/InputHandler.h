//
// Created by Josh Sloggett on 01/05/2024.
//

#ifndef UNTITLED2_INPUTHANDLER_H
#define UNTITLED2_INPUTHANDLER_H
#include<string>

using namespace std;

class InputHandler{
private:
    static InputHandler* instance; // Singleton
    vector<string> processedInput;
public:
    static void forceInput(string); // for ui in future

    static InputHandler* getInstance();

    void takeInInput();

    void processInput(string);

    vector<string> getProcessedInput();
};

#endif //UNTITLED2_INPUTHANDLER_H