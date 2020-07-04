#include "pokemon.h"
#include "move.h"
#include "player.h"
#include "gamelogic.h"

int main() {
	
	//Player player1;
	//Player player2;
	//GameManager gamePokemon;
	//gamePokemon.Setup(player1, player2);
	//gamePokemon.Run(player1, player2);
	Venusaur p1;
	Charizard p2;
	SleepPowder skill;
	p1.Attack(skill, p2);

	return 0;
}