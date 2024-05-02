//
// Created by Josh Sloggett on 30/04/2024.
//

#ifndef UNTITLED2_ITEM_H
#define UNTITLED2_ITEM_H
#include<string>

using namespace std;

class Item{
protected:
    string name;
    string description;
    int id;
public:
    bool equals(const Item&) const;
    bool operator==(const Item& a) const
    {
        return equals(a);
    }

    Item(int, string, string);
    virtual void use();

    string getName();
    string getDescription();

    int getId();
};

#endif //UNTITLED2_ITEM_H
