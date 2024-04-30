//
// Created by Josh Sloggett on 30/04/2024.
//

#ifndef UNTITLED2_ENEMY_H
#define UNTITLED2_ENEMY_H
#include<string>
using namespace std;

class Enemy: public Battlable{
private:
    string name;
    vector<string> dialog;
public:
    Enemy(string, vector<string>);
    ~Enemy();
};

#endif //UNTITLED2_ENEMY_H
