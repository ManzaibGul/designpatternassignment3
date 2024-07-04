#ifndef WEAPON_H
#define WEAPON_H

#include "Treasure.h"

class Weapon : public Treasure {
public:
    Weapon(const std::string& name)
        : Treasure(name, 0) {} // Assuming weapon value is 0 or you can assign a specific value

    // Add additional methods and members as needed
};

#endif // WEAPON_H