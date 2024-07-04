#include "pch.h"
#include "Zelda.h"
#include "./test.cpp"
#include <windows.h>
/*
int main()
{
	Game game = new Game();
	game->Play();

	system("PAUSE");
	return 0;
}
*/

//--------------After implementing SINGLETON-------------------------
int main() 
{
    Game* game = Game::getInstance();
    game->Play();

    system("PAUSE");
    return 0;
}