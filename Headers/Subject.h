//
// Created by Josh Sloggett on 30/04/2024.
//

#ifndef UNTITLED2_SUBJECT_H
#define UNTITLED2_SUBJECT_H
#include<vector>
#include "Observer.h"

using namespace std;

class Subject {
protected:
    vector<Observer*> observers;
public:
    void addObserver(Observer*);
    void removeObserver(Observer*);
    void update(pair<int,int>);
};

#endif //UNTITLED2_SUBJECT_H
