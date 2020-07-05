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
	//Venusaur p1;
	//Pikachu p2;
	//SleepPowder skill;
	//p1.Attack(skill, p2);
	////p2.Attack(skill, p1);

	return 0;
}