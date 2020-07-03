#include "pokemon.h"
#include "move.h"
#include "player.h"
#include "gamelogic.h"

int main() {
	
	Player player1;
	Player player2;
	GameManager gamePokemon;
	gamePokemon.Setup(player1, player2);
	player1.ShowListPokemons();
	player2.ShowListPokemons();
	gamePokemon.Run(player1, player2);

	return 0;
}