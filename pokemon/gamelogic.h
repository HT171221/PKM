#pragma once
#include "pokemon.h"
#include "player.h"

class GameManager {
private:
	// Tạo Pokedex
	// 2 Players
	std::vector <Pokemon*> pokedex;
	Player* playerAttackFirst;
	Player* playerAttackSecond;

public:
	// Constructor
	GameManager();
	// Destructor
	~GameManager();
	// Hiện Pokedex cho player chọn
	void ShowPokedex();
	// Nhập tên, số lượng Pokemon, và chọn Pokemon của từng player
	void Setup(Player* player1, Player* player2);
	// Bắt đầu game
	void Run(Player* player1, Player* player2);
};