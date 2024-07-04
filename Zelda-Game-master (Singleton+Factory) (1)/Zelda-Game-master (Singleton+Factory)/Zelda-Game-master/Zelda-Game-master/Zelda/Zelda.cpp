#include "pch.h"
#include "Zelda.h"
#include "Player.h"
#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <fstream>
#include "ArmorFactory.h"
#include "TreasureFactory.h"
#include "WeaponFactory.h"
#include "MonsterFactory.h"
#include "PlayerFactory.h"
#include "PrincessFactory.h"
#include "CastleFactory.h"

using namespace std;

/*Some COLOR Constants*/
const int RED = 12;
const int PURPLE = 13;
const int GREEN = 10;
const int AQUA = 11;
const int YELLOW = 14;
const int WHITE = 15;
const int BLUE = 9;


//---------------------Helper Functions------------------------



void HelperFunctions::charactersCase(char* input)
{
	for (int i = 0; input[i]!='\0'; ++i)
	{
		if(input[i] >= 'a' && input[i] <= 'z')
		{
			input[i] = input[i] - 32;
		}
	}
}



void HelperFunctions::color(int k)
{
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, k);
}



//---------------------Item------------------------


Item::Item()
{
	name = nullptr;
}



Item::~Item()
{
	if(name)
		delete[] name;
}



char* Item::getItemName()
{
	return name;
}



//---------------------Treasure------------------------



Treasure::Treasure()
{
	worth = 0;
}



Treasure::~Treasure()
{

}



Treasure::Treasure(char const* treasure_Name , int treasure_Worth)
{
	name = new char [strlen (treasure_Name) + 1];
	strcpy_s(name,strlen (treasure_Name) + 1, treasure_Name);

	worth = treasure_Worth;
}



int Treasure::getWorth()
{
	return worth;
}



//---------------------Weapon------------------------



Weapon::Weapon()
{

}



Weapon::~Weapon()
{

}



Weapon::Weapon(char const* weapon_Name)
{
	name = new char [strlen (weapon_Name) + 1];
	strcpy_s (name, strlen (weapon_Name) + 1, weapon_Name);
}



int Weapon::getWorth()
{
	return 0;
}


//----------STRATEGY PATTERN INTERFACES DECLARATION------------------------
class AttackStrategy {
public:
    virtual void attack() = 0;
    virtual ~AttackStrategy() = default;
};

class ShieldAttack : public AttackStrategy {
public:
    void attack() override {
        std::cout << "Performing shield attack!" << std::endl;
    }
};

class DaggerAttack : public AttackStrategy {
public:
    void attack() override {
        std::cout << "Performing dagger attack!" << std::endl;
    }
};

class MagicAttack : public AttackStrategy {
public:
    void attack() override {
        std::cout << "Performing magic attack using proof!" << std::endl;
    }
};

//---------------------Monster------------------------

Monster::Monster()
{
	name = nullptr;
	is_Alive = true;
	killing_weapon = nullptr;
}

Monster::~Monster()
{
	if(name)
		delete[] name;
}

Monster::Monster(char const* monster_Name, Item* weapon)
{
	name = new char [strlen(monster_Name) + 1];
	strcpy_s (name,strlen (monster_Name) + 1, monster_Name);

	is_Alive = true;
	killing_weapon = weapon;
}

Item* Monster::getKillingWeapon()
{
	return killing_weapon;
}

void Monster::setKillingWeapon(Item* item)
{
	killing_weapon = item;
}

bool Monster::getLivingState()
{
	return is_Alive;
}

void Monster::setLivingState(bool currentState)
{
	is_Alive = currentState;
}

char* Monster::getMonsterName()
{
	return name;
}

//---------------------Princess------------------------

Princess::Princess()
{
	is_Alive = true;
}



Princess::~Princess()
{

}



bool Princess::getLivingState()
{
	return is_Alive;
}



void Princess::setLivingState(bool currentState)
{
	is_Alive = currentState;
}



//---------------------Room------------------------



Room::Room()
{
	for (int i = 0; i < 4; ++i)
	{
		paths[i] = nullptr;
	}

	for (int i = 0; i < 5; ++i)
	{
		items_Present[i] = nullptr;
	}

	monster_Present  = nullptr;
	princess_Present = nullptr;

	description 	 = nullptr;
	roomNumber 		 = 0;
}



Room::~Room()
{
	if(description)
		delete[] description;
}



int Room::directionIndex(char const* direction)
{
	int i = 0;
	if(strcmp(direction , "NORTH") == 0)
		i = 0;

	else if(strcmp (direction, "SOUTH") == 0)
		i = 1;

	else if(strcmp (direction, "EAST") == 0)
		i = 2;

	else if(strcmp (direction, "WEST") == 0)
		i = 3;

	return i;
}



char* Room::directionName(int i)
{
	char* buffer = new char [10];

	if( i == 0)
		strcpy_s(buffer,10, "North");

	else if(i == 1)
		strcpy_s(buffer,10, "South");

	else if(i == 2)
		strcpy_s(buffer,10, "East");

	else if(i == 3)
		strcpy_s(buffer,10, "West");

	return buffer;
}



bool Room::isRoomFull()
{
	for (int i = 0; i < 5; ++i)
	{
		if (items_Present[i] == nullptr)
		{
			return false;
		}
	}

	return true;
}



//Getters



Room** Room::getPaths()
{
	return paths;
}



Item** Room::getItemsPresent()
{
	return items_Present;
}



Monster* Room::getMonsterPresent()
{
	return monster_Present;
}



Princess* Room::getPrincessPresent()
{
	return princess_Present;
}



char* Room::getDescription()
{
	return description;
}



int Room::getRoomNumber()
{
	return roomNumber;
}




// paths[0] = North
// paths[1] = South
// paths[2] = East
// paths[3] = West



void Room::setNorth(Room* roomNo)
{
	paths[0] = roomNo;
}



void Room::setSouth(Room* roomNo)
{
	paths[1] = roomNo;
}



void Room::setEast(Room* roomNo)
{
	paths[2] = roomNo;
}



void Room::setWest(Room* roomNo)
{
	paths[3] = roomNo;
}



void Room::setItemsPresent(int itemNo , Item* item)
{
	items_Present[itemNo] = item;
}



void Room::setMonsterPresent(Monster* monster)
{
	monster_Present = monster;
}



void Room::setPrincessPresent(Princess* princess)
{
	princess_Present = princess;
}



void Room::setDesription(char const* room_Description)
{
	description = new char [strlen(room_Description)+1];
	strcpy_s(description,strlen(room_Description)+1,room_Description);
}



void Room::setRoomNumber(int roomNo)
{
	roomNumber = roomNo;
}



//---------------------Castle------------------------



Castle::Castle()
{

}



Room* Castle::getRoom( int room_No )
{
	return &rooms[room_No - 1];
}



void Castle::LinkRoomsWithOtherThings(Item** items , Monster** monsters , Princess* princess)
{
	//Room1
	rooms[0].setSouth(&rooms[3]);
	rooms[0].setEast(&rooms[1]);
	//room1.west = Exit from castle


	//Room2
	rooms[1].setWest(&rooms[0]);
	rooms[1].setEast(&rooms[2]);
	rooms[1].setSouth(&rooms[4]);

	rooms[1].setItemsPresent(0 , items[0]);


	//Room3
	rooms[2].setWest(&rooms[1]);
	rooms[2].setItemsPresent(0 , items[3]);


	//Room4
	rooms[3].setNorth(&rooms[0]);
	rooms[3].setItemsPresent(0 , items[1]);


	//Room5
	rooms[4].setNorth(&rooms[1]);
	rooms[4].setEast(&rooms[5]);

	rooms[4].setMonsterPresent( monsters[0] );


	//Room6
	rooms[5].setWest(&rooms[4]);

	rooms[5].setMonsterPresent( monsters[1] );


	//Room7
	rooms[6].setEast(&rooms[7]);
	rooms[6].setItemsPresent(0 , items[4]);


	//Room8
	rooms[7].setWest(&rooms[6]);
	rooms[7].setNorth(&rooms[4]);

	rooms[7].setItemsPresent(0 , items[2]);


	//Room9
	rooms[8].setNorth(&rooms[5]);
	rooms[8].setPrincessPresent(princess);
}



void Castle::LinkRoom5and8()
{
	rooms[4].setSouth(&rooms[7]);
	rooms[7].setNorth(&rooms[4]);
}



void Castle::LinkRoom6and9()
{
	rooms[5].setSouth(&rooms[8]);
	rooms[8].setNorth(&rooms[5]);
}



void Castle::HiddenRoomsUnlocker(char const* monsterName , Monster** monsters)
{
	if (strcmp(monsterName , (monsters[0]->getMonsterName())) == 0)
	{
		LinkRoom5and8();
	}

	else if (strcmp(monsterName , (monsters[1]->getMonsterName())) == 0)
	{
		LinkRoom6and9();
	}
}



void Castle::setDescriptionOfRooms()
{
	ifstream InputStream("Rooms.txt");
	if (InputStream.is_open())
	{
		char buffer[300];

		for (int i = 0; i < 9 && !InputStream.eof(); ++i)
		{
			InputStream.getline(buffer,300);
			rooms[i].setDesription(buffer);
		}
	}
	else
		cout << "Could not open file";
	InputStream.close();
}



void Castle::setNumbersofRooms()
{
	for (int i = 0; i < 9; ++i)
	{
		rooms[i].setRoomNumber(i+1);
	}
}



Castle::~Castle()
{

}

//-------------------Player---------------------

Player::Player(char const* player_Name , Room* room1 )
{
	name = new char [strlen(player_Name) + 1];
	strcpy_s (name,strlen(player_Name) + 1, player_Name);

	current_Room = room1;
	princess_Pointer = nullptr;
	is_Alive = true;
	cash = 0;

	for (int i = 0; i < 10; ++i)
	{
		bag[i] = nullptr;
	}

	AttackStrategy* attackStrategy;  // Add attack strategy pointer
    GameState* currentState; // Add game state pointer
    std::map<std::string, AttackStrategy*> attackStrategies;
}



Player::Player()
{
    currentState = new PlayingState();
}

Player() : attackStrategy(nullptr) {
        attackStrategies["dracula"] = new DaggerAttack();
        attackStrategies["medusa"] = new ShieldAttack();
        attackStrategies["princess"] = new MagicAttack();
    }


Player::~Player()
{
	if (name)
	{
		delete[] name;
	}
}



bool Player::getCurrentState()
{
	return is_Alive;
}



Player::setCurrentState(bool currentState)
{
	is_Alive = currentState;
}



Princess* Player::getPrincess_Pointer()
{
	return princess_Pointer;
}



char* Player::getPlayerName()
{
	return name;
}



Player::CashUpdater()
{
	cash = 0;

	for (int i = 0; i < 10; ++i)
	{
		if(bag[i])
		{
			cash = cash + bag[i]->getWorth();
		}
	}
}

//NEW FACTORY START

Player::Player() : currentRoom(nullptr), equippedArmor(nullptr) {}

Player::Player(const std::string& name, Room* startingRoom) 
    : name(name), currentRoom(startingRoom), equippedArmor(nullptr) {}

void Player::setName(const std::string& name) {
    this->name = name;
}

std::string Player::getName() const {
    return name;
}

void Player::setCurrentRoom(Room* room) {
    currentRoom = room;
}

Room* Player::getCurrentRoom() const {
    return currentRoom;
}

void Player::equipArmor(Armor* armor) {
    equippedArmor = armor;
}

Armor* Player::getEquippedArmor() const {
    return equippedArmor;
}

// NEW FACTORY ENDED


int Player::getCash()
{
	return cash;
}



bool Player::isBagEmpty()
{
	for (int i = 0; i < 10; ++i)
	{
		if(bag[i] != nullptr)
			return false;
	}

	return true;
}



bool Player::isBagFull()
{
	bool bag_Full = true;

	for (int i = 0; i < 10 && bag_Full; ++i)
	{
		if(bag[i] == nullptr)
			bag_Full = false;
	}

	return bag_Full;
}

bool Player::Play() {
    currentState->Play(this);
}

bool Player::ChangeState(GameState* newState) {
    delete currentState;
    currentState = newState;
}

bool Player::loseGame() {
    GameState* endLoseState = new EndLoseState();
    ChangeState(endLoseState);
}

bool Player::Move(char const* direction , bool& exit_Castle)
{
	bool moveSuccessful = false;
	int i = 0;

	i = current_Room->directionIndex(direction);

	if ((i == 3) && ((current_Room->getRoomNumber()) == 1))
	{
		exit_Castle = true;
	}

	else if((current_Room->getPaths())[i] != nullptr)
	{
		current_Room   = (current_Room->getPaths())[i];
		moveSuccessful = true;

		if(current_Room->getPrincessPresent())
		{
			HelperFunctions::color(AQUA);
			cout << "The Princess is standing , waiting for you in the dark . ";
			princess_Pointer= current_Room->getPrincessPresent();
			current_Room->setPrincessPresent(nullptr);
		}

		HelperFunctions::color(RED);
		cout << "\nYou have successfully been moved to Room : " << current_Room->getRoomNumber();
	}

	else
	{
		HelperFunctions::color(RED);
		cout << "\nMOVE " << direction <<" is an invalid command.";
	}

	return moveSuccessful;
}

void Player::Pick(char const* itemName)
{
	bool picked = false;
	bool itemFound = false;

	for (int i = 0; i < 5; ++i)
	{
		if((current_Room->getItemsPresent())[i] != nullptr)
		{
			if(	strcmp((((current_Room->getItemsPresent())[i])->getItemName()) , itemName) == 0)
			{
				itemFound = true;

				if (!isBagFull())
				{
					int j = 0;

					for (; bag[j] != nullptr; ++j)
					{

					}

					bag[j] =  (current_Room->getItemsPresent())[i];
					current_Room->setItemsPresent(i , nullptr);

					picked = true;

					CashUpdater();
				}
				else
					cout << "\nSorry , your bag is already full.";
			}
		}
	}

	HelperFunctions::color(RED);
	if(picked)
		cout <<endl << itemName << " has successfully been picked.";

	else if(itemFound == false)
		cout <<endl << itemName <<" is not present in this room.";
}

void Player::Drop(char const* itemName)
{
	bool dropped = false;
	bool item_in_bag = false;

	for (int i = 0; i < 10; ++i)
	{
		if(bag[i] != NULL)
		{
			if(	strcmp((bag[i])->getItemName() , itemName) == 0)
			{
				item_in_bag = true;

				if(!(current_Room-> isRoomFull()))
				{
					int j = 0;

					for (; (current_Room->getItemsPresent())[j] != nullptr; ++j)
					{

					}

					current_Room->setItemsPresent(j , bag[i]);
					bag[i] = nullptr;

					dropped = true;

					CashUpdater();
				}
				else
				{
					HelperFunctions::color(AQUA);
					cout << "/n/The item" << itemName << " couldn't be dropped as Room "<<current_Room->getRoomNumber()
						 << " is already full.";
				}
			}
		}
	}

	HelperFunctions::color(YELLOW);

	if(dropped)
		cout << endl<< itemName <<" has successfully been dropped.";

	else if(item_in_bag == false)
		cout << endl << itemName <<" couldn't be dropped as it is not present in your bag.";
}

  // Strategy pattern methods
    setAttackStrategy(AttackStrategy* strategy) {
        attackStrategy = strategy;
    }

    performAttack() {
        if (attackStrategy) {
            attackStrategy->attack();
        }
    }

// bool Player::Attack(char const* monsterName) {
//     bool killed = false;

//     if (current_Room->getMonsterPresent() != nullptr) {p
//         if ((current_Room->getMonsterPresent())->getLivingState() == true) {
//             performAttack();  // Use the strategy to attack
//             killed = true;

//             (current_Room->getMonsterPresent())->setLivingState(false);
//             HelperFunctions::color(RED);
//             std::cout << monsterName << " has been killed. " << std::endl;
//         } else {
//             HelperFunctions::color(RED);
//             std::cout << monsterName << " is already dead." << std::endl;
//         }
//     } else {
//         HelperFunctions::color(RED);
//         std::cout << monsterName << " is not present in this room." << std::endl;
//     }

//     return killed;
// }

bool Attack(const char* monsterName) {
        bool killed = false;

        if (current_Room->getMonsterPresent() != nullptr) {
            if ((current_Room->getMonsterPresent())->getLivingState() == true) {
                // Set the attack strategy based on monsterName
                auto it = attackStrategies.find(monsterName);
                if (it != attackStrategies.end()) {
                    setAttackStrategy(it->second);
                    performAttack();  // Use the strategy to attack
                    killed = true;
                } else {
                    HelperFunctions::color(RED);
                    std::cout << "No specific attack strategy found for " << monsterName << std::endl;
                }

                (current_Room->getMonsterPresent())->setLivingState(false);
                HelperFunctions::color(RED);
                std::cout << monsterName << " has been killed using strategies" << std::endl;
            } else {
                HelperFunctions::color(RED);
                std::cout << monsterName << " is already dead." << std::endl;
            }
        } else {
            HelperFunctions::color(RED);
            std::cout << monsterName << " is not present in this room." << std::endl;
        }

        return killed;
    }

void Player::Look()
{
	HelperFunctions::color(RED);
	cout << "\nCurrently you are in Room "<<current_Room->getRoomNumber()<<". ";
	cout << current_Room->getDescription();

	for (int i = 0; i < 4; ++i)
	{
		HelperFunctions::color(AQUA);
		if ((current_Room->getPaths())[i] != NULL)
			cout << " There is a room to your " << current_Room->directionName(i)<<" .";
	}

	for (int i = 0; i < 5; ++i)
	{
		HelperFunctions::color(WHITE);
		if ((current_Room->getItemsPresent())[i] != NULL)
			cout << " The " << ((current_Room->getItemsPresent())[i])->getItemName() << " is lying on the floor .";
	}

	if(current_Room->getMonsterPresent() != NULL)
	{
		HelperFunctions::color(RED);
		if((current_Room->getMonsterPresent())->getLivingState() == true)
			cout << (current_Room->getMonsterPresent())->getMonsterName()  << " is waiting to kill you beside a locked door.";
		else
			cout << (current_Room->getMonsterPresent())->getMonsterName()  << " is lying dead on the floor.";
	}

	HelperFunctions::color(PURPLE);
	if(princess_Pointer)
		cout << " You have Princess along with you finally saved using magic attack strategy .";

	HelperFunctions::color(GREEN);
	cout << "\nYour bag contains the following items : ";


	if(!isBagEmpty())
	{
		for (int i = 0; i < 10; ++i)
		{
			if (bag[i])
				cout << endl << bag[i] -> getItemName();
		}
	}
	else
		cout << "\nCurrently, your bag is empty.";

	HelperFunctions::color(BLUE);
	cout <<"\nCurrent Cash is : " << getCash();
}

void Player::Exit()
{
	HelperFunctions::color(WHITE);
	cout << "Thankyou " << getPlayerName() <<" for playing Zelda.\nThe game is now exiting .........";
}


//--------------------------GameState Interfaces------------------------------------------
class GameState {
public:
    virtual void Play(Game* game) = 0;
    virtual void Move(Game* game, const char* direction, bool& exitCastle) = 0;
    virtual void Pick(Game* game, const char* itemName) = 0;
    virtual void Drop(Game* game, const char* itemName) = 0;
    virtual void Look(Game* game) = 0;
    virtual void Attack(Game* game, const char* monsterName, const char* weaponName) = 0;
    virtual void Exit(Game* game, bool& exitCastle) = 0;
    virtual ~GameState() = default;
};

// Concrete state classes
class PlayingState : public GameState 
{
public:
    Play(Game* game) override 
    {
        cout <<"\n\n\n\n";
    char s[300] = "\t\t\t#####################################################\n"
                   "\t\t\t#                                                   #\n"
                   "\t\t\t#                  Text Based Game                  #\n"
                   "\t\t\t#                                                   #\n"
                   "\t\t\t#####################################################";

    HelperFunctions::color(RED);
    cout << s;
    cout <<"\n\n\n";
    displayStory();

    char functionName[30];
    bool exit_Castle = false;
    playerPtr->Look();

    do
    {
        HelperFunctions::color(YELLOW);
        cout << "\n\nWhat do you want to do : ";

        char fullCommand[30];
        cin.getline(fullCommand,30);

        //Converting all the characters of fullCommand to UpperCase
        HelperFunctions::charactersCase(fullCommand);

        char command[15];

        int i = 0;

        for (i = 0; fullCommand[i] != '\0' && fullCommand[i] != ' '; ++i)
        {
            functionName[i] = fullCommand[i];
        }

        functionName[i] = '\0';
    }
    }

    Move(Game* game, const char* direction, bool& exitCastle) override 
    {
        if ( strcmp(functionName,    "MOVE") == 0)
        {
            if (playerPtr-> Move(command , exit_Castle))
                playerPtr->Look();

            if (exit_Castle == true)
            {
                    gameCheck();
            }
        }
    }

    Pick(Game* game, const char* itemName) override {
        if ( strcmp(functionName,    "PICK") == 0)
        playerPtr->Pick(command);
    }

    Drop(Game* game, const char* itemName) override {
        if ( strcmp(functionName,    "DROP") == 0)
        playerPtr->Drop(command);
    }

    Look(Game* game) override {
        if ( strcmp(functionName,    "LOOK") == 0)
            playerPtr->Look();

    }

    Attack(Game* game, const char* monsterName, const char* weaponName) override {
        else if ( strcmp(functionName,   "ATTACK") == 0)
        {
            if(playerPtr->Attack(command))
            {
                castlePtr->HiddenRoomsUnlocker(command , monstersPtr);
            }
            else if(playerPtr->getCurrentState() == false)
                PlayerDead();
        }
    }

    Exit(Game* game, bool& exitCastle) override {
        else if(strcmp (functionName , "EXIT") == 0)
        {
            playerPtr->Exit();
        }
    }
};

class EndWinState : public GameState 
{
public:
    Play(Game* game) override 
    {
        cout <<"\n\n\n\n";
    char s[300] = "\t\t\t#####################################################\n"
                   "\t\t\t#                                                   #\n"
                   "\t\t\t#                  Text Based Game                  #\n"
                   "\t\t\t#                                                   #\n"
                   "\t\t\t#####################################################";

    HelperFunctions::color(RED);
    cout << s;
    cout <<"\n\n\n";
    displayStory();

    char functionName[30];
    bool exit_Castle = false;
    playerPtr->Look();

    do
    {
        HelperFunctions::color(YELLOW);
        cout << "\n\nWhat do you want to do : ";

        char fullCommand[30];
        cin.getline(fullCommand,30);

        //Converting all the characters of fullCommand to UpperCase
        HelperFunctions::charactersCase(fullCommand);

        char command[15];

        int i = 0;

        for (i = 0; fullCommand[i] != '\0' && fullCommand[i] != ' '; ++i)
        {
            functionName[i] = fullCommand[i];
        }

        functionName[i] = '\0';
    }
    }

    Move(Game* game, const char* direction, bool& exitCastle) override 
    {
        if ( strcmp(functionName,    "MOVE") == 0)
        {
            if (playerPtr-> Move(command , exit_Castle))
                playerPtr->Look();

            if (exit_Castle == true)
            {
                    gameCheck();
            }
        }
    }

    Pick(Game* game, const char* itemName) override {
        if ( strcmp(functionName,    "PICK") == 0)
        playerPtr->Pick(command);
    }

    Drop(Game* game, const char* itemName) override {
        if ( strcmp(functionName,    "DROP") == 0)
        playerPtr->Drop(command);
    }

    Look(Game* game) override {
        if ( strcmp(functionName,    "LOOK") == 0)
            playerPtr->Look();

    }

    Attack(Game* game, const char* monsterName, const char* weaponName) override {
        else if ( strcmp(functionName,   "ATTACK") == 0)
        {
            if(playerPtr->Attack(command))
            {
                castlePtr->HiddenRoomsUnlocker(command , monstersPtr);
            }
            else if(playerPtr->getCurrentState() == false)
                PlayerDead();
        }
    }

    Exit(Game* game, bool& exitCastle) override {
        else if(strcmp (functionName , "EXIT") == 0)
        {
            playerPtr->Exit();
        }
    }
};


class EndLoseState : public GameState 
{
public:
    Play(Game* game) override 
    {
        // Do nothing or display a message indicating that this method not possible in this state where the game has already been lost.
    }

    Move(Game* game, const char* direction, bool& exitCastle) override 
    {
        // Do nothing or display a message indicating that this method not possible in this state where the game has already been lost.
    
    }

    Pick(Game* game, const char* itemName) override {
        // Do nothing or display a message indicating that this method not possible in this state where the game has already been lost.
    }

    Drop(Game* game, const char* itemName) override {
     // Do nothing or display a message indicating that this method not possible in this state where the game has already been lost.
    }

    Look(Game* game) override {
       // Do nothing or display a message indicating that this method not possible in this state where the game has already been lost.
    }

    Attack(Game* game, const char* monsterName, const char* weaponName) override {
        // Do nothing or display a message indicating that this method not possible in this state where the game has already been lost.
    }
    

    Exit(Game* game, bool& exitCastle) override {
        else if(strcmp (functionName , "EXIT") == 0)
        {
            playerPtr->Exit();
        }
    }
};


//--------------------------Game------------------------------------------

// --------------NEW GAME CLASS ACCORDING TO SINGLETON PATTERN-----------------

class Game {
private:
    Player* playerPtr;
    Castle* castlePtr;
    Treasure* itemsPtr[7]; // Increase the size to accommodate new armors
    Monster* monstersPtr[2];
    Princess* princessPtr;

    TreasureFactory treasureFactory;
    WeaponFactory weaponFactory;
    MonsterFactory monsterFactory;
    PlayerFactory playerFactory;
    PrincessFactory princessFactory;
    CastleFactory castleFactory;
    ArmorFactory armorFactory; // Add ArmorFactory

    // Singleton instance
    static Game* instance;

    // Private constructor for Singleton pattern
    Game();
    
public:
    ~Game();
    void Play();
    void ChangeState(GameState* newState);
    void displayStory();
    void PlayerDead();
    void gameCheck();
    void equipArmor();
    
    // Static method to get the singleton instance
    static Game* getInstance();
};

// Initialize static instance to nullptr
Game* Game::instance = nullptr;

// Private constructor
Game::Game()
{
    // Creating Items for the Game using factories
    itemsPtr[0] = treasureFactory.create("GOLDEN EGG");
    itemsPtr[1] = treasureFactory.create("GOLDEN CHALICE");
    itemsPtr[2] = treasureFactory.create("PROOF");
    itemsPtr[3] = weaponFactory.create("SHIELD");
    itemsPtr[4] = weaponFactory.create("DAGGER");
    itemsPtr[5] = armorFactory.create("HELMET");     // Add new Armor
    itemsPtr[6] = armorFactory.create("CHESTPLATE"); // Add new Armor

    // Creating Monsters for the Game using factories
    monstersPtr[0] = monsterFactory.create("MEDUSA", nullptr, itemsPtr[3]);  // MEDUSA with SHIELD
    monstersPtr[1] = monsterFactory.create("DRACULA", nullptr, itemsPtr[4]); // DRACULA with DAGGER

    // Creating Princess for the Game using factory
    princessPtr = princessFactory.create();

    // Creating Castle for the Game using factory
    castlePtr = castleFactory.create();

    // Placing items and monsters in rooms and linking them
    castlePtr->LinkRoomsWithOtherThings(itemsPtr, monstersPtr, princessPtr);
    castlePtr->setDescriptionOfRooms();
    castlePtr->setNumbersofRooms();

    // Code to get the name of the Player
    char username[20];
    HelperFunctions::color(YELLOW);
    cout << "Enter your name : ";
    cin.getline(username, 20);

    // Creating Player for the Game using factory
    playerPtr = playerFactory.create();
    playerPtr->setName(username);
    playerPtr->setCurrentRoom(castlePtr->getRoom(1));
}

Game::~Game() {
    delete currentState;

    for (int i = 0; i < 7; ++i) { // Adjust the loop to match the new size of itemsPtr
        delete itemsPtr[i];
    }

    for (int i = 0; i < 2; ++i) {
        delete monstersPtr[i];
    }

    delete princessPtr;
    delete castlePtr;
    delete playerPtr;
}

// Static method to get the singleton instance
Game* Game::getInstance() {
    if (instance == nullptr) {
        instance = new Game();
    }
    return instance;
}

//NEW FACTORY
void Game::equipArmor() {
    std::string armorName;
    cout << "Enter the name of the armor you want to equip: ";
    cin >> armorName;

    for (int i = 5; i < 7; ++i) { // Checking only armor items
        if (itemsPtr[i]->getName() == armorName) {
            playerPtr->equipArmor(static_cast<Armor*>(itemsPtr[i]));
            cout << "You have equipped " << armorName << "." << endl;
            return;
        }
    }
    cout << "Armor not found." << endl;
}

void Game::Play() {
    char choice;
    bool playing = true;

    while (playing) {
        cout << "Enter your move (n/s/e/w) or (a)ttack or (q)uit or (e)quip armor: ";
        cin >> choice;

        switch (choice) {
            case 'n':
            case 's':
            case 'e':
            case 'w':
                playerPtr->move(choice);
                break;
            case 'a':
                playerPtr->attack();
                break;
            case 'q':
                playing = false;
                break;
            case 'e':
                equipArmor(); // Add this case
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
                break;
        }

        gameCheck();
    }
}
//END NEW FACTORY

void Game::displayStory() {
    ifstream InputStream("Start.txt");
    if (InputStream.is_open()) {
        HelperFunctions::color(PURPLE);
        char buffer[200];
        while (!InputStream.eof()) {
            InputStream.getline(buffer, 200);
            cout << buffer << endl;
        }
    } else {
        cout << "Could not open file";
    }
    InputStream.close();
}

void Game::PlayerDead() {
    ifstream InputStream("EndDead.txt");
    if (InputStream.is_open()) {
        HelperFunctions::color(RED);
        while (!InputStream.eof()) {
            char buffer[200];
            while (!InputStream.eof()) {
                InputStream.getline(buffer, 200);
                cout << buffer << endl;
            }
        }
    } else {
        cout << "Could not open file";
    }
    InputStream.close();
}

void Game::gameCheck() {
    if (playerPtr->getPrincess_Pointer()) {
        ifstream InputStream("EndWin.txt");
        if (InputStream.is_open()) {
            HelperFunctions::color(AQUA);
            char buffer[200];
            while (!InputStream.eof()) {
                InputStream.getline(buffer, 200);
                cout << buffer << endl;
            }
        } else {
            cout << "Could not open file";
        }
        InputStream.close();
    } else {
        ifstream InputStream("EndLose.txt");
        if (InputStream.is_open()) {
            char buffer[200];
            HelperFunctions::color(RED);
            while (!InputStream.eof()) {
                InputStream.getline(buffer, 200);
                cout << buffer << endl;
            }
        } else {
            cout << "Could not open file";
        }
        InputStream.close();
    }
}