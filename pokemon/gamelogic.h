#pragma once
#include "pokemon.h"
#include "player.h"

class GameManager {
private:
	std::vector <Pokemon> pokedex;
	Player* playerAttackFirst;
	Player* playerAttackSecond;

public:

	GameManager();
	void ShowPokedex();
	void Setup(Player* player1, Player* player2);
	void Run(Player* player1, Player* player2);

	
};