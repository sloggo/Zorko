//
// Created by Josh Sloggett on 30/04/2024.
//

#ifndef UNTITLED2_ENEMY_H
#define UNTITLED2_ENEMY_H
#include<string>
#include "Battlable.h"
#include "Weapon.h"
using namespace std;

class Enemy: public Battlable{
private:
    int id;
    string name;
    vector<string> attackDialog;
    vector<string> hurtDialog;
    vector<string> deathDialog;
public:
    Enemy(Weapon, int, string, vector<string>, vector<string>, vector<string>);
    ~Enemy();
    int getId();
    string getName();
};

#endif //UNTITLED2_ENEMY_H
