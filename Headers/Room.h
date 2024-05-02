//
// Created by Josh Sloggett on 30/04/2024.
//

#ifndef UNTITLED2_ROOM_H
#define UNTITLED2_ROOM_H
#include<string>
#include "Runnable.h"
#include "Stage.h"
#include<vector>

using namespace std;

class Room : public Runnable{
private:
    int id;
    vector<Stage> stages;
    pair<int,int> location;
public:
    Room(int, vector<Stage>, pair<int,int>);
    void run() override;
};

#endif //UNTITLED2_ROOM_H
