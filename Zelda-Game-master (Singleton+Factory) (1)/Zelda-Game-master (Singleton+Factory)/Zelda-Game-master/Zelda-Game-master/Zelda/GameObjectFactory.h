#ifndef GAMEOBJECTFACTORY_H
#define GAMEOBJECTFACTORY_H

class GameObject;

class GameObjectFactory {
public:
    virtual GameObject* create() = 0;
    virtual ~GameObjectFactory() = default;
};

#endif // GAMEOBJECTFACTORY_H