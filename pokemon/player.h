#pragma once
#include "pokemon.h"

class Player {
private:
	std::string playerName;
	int numberOfPokemons;
	std::vector <Pokemon> listPickedPokemons;
	Pokemon currentPickedPokemon;

public:
	Player();
	void SetPlayerName(std::string playerName);
	void SetNumberOfPokemons(int numberOfPokemons);
	void ShowListPokemons();
	void ChoseCurrentPokemon(int indexPokemon);
	friend class GameManager;
};