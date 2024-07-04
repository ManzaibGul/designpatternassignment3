#ifndef CASTLEFACTORY_H
#define CASTLEFACTORY_H

#include "GameObjectFactory.h"
#include "Castle.h"

class CastleFactory : public GameObjectFactory {
public:
    Castle* create() override {
        // Customize this according to your needs
        return new Castle();
    }
};

#endif // CASTLEFACTORY_H