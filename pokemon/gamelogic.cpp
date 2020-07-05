#include "gamelogic.h"

// Constructor
GameManager::GameManager() {

	this->pokedex = { new Venusaur(), new Charizard(), new Blastoise(), new Pikachu(), new Walrein(), new Lucario(), new Weezing(), new Dugtrio(), new Pidgeot(), new Alakazam(), new Scyther(), new Onix() };
}

// Destructor
GameManager::~GameManager() {

	for (auto pokemon : this->pokedex)
		delete pokemon;
}

// Hiện Pokedex cho player chọn
void GameManager::ShowPokedex() {

	for (int i = 0; i < pokedex.size(); i++)
		std::cout << "(" << i + 1 << ") " << pokedex[i]->pokemonName << std::endl;
}

// Nhập tên, số lượng Pokemon, và chọn Pokemon của từng player
void GameManager::Setup(Player* player1, Player* player2) {
	
	std::string playerName;
	int numberOfPokemons;
	int indexPokemon;

	// Tên và số Pokemon của player1
	std::cout << "Player1's name: ";
	std::cin >> playerName;
	std::cout << "Number of Pokemons: ";
	std::cin >> numberOfPokemons;
	player1->SetPlayerName(playerName);
	player1->SetNumberOfPokemons(numberOfPokemons);
	system("cls");

	// Tên và số Pokemon của player2
	std::cout << "Player2's name: ";
	std::cin >> playerName;
	std::cout << "Number of Pokemons: ";
	std::cin >> numberOfPokemons;
	player2->SetPlayerName(playerName);
	player2->SetNumberOfPokemons(numberOfPokemons);
	system("cls");

	// Chọn Pokemon
	std::cout << "Pick pokemon: " << std::endl;
	this->ShowPokedex();

	// Chọn theo từng lượt player1 -> player2 -> player1 -> ...
	while (player1->listPickedPokemons.size() < player1->numberOfPokemons && player2->listPickedPokemons.size() < player2->numberOfPokemons) {
		std::cout << player1->playerName << ": ";
		std::cin >> indexPokemon;
		player1->listPickedPokemons.push_back(new Pokemon(*pokedex[indexPokemon - 1]));
		std::cout << player2->playerName << ": ";
		std::cin >> indexPokemon;
		player2->listPickedPokemons.push_back(new Pokemon(*pokedex[indexPokemon - 1]));
	}
	
	// Nếu player1 chưa chọn đủ số lượng
	while (player1->listPickedPokemons.size() < player1->numberOfPokemons) {
		std::cout << player1->playerName << ": ";
		std::cin >> indexPokemon;
		player1->listPickedPokemons.push_back(new Pokemon(*pokedex[indexPokemon - 1]));
	}

	// Nếu player2 chưa chọn đủ số lượng
	while (player2->listPickedPokemons.size() < player2->numberOfPokemons) {
		std::cout << player2->playerName << ": ";
		std::cin >> indexPokemon;
		player2->listPickedPokemons.push_back(new Pokemon(*pokedex[indexPokemon - 1]));
	}

	system("cls");
}

// Bắt đầu game
void GameManager::Run(Player* player1, Player* player2) {

	// Vòng lặp khi 2 player vẫn còn Pokemon có thể chiến đấu
	while (true) {
		// Do ban đầu chưa chọn Pokemon nên currentPickedPokemon sẽ có giá trị NULL và trả IsFainted sẽ trả về false để người chơi chọn
		// Người chơi 1 chọn Pokemon nếu Pokemon hiện tại bị ngất
		// Số lượng Pokemon của 1 trong 2 player = -1 sẽ kết thúc vòng lặp
		if (!player1->currentPickedPokemon->IsFainted()) {
			player1->numberOfPokemons--;
			if (player1->numberOfPokemons == -1)
				break;
			player1->ChoseCurrentPokemon();
			std::cout << player1->playerName << " sent out " << player1->currentPickedPokemon->pokemonName << "." << std::endl;
		}

		// Người chơi 2 chọn Pokemon nếu Pokemon hiện tại bị ngất
		if (!player2->currentPickedPokemon->IsFainted()) {
			player2->numberOfPokemons--;
			if (player2->numberOfPokemons == -1)
				break;
			player2->ChoseCurrentPokemon();
			std::cout << player2->playerName << " sent out " << player2->currentPickedPokemon->pokemonName << "." << std::endl;
		}

		// Set flinch mỗi turn về false;
		// Pokemon bị flinch sẽ bỏ lượt
		player1->currentPickedPokemon->isFlinch = false;
		player2->currentPickedPokemon->isFlinch = false;

		// Player chọn Move cho Pokemon hiện tại
		player1->SelectMove();
		player2->SelectMove();

		system("cls");

		// Pokemon đánh trước theo thứ tự:
		// Ưu tiên 1: So sánh priority của Move;
		// Ưu tiên 2: So sánh speed của Pokemon
		if (player1->currentMove->priority > player2->currentMove->priority) {
			this->playerAttackFirst = player1;
			this->playerAttackSecond = player2;
		}
		else if (player1->currentMove->priority < player2->currentMove->priority) {
			this->playerAttackFirst = player2;
			this->playerAttackSecond = player1;
		}
		else if (player1->currentMove->priority == player2->currentMove->priority) {
			if (player1->currentPickedPokemon->speed >= player2->currentPickedPokemon->speed) {
				this->playerAttackFirst = player1;
				this->playerAttackSecond = player2;
			}
			else if (player1->currentPickedPokemon->speed < player2->currentPickedPokemon->speed) {
				this->playerAttackFirst = player2;
				this->playerAttackSecond = player1;
			}
		}

		// Thựch hiện đòn tấn công của player trước
		if (playerAttackFirst->currentPickedPokemon->CanAttack()) {
			this->playerAttackFirst->currentPickedPokemon->Attack(this->playerAttackFirst->currentMove, this->playerAttackSecond->currentPickedPokemon);
		}

		// Thựch hiện đòn tấn công của player sau
		if (playerAttackSecond->currentPickedPokemon->CanAttack()) {
			this->playerAttackSecond->currentPickedPokemon->Attack(this->playerAttackSecond->currentMove, this->playerAttackFirst->currentPickedPokemon);
		}
	}

	// Player nào còn Pokemon sẽ là người chiến thắng
	if (player1->numberOfPokemons >= 0)
		std::cout << "The winner is " << player1->playerName;
	else
		std::cout << "The winner is " << player2->playerName;
}