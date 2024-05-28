//
// Created by Josh Sloggett on 30/04/2024.
//

#ifndef UNTITLED2_STAGE_H
#define UNTITLED2_STAGE_H
#include<string>
#include "Runnable.h"
#include "Item.h"

using namespace std;

class Stage : public Runnable{
private:
    string text;
    string type;
public:
    int id;
    Stage(int, string, string);
    bool runStage() override;
    string getText();
    void runUI() override;
    string getType();
};

#endif //UNTITLED2_STAGE_H
