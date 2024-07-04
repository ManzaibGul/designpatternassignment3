#ifndef MONSTERFACTORY_H
#define MONSTERFACTORY_H

#include "GameObjectFactory.h"
#include "Monster.h"
#include "Treasure.h"
#include "Weapon.h"
#include <string>

class MonsterFactory : public GameObjectFactory {
public:
    Monster* create(const std::string& type, Treasure* treasure, Weapon* weapon) {
        if (type == "MEDUSA") {
            return new Monster("MEDUSA", weapon);
        } else if (type == "DRACULA") {
            return new Monster("DRACULA", weapon);
        }
        return nullptr;
    }
};

#endif // MONSTERFACTORY_H