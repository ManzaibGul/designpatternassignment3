#ifndef TREASURE_H
#define TREASURE_H

#include "GameObject.h"

class Treasure : public GameObject {
private:
    std::string name;
    int value;

public:
    Treasure(const std::string& name, int value)
        : name(name), value(value) {}

    // Add additional methods and members as needed
    std::string getName() const { return name; }
    int getValue() const { return value; }
};

#endif // TREASURE_H