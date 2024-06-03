#ifndef BOX_H
#define BOX_H

#include <iostream>
using namespace std;

template <typename T>
class Box {
private:
    T value;

public:
    Box(T val);
    void setValue(T val);
    T getValue() const;
    void printValue() const;
};

#endif // BOX_H

