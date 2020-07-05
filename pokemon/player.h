#pragma once
#include "pokemon.h"

class Player {
private:
	std::string playerName;
	int numberOfPokemons;
	std::vector <Pokemon*> listPickedPokemons;
	Pokemon* currentPickedPokemon;
	Move* currentMove;

public:
	Player();
	void SetPlayerName(std::string playerName);
	void SetNumberOfPokemons(int numberOfPokemons);
	void ShowListPokemons();
	void ChoseCurrentPokemon();
	void SelectMove();

	friend class GameManager;
};