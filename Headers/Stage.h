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
    int id;
    string text;
    string type;
public:
    Stage(int, string, string);
    bool runStage() override;
};

#endif //UNTITLED2_STAGE_H
