#include "player.h"

Player::Player() = default;

void Player::SetPlayerName(std::string playerName) {

	this->playerName = playerName;
}

void Player::SetNumberOfPokemons(int numberOfPokemons) {

	this->numberOfPokemons = numberOfPokemons;
}

void Player::ShowListPokemons() {

	for (int i = 0; i < this->listPickedPokemons.size(); i++) {
		std::cout << "(" << i + 1 << ") ";
		listPickedPokemons[i].ShowPokemonName();
	}
}

void Player::ChoseCurrentPokemon(int indexPokemon) {
	
	this->currentPickedPokemon = this->listPickedPokemons[indexPokemon];
}