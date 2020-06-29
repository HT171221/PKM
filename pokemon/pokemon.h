#pragma once
#include <string>
#include <vector>

enum class BasicType {
	NORMAL,
	FIRE,
	WATER,
	ELECTRIC,
	GRASS,
	ICE,
	FIGHTING,
	POISON,
	GROUND,
	FLYING,
	PSYCHIC,
	BUG,
	ROCK
};

enum class StatusCondition {
	NORMAL,
	BURN,
	FREEZE,
	PARALYSIS,
	POISON
};

class Pokemon {
private:

	std::string pokemonName;
	int maxHitPoins;
	int currentHitPoints;
	int attack;
	int defense;
	int specialAttack;
	int specialDefense;
	int speed;
	bool isAlive;
	BasicType type;
	StatusCondition statusCondition;
	void(*effect)(Pokemon&);

public:

	Pokemon(std::string name, int maxHitPoints, int attack, int defense, int specialAttack, int specialDefense, int speed, BasicType type);
	void SetEffect(void (*Effect)(Pokemon&));
	void RunEffect(Pokemon& pokemon);
	bool CanRunEffect();
	void ShowStats();

	friend class Effect;
};

class Effect {
public:


};

class User {
private:

	std::string userName;
	int numberOfPokemons;
	std::vector <Pokemon> listPickedPokemons;
	Pokemon currentPickedPokemon;


};

class GameManager {


};