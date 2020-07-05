#include "player.h"

// default constructor
Player::Player() = default;

// Set tên người chơi
void Player::SetPlayerName(std::string playerName) {

	this->playerName = playerName;
}

// Set số lượng pokemon mà người chơi chọn
void Player::SetNumberOfPokemons(int numberOfPokemons) {

	this->numberOfPokemons = numberOfPokemons;
}

// Hiện số Pokemon của của người chơi đã chọn
void Player::ShowListPokemons() {

	for (int i = 0; i < this->listPickedPokemons.size(); i++) 
		std::cout << "(" << i + 1 << ") " << listPickedPokemons[i]->pokemonName << std::endl;
}

// Chọn Pokemon ra trận trong số Pokemon người chơi đã chọn
void Player::ChoseCurrentPokemon() {
	
	int indexPokemon;
	this->ShowListPokemons();
	std::cout << this->playerName << std::endl << "Chose Pokemon: ";
	std::cin >> indexPokemon;
	this->currentPickedPokemon = this->listPickedPokemons[indexPokemon - 1];
	this->listPickedPokemons.erase(this->listPickedPokemons.begin() + indexPokemon - 1);
}

// Chọn Move cho Pokemon đang ra trận
void Player::SelectMove() {

	int indexMove;
	std::cout << this->playerName << ". What will " << this->currentPickedPokemon->pokemonName << " do?" << std::endl;
	this->currentPickedPokemon->ShowPokemonMoves();
	std::cout << "Choose move: ";
	std::cin >> indexMove;

	this->currentMove = currentPickedPokemon->moves[indexMove - 1];
}