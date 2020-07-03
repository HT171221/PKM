#pragma once
#include "move.h"
#include <iostream>
#include <string>
#include <vector>
#include <ctime>

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

class Move;

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
	std::vector <Move> moves;
	BasicType type;
	StatusCondition statusCondition;
	void(*effect)(Pokemon&);

public:
	Pokemon();
	Pokemon(std::string name, int maxHitPoints, int attack, int defense, int specialAttack, int specialDefense, int speed, BasicType type, std::vector <Move> moves);
	void SetEffect(void (*effect)(Pokemon&));
	void RunEffect(Pokemon& pokemon);
	void ShowPokemonName();
	void ShowPokemonMoves();
	void ShowStats();
	void TakeDamage(int hitPoints);
	bool operator == (const Pokemon& rhs);

	friend class Move;
	friend class Effect;
};

class Venusaur : public Pokemon {
public:
	Venusaur();
};

class Charizard : public Pokemon {
public:
	Charizard();
};

class Blastoise : public Pokemon {
public:
	Blastoise();
};

class Pikachu : public Pokemon {
public:
	Pikachu();
};

class Walrein : public Pokemon {
public:
	Walrein();
};

class Lucario : public Pokemon {
public:
	Lucario();
};

class Weezing : public Pokemon {
public:
	Weezing();
};

class Dugtrio : public Pokemon {
public:
	Dugtrio();
};

class Pidgeot : public Pokemon {
public:
	Pidgeot();
};

class Alakazam : public Pokemon {
public:
	Alakazam();
};

class Scyther : public Pokemon {
public:
	Scyther();
};

class Onix : public Pokemon {
public:
	Onix();
};

//class Effect {
//public:
//	//inline void Sleep
//
//};

