#ifndef PRINCESSFACTORY_H
#define PRINCESSFACTORY_H

#include "GameObjectFactory.h"
#include "Princess.h"

class PrincessFactory : public GameObjectFactory {
public:
    Princess* create() override {
        // Customize this according to your needs
        return new Princess();
    }
};

#endif // PRINCESSFACTORY_H