#include "pokemon.h"
#include "move.h"

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

Pokemon::Pokemon() = default;

Pokemon::Pokemon(std::string pokemonName, int maxHitPoints, int attack, int defense, int specialAttack, int specialDefense, int speed, BasicType type, std::vector <Move> moves) {

	this->pokemonName = pokemonName;
	this->maxHitPoints = maxHitPoints;
	this->currentHitPoints = maxHitPoints;
	this->attack = attack;
	this->defense = defense;
	this->specialAttack = specialAttack;
	this->specialDefense = specialDefense;
	this->speed = speed;
	this->isAlive = true;
	this->type = type;
	this->statusCondition = StatusCondition::NORMAL;
	this->effect = NULL;
	this->moves = moves;
}

void Pokemon::SetEffect(void (*effect)(Pokemon&)) { this->effect = effect; }

void Pokemon::RunEffect(Pokemon& pokemon) { effect(*this); }

void Pokemon::ShowPokemonName() {

	std::cout << this->pokemonName << std::endl;
}

void Pokemon::ShowPokemonMoves() {
	
	for (int i = 0; i < this->moves.size(); i++) {
		std::cout << "(" << i + 1 << ") ";
		moves[i].ShowMoveName();
	}
}

void Pokemon::ShowStats() {

	std::cout << "HP: " << this->currentHitPoints << " / " << this->maxHitPoints << std::endl;
	std::cout << "Attack: " << this->attack << "\tSpecial Attack: " << this->specialAttack << std::endl;
	std::cout << "Defense: " << this->defense << "\tSpecial Defense: " << this->specialDefense << std::endl;
	std::cout << "Speed: " << this->speed << std::endl;
	std::cout << "Type: " << this->type << std::endl;
	std::cout << "Status: " << this->statusCondition << std::endl;
}

void Pokemon::TakeDamage(int hitPoints) {

	if (this->currentHitPoints - hitPoints < 0) {
		this->currentHitPoints = 0;
		this->isAlive = false;
	}
	else
		this->currentHitPoints -= hitPoints;
}

bool Pokemon::operator==(const Pokemon& rhs) {
	
	return this->pokemonName == rhs.pokemonName;
}

Venusaur::Venusaur() : Pokemon(
	"Venusaur",
	364,
	289,
	291,
	328,
	328,
	284,
	BasicType::GRASS,
	{Tackle(), SleepPowder(), MagicalLeaf(), RazorLeaf()}
) {}

Charizard::Charizard() : Pokemon(
	"Charizard",
	360,
	293,
	280,
	348,
	295,
	328,
	BasicType::FIRE,
	{ Scratch(), WillOWisp(), FireFang(), FlameThrower() }
) {}

Blastoise::Blastoise() : Pokemon(
	"Blastoise",
	362,
	291,
	238,
	295,
	339,
	280,
	BasicType::WATER,
	{ Tackle(), Withdraw(), AquaTail(), WaterGun() }
) {}

Pikachu::Pikachu() : Pokemon (
	"Pikachu",
	324,
	306,
	229,
	306,
	284,
	350,
	BasicType::ELECTRIC,
	{ QuickAttack(), ThunderWave(), Spark(), Thunderbolt() }
) {}

Walrein::Walrein() : Pokemon(
	"Walrein",
	424,
	284,
	306,
	317,
	306,
	251,
	BasicType::ICE,
	{ BodySlam(), DefenseCurl(), IceFang(), IceBeam() }
) {}

Lucario::Lucario() : Pokemon(
	"Lucario",
	344,
	350,
	262,
	361,
	262,
	306,
	BasicType::FIGHTING,
	{ QuickAttack(), SwordsDance(), PoweUpPunch(), VacuumWave() }
) {}

Weezing::Weezing() : Pokemon(
	"Weezing",
	334,
	306,
	372,
	295,
	262,
	240,
	BasicType::POISON,
	{ Tackle(), PoisonGas(), SelfDestruct(), Sludge() }
) {}

Dugtrio::Dugtrio() : Pokemon(
	"Dugtrio",
	274,
	328,
	218,
	218,
	262,
	372,
	BasicType::GROUND,
	{ Scratch(), Screech(), Bulldoze(), EarthPower() }
) {}

Pidgeot::Pidgeot() : Pokemon(
	"Pidgeot",
	370,
	284,
	273,
	262,
	262,
	331,
	BasicType::FLYING,
	{ Tackle(), Agility(), WingAttack(), AirSlash() }
) {}

Alakazam::Alakazam() : Pokemon(
	"Alakazam",
	314,
	218,
	207,
	405,
	317,
	372,
	BasicType::PSYCHIC,
	{ MegaPunch(), CalmMind(), PsychoCut(), Psyshock() }
) {}

Scyther::Scyther() : Pokemon(
	"Scyther",
	344,
	350,
	284,
	229,
	284,
	339,
	BasicType::BUG,
	{ QuickAttack(), Leer(), FuryCutter(), BugBuzz() }
) {}

Onix::Onix() : Pokemon(
	"Onix",
	274,
	207,
	460,
	174,
	207,
	262,
	BasicType::ROCK,
	{ Tackle(), Harden(), RockThrow(), PowerGem() }
) {}
