#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"
#include "Room.h"
#include "Armor.h"

class Player : public GameObject {
private:
    std::string name;
    Room* currentRoom;
    Armor* equippedArmor; // Add this line

public:
    Player();
    Player(const std::string& name, Room* startingRoom);

    void setName(const std::string& name);
    std::string getName() const;

    void setCurrentRoom(Room* room);
    Room* getCurrentRoom() const;

    void equipArmor(Armor* armor); // Add this method
    Armor* getEquippedArmor() const; // Add this method

    void move(char direction);
    void attack();
    void defend();
    bool hasWon() const;
};

#endif // PLAYER_H
