#include "pokemon.h"

std::ostream& operator << (std::ostream& out, const BasicType type) {

	std::string s = "";
	switch (type) {
	case BasicType::NORMAL:
		s = "NORMAL"; break;
	case BasicType::FIRE:
		s = "FIRE"; break;
	case BasicType::WATER:
		s = "WATER"; break;
	case BasicType::ELECTRIC:
		s = "ELECTRIC"; break;
	case BasicType::GRASS:
		s = "GRASS"; break;
	case BasicType::ICE:
		s = "ICE"; break;
	case BasicType::FIGHTING:
		s = "FIGHTING"; break;
	case BasicType::POISON:
		s = "POISON"; break;
	case BasicType::GROUND:
		s = "GROUND"; break;
	case BasicType::FLYING:
		s = "FLYING"; break;
	case BasicType::PSYCHIC:
		s = "PSYCHIC"; break;
	case BasicType::BUG:
		s = "BUG"; break;
	case BasicType::ROCK:
		s = "ROCK"; break;
	}

	return out << s;
}

std::ostream& operator << (std::ostream& out, const StatusCondition status) {

	std::string s = "";
	switch (status) {
	case StatusCondition::NORMAL:
		s = "NORMAL"; break;
	case StatusCondition::BURN:
		s = "BURN"; break;
	case StatusCondition::FREEZE:
		s = "FREEZE"; break;
	case StatusCondition::PARALYSIS:
		s = "PARALYSIS"; break;
	case StatusCondition::POISON:
		s = "POISON"; break;
	case StatusCondition::SLEEP:
		s = "SLEEP"; break;
	}

	return out << s;
}

Pokemon::Pokemon(std::string pokemonName, int maxHitPoints, int attack, int defense, int specialAttack, int specialDefense, int speed, BasicType type) {

	this->pokemonName = pokemonName;
	this->maxHitPoints = maxHitPoints;
	this->currentHitPoints = maxHitPoints;
	this->attack = attack;
	this->defense = defense;
	this->specialAttack = specialAttack;
	this->specialDefense = specialDefense;
	this->speed = speed;
	this->type = type;
	this->statusCondition = StatusCondition::NORMAL;
	this->effect = NULL;
}

void Pokemon::SetEffect(void (*effect)(Pokemon&)) { this->effect = effect; }

void Pokemon::RunEffect(Pokemon& pokemon) { effect(*this); }

bool Pokemon::CanRunEffect() { return effect != NULL; }

void Pokemon::ShowStats() {

	std::cout << "HP: " << this->currentHitPoints << " / " << this->maxHitPoints << std::endl;
	std::cout << "Attack: " << this->attack << "\tSpecial Attack: " << this->specialAttack << std::endl;
	std::cout << "Defense: " << this->defense << "\tSpecial Defense: " << this->specialDefense << std::endl;
	std::cout << "Speed: " << this->speed << std::endl;
	std::cout << "Type: " << this->type << std::endl;
	std::cout << "Status: " << this->statusCondition << std::endl;
}



