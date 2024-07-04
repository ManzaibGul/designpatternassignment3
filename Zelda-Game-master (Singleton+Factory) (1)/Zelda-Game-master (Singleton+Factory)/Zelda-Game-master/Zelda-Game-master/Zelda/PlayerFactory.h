#ifndef PLAYERFACTORY_H
#define PLAYERFACTORY_H

#include "GameObjectFactory.h"
#include "Player.h"

class PlayerFactory : public GameObjectFactory {
public:
    Player* create() override {
        // Customize this according to your needs
        return new Player("Default Player", nullptr); // Placeholder room pointer
    }
};

#endif // PLAYERFACTORY_H