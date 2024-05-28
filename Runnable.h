//
// Created by Josh Sloggett on 30/04/2024.
//

#ifndef UNTITLED2_RUNNABLE_H
#define UNTITLED2_RUNNABLE_H

using namespace std;

class Runnable{
public:
    virtual void run();
    virtual bool runStage();
    virtual void runUI();
};

#endif //UNTITLED2_RUNNABLE_H
