#ifndef ARMORFACTORY_H
#define ARMORFACTORY_H

#include "GameObjectFactory.h"
#include "Armor.h"
#include <string>

class ArmorFactory : public GameObjectFactory {
public:
    Armor* create(const std::string& type) {
        if (type == "HELMET") {
            return new Armor("HELMET");
        } else if (type == "CHESTPLATE") {
            return new Armor("CHESTPLATE");
        }
        return nullptr;
    }
};

#endif // ARMORFACTORY_H
