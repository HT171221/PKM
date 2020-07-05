#include "gamelogic.h"

GameManager::GameManager() {

	this->pokedex = { Venusaur(), Charizard(), Blastoise(), Pikachu(), Walrein(), Lucario(), Weezing(), Dugtrio(), Pidgeot(), Alakazam(), Scyther(), Onix() };
}

void GameManager::ShowPokedex() {

	for (int i = 0; i < pokedex.size(); i++)
		std::cout << "(" << i + 1 << ") " << pokedex[i].pokemonName << std::endl;
}

void GameManager::Setup(Player* player1, Player* player2) {
	
	std::string playerName;
	int numberOfPokemons;
	int indexPokemon;

	std::cout << "Player1's name: ";
	std::cin >> playerName;
	std::cout << "Number of Pokemons: ";
	std::cin >> numberOfPokemons;
	player1->SetPlayerName(playerName);
	player1->SetNumberOfPokemons(numberOfPokemons);
	system("cls");

	std::cout << "Player2's name: ";
	std::cin >> playerName;
	std::cout << "Number of Pokemons: ";
	std::cin >> numberOfPokemons;
	player2->SetPlayerName(playerName);
	player2->SetNumberOfPokemons(numberOfPokemons);
	system("cls");

	std::cout << "Pick pokemon: " << std::endl;
	this->ShowPokedex();

	while (player1->listPickedPokemons.size() < player1->numberOfPokemons && player2->listPickedPokemons.size() < player2->numberOfPokemons) {
		std::cout << player1->playerName << ": ";
		std::cin >> indexPokemon;
		player1->listPickedPokemons.push_back(pokedex[indexPokemon - 1]);
		std::cout << player2->playerName << ": ";
		std::cin >> indexPokemon;
		player2->listPickedPokemons.push_back(pokedex[indexPokemon - 1]);
	}
	
	while (player1->listPickedPokemons.size() < player1->numberOfPokemons) {
		std::cout << player1->playerName << ": ";
		std::cin >> indexPokemon;
		player1->listPickedPokemons.push_back(pokedex[indexPokemon - 1]);
	}

	while (player2->listPickedPokemons.size() < player2->numberOfPokemons) {
		std::cout << player2->playerName << ": ";
		std::cin >> indexPokemon;
		player2->listPickedPokemons.push_back(pokedex[indexPokemon - 1]);
	}

	system("cls");
}

void GameManager::Run(Player* player1, Player* player2) {

	while (player1->numberOfPokemons >= 0 && player2->numberOfPokemons >= 0) {
		if (!player1->currentPickedPokemon.IsAlive()) {
			player1->numberOfPokemons--;
			player1->ChoseCurrentPokemon();
			std::cout << player1->playerName << " sent out " << player1->currentPickedPokemon.pokemonName << "." << std::endl;
		}

		if (!player2->currentPickedPokemon.IsAlive()) {
			player1->numberOfPokemons--;
			player2->ChoseCurrentPokemon();
			std::cout << player2->playerName << " sent out " << player2->currentPickedPokemon.pokemonName << "." << std::endl;
		}

		player1->currentPickedPokemon.isFlinch = false;
		player2->currentPickedPokemon.isFlinch = false;

		player1->SelectMove();
		player2->SelectMove();

		system("cls");

		if (player1->currentMove.priority > player2->currentMove.priority) {
			this->playerAttackFirst = player1;
			this->playerAttackSecond = player2;
		}
		else if (player1->currentMove.priority < player2->currentMove.priority) {
			this->playerAttackFirst = player2;
			this->playerAttackSecond = player1;
		}
		else if (player1->currentMove.priority == player2->currentMove.priority) {
			if (player1->currentPickedPokemon.speed >= player2->currentPickedPokemon.speed) {
				this->playerAttackFirst = player1;
				this->playerAttackSecond = player2;
			}
			else if (player1->currentPickedPokemon.speed < player2->currentPickedPokemon.speed) {
				this->playerAttackFirst = player2;
				this->playerAttackSecond = player1;
			}
		}

		if (playerAttackFirst->currentPickedPokemon.CanAttack()) {
			this->playerAttackFirst->currentPickedPokemon.Attack(this->playerAttackFirst->currentMove, this->playerAttackSecond->currentPickedPokemon);
		}

		if (playerAttackFirst->currentPickedPokemon.CanAttack()) {
			this->playerAttackSecond->currentPickedPokemon.Attack(this->playerAttackSecond->currentMove, this->playerAttackFirst->currentPickedPokemon);
		}
	}

	system("cls");
	if (player1->numberOfPokemons > 0)
		std::cout << "The winner is " << player1->playerName;
	else
		std::cout << "The winner is " << player2->playerName;
}