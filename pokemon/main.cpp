#include "pokemon.h"
#include "move.h"
#include "player.h"
#include "gamelogic.h"

int main() {
	
	Player* player1 = new Player;
	Player* player2 = new Player;
	GameManager* gamePokemon = new GameManager();
	gamePokemon->Setup(player1, player2);
	gamePokemon->Run(player1, player2);

	return 0;
}