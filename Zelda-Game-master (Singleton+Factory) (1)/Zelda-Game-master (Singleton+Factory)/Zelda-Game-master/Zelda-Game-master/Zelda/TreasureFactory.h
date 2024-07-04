#ifndef TREASUREFACTORY_H
#define TREASUREFACTORY_H

#include "GameObjectFactory.h"
#include "Treasure.h"
#include <string>

class TreasureFactory : public GameObjectFactory {
public:
    Treasure* create(const std::string& type) {
        if (type == "GOLDEN EGG") {
            return new Treasure("GOLDEN EGG", 500000);
        } else if (type == "GOLDEN CHALICE") {
            return new Treasure("GOLDEN CHALICE", 500000);
        } else if (type == "PROOF") {
            return new Treasure("PROOF", 1000000);
        }
        return nullptr;
    }
};

#endif // TREASUREFACTORY_H