//
// Created by Josh Sloggett on 30/04/2024.
//

#ifndef UNTITLED2_OBSERVER_H
#define UNTITLED2_OBSERVER_H

using namespace std;

class Observer{
private:
    int id;
public:
    Observer(int);
    void update(int,int); // for updating location
    bool operator==(const Observer& a) const
    {
        return equals(a);
    }
    bool equals(Observer) const;
};

#endif //UNTITLED2_OBSERVER_H
