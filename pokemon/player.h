#pragma once
#include "pokemon.h"

class Player {
private:
	// Thông tin của player
	std::string playerName;
	int numberOfPokemons; // 1 -> 6
	std::vector <Pokemon*> listPickedPokemons;
	Pokemon* currentPickedPokemon;
	Move* currentMove;

public:
	Player();
	// Set tên người chơi
	void SetPlayerName(std::string playerName); 
	// Set số lượng pokemon mà người chơi chọn
	void SetNumberOfPokemons(int numberOfPokemons); 
	// Hiện số Pokemon của của người chơi đã chọn
	void ShowListPokemons(); 
	// Chọn Pokemon ra trận trong số Pokemon người chơi đã chọn
	void ChoseCurrentPokemon();
	// Chọn Move cho Pokemon đang ra trận
	void SelectMove(); 

	friend class GameManager;
};