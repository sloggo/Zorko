//
// Created by Josh Sloggett on 30/04/2024.
//

#ifndef UNTITLED2_PLAYER_H
#define UNTITLED2_PLAYER_H

#include<string>
#include<vector>

using namespace std;

class Player {
private:
    string name
    Item[] inventory;
    vector<Observer> observers;
public:
    string getName();
    void setName(string);

    void move(int, int);
    void pickup(Item);
    void drop(Item);
};


#endif //UNTITLED2_PLAYER_H
