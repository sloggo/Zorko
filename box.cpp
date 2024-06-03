#include "Box.h"

template <typename T>
Box<T>::Box(T val) : value(val) {}

template <typename T>
void Box<T>::setValue(T val) {
    value = val;
}

template <typename T>
T Box<T>::getValue() const {
    return value;
}

template <typename T>
void Box<T>::printValue() const {
    cout << "Value: " << value << endl;
}
