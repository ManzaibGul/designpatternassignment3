#ifndef MONSTER_H
#define MONSTER_H

#include "GameObject.h"
#include "Treasure.h"

class Monster : public GameObject {
private:
    std::string name;
    Treasure* guardedTreasure;

public:
    Monster(const std::string& name, Treasure* treasure)
        : name(name), guardedTreasure(treasure) {}

    // Add additional methods and members as needed
    std::string getName() const { return name; }
    Treasure* getGuardedTreasure() const { return guardedTreasure; }
};

#endif // MONSTER_H