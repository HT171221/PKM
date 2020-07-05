#pragma once
#include "move.h"
#include <iostream>
#include <string>
#include <vector>
#include <ctime>

// 12 BasicType cơ bản + Normal
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

// 5 Status + Normal
enum class StatusCondition {
	NORMAL,
	BURN,
	FREEZE,
	PARALYSIS,
	POISON,
	SLEEP
};

class Pokemon {
private:
	// Chỉ số Pokemon
	std::string pokemonName;
	int maxHitPoints;
	int currentHitPoints;
	int attack;
	int defense;
	int specialAttack;
	int specialDefense;
	int speed;
	int effectTurnsEnd;
	bool isFlinch;
	std::vector <Move*> moves;
	BasicType type;
	StatusCondition statusCondition;

public:
	// Default constructor
	Pokemon();
	Pokemon(std::string name, int maxHitPoints, int attack, int defense, int specialAttack, int specialDefense, int speed, BasicType type, std::vector <Move*> moves);
	// Copy constructor
	Pokemon(Pokemon& pokemon);
	// Destructor
	~Pokemon();
	void ShowPokemonMoves(); // Hiện 4 move của Pokemon
	void Attack(Move* move, Pokemon* target); // Thực hiện đòn đánh
	void TakeDamage(int damage); // Nhận damage
	void TakeEffect(std::string effect); // Nhận effect
	void RaiseStat(std::string stat, int value); // Tăng chỉ số
	void LowerStat(std::string stat, int value); // Giảm chỉ số
	bool CanAttack(); // Khả năng thực hiện đòn đánh dựa trên effect
	bool IsFainted(); // Kiểm tra trạng thái 

	friend class Move;
	friend class GameManager;
	friend class Player;
};

// Khai báo các class con kế thừa class Pokemon
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

