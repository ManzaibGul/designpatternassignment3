#ifndef WEAPONFACTORY_H
#define WEAPONFACTORY_H

#include "GameObjectFactory.h"
#include "Weapon.h"
#include <string>

class WeaponFactory : public GameObjectFactory {
public:
    Weapon* create(const std::string& type) {
        if (type == "SHIELD") {
            return new Weapon("SHIELD");
        } else if (type == "DAGGER") {
            return new Weapon("DAGGER");
        }
        return nullptr;
    }
};

#endif // WEAPONFACTORY_H