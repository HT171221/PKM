#pragma once
#include <iostream>
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
	POISON,
	SLEEP
};

std::ostream& operator << (std::ostream& out, const BasicType type);

std::ostream& operator << (std::ostream& out, const StatusCondition status);


class Pokemon {
private:

	std::string pokemonName;
	int maxHitPoints;
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
	friend class User;
public:

	Pokemon(std::string name, int maxHitPoints, int attack, int defense, int specialAttack, int specialDefense, int speed, BasicType type);
	void SetEffect(void (*effect)(Pokemon&));
	void RunEffect(Pokemon& pokemon);
	bool CanRunEffect();
	void ShowStats();
	void ShowName();
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
	friend class Pokemon;
	friend class GameManager;
public:
	void GetName_PokemonNumber();
	void Push_Pokemon();
	void Pick_Pokemon();
};

class GameManager {


};