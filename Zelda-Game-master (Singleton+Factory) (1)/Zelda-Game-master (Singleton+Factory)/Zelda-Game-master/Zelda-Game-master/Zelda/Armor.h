#ifndef ARMOR_H
#define ARMOR_H

#include "Treasure.h"

class Armor : public Treasure {
public:
    explicit Armor(const std::string& name)
        : Treasure(name, 0) {} // Assuming armor value is 0 or you can assign a specific value

    // Add additional methods and members as needed
};

#endif // ARMOR_H
