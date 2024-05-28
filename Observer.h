//
// Created by Josh Sloggett on 30/04/2024.
//

#ifndef UNTITLED2_OBSERVER_H
#define UNTITLED2_OBSERVER_H

#include<string>
#include "Room.h"
#include<vector>

using namespace std;

class Observer{
private:
    int id;
public:
    Observer(int);
    virtual void update(pair<int,int>); // for updating location
    bool operator==(const Observer& a) const
    {
        return equals(a);
    }
    bool equals(Observer) const;
    void addToPlayer();
    virtual void update(int); // update stage
    virtual void updateR(Room*);
};

#endif //UNTITLED2_OBSERVER_H
