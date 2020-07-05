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

Pokemon::Pokemon(Pokemon& pokemon) {
	this->pokemonName = pokemon.pokemonName;
	this->maxHitPoints = pokemon.maxHitPoints;
	this->currentHitPoints = pokemon.currentHitPoints;
	this->attack = pokemon.attack;
	this->defense = pokemon.defense;
	this->specialAttack = pokemon.specialAttack;
	this->specialDefense = pokemon.specialDefense;
	this->speed = pokemon.speed;
	this->effectTurnsEnd = pokemon.effectTurnsEnd;
	this->isFlinch = pokemon.isFlinch;
	this->moves = pokemon.moves;
	this->type = pokemon.type;
	this->statusCondition = pokemon.statusCondition;
}

Pokemon::~Pokemon() {

	for (auto move : this->moves)
		delete move;
}

Pokemon::Pokemon(std::string pokemonName, int maxHitPoints, int attack, int defense, int specialAttack, int specialDefense, int speed, BasicType type, std::vector <Move*> moves) {

	this->pokemonName = pokemonName;
	this->maxHitPoints = maxHitPoints;
	this->currentHitPoints = maxHitPoints;
	this->attack = attack;
	this->defense = defense;
	this->specialAttack = specialAttack;
	this->specialDefense = specialDefense;
	this->speed = speed;
	this->effectTurnsEnd = 0;
	this->isFlinch = false;
	this->moves = moves;
	this->type = type;
	this->statusCondition = StatusCondition::NORMAL;
}

void Pokemon::ShowPokemonMoves() {
	
	for (int i = 0; i < this->moves.size(); i++) 
		std::cout << "(" << i + 1 << ") " << moves[i]->moveName << std::endl;
}

void Pokemon::Attack(Move* move, Pokemon* target) {

	if (move->category == CategoryMove::PHYSICAL || move->category == CategoryMove::SPECIAL) {
		std::cout << this->pokemonName << " used " << move->moveName << " on " << target->pokemonName << "!" << std::endl;
		move->DealDamage(this, target);
	}
	else if (move->category == CategoryMove::STATUS) {
		std::cout << this->pokemonName << " used " << move->moveName << "!" << std::endl;
		move->DealEffect(this, target);
	}
}

void Pokemon::TakeDamage(int damage) {

	if (damage == 1000)
		damage = this->currentHitPoints;
	this->currentHitPoints -= damage;
	std::cout << this->pokemonName << " took " << damage << " damage!" << std::endl;
	if (this->currentHitPoints<= 0)
		std::cout << this->pokemonName << " has fainted!" << std::endl;
	else
		std::cout << this->pokemonName << " has " << this->currentHitPoints << " HP left" << std::endl;

}

void Pokemon::TakeEffect(std::string effect) {

	if (this->statusCondition == StatusCondition::NORMAL) {
		if (effect == "burn") {
			if (this->type == BasicType::FIRE) {
				std::cout << this->pokemonName << " is immune to burn!" << std::endl;
			}
			else {
				std::cout << this->pokemonName << " was burned!" << std::endl;
				this->statusCondition = StatusCondition::BURN;
			}
		}
		else if (effect == "freeze") {
			if (this->type == BasicType::ICE) {
				std::cout << this->pokemonName << " is immune to freeze!" << std::endl;
			}
			else {
				std::cout << this->pokemonName << " was frozen solid!" << std::endl;
				this->statusCondition = StatusCondition::FREEZE;
			}
		}
		else if (effect == "paralysis") {
			if (this->type == BasicType::ELECTRIC) {
				std::cout << this->pokemonName << " is immune to paralysis!" << std::endl;
			}
			else {
				std::cout << this->pokemonName << " is paralyzed! It may be unable to move!" << std::endl;
				this->statusCondition = StatusCondition::PARALYSIS;
				this->speed /= 2;
			}
		}
		else if (effect == "poison") {
			if (this->type == BasicType::POISON) {
				std::cout << this->pokemonName << " is immune to poison!";
			}
			else {
				std::cout << this->pokemonName << " was poisoned!" << std::endl;
				this->statusCondition = StatusCondition::POISON;
			}
		}
		else if (effect == "sleep") {
			std::cout << this->pokemonName << " fell asleep!" << std::endl;
			this->statusCondition = StatusCondition::SLEEP;
			this->effectTurnsEnd = Move::RandomNumberGenerator(1, 3);
		}
	}
	if (effect == "flinch") {
		this->isFlinch = true;
	}
}

void Pokemon::RaiseStat(std::string stat, int value) {

	if (stat == "attack") { this->attack += value; }
	else if (stat == "defense") { this->defense += value; }
	else if (stat == "specialAttack") { this->specialAttack += value; }
	else if (stat == "specialDefense") { this->specialDefense += value; }
	else if (stat == "speed") { this->speed += value; }
	std::cout << "Raised " << this->pokemonName << "'s " << stat << " by " << value << "." << std::endl;
}

void Pokemon::LowerStat(std::string stat, int value) {

	if (stat == "attack") { this->attack -= value; }
	else if (stat == "defense") { this->defense -= value; }
	else if (stat == "specialAttack") { this->specialAttack -= value; }
	else if (stat == "specialDefense") { this->specialDefense -= value; }
	else if (stat == "speed") { this->speed -= value; }
	std::cout << "Lowered " << this->pokemonName << "'s " << stat << " by " << value << "." << std::endl;

}

bool Pokemon::CanAttack() {

	if (this->statusCondition == StatusCondition::BURN) {
		std::cout << this->pokemonName << " is hurt by its burn!" << std::endl;
		this->TakeDamage(this->maxHitPoints / 8);
	}
	else if (this->statusCondition == StatusCondition::FREEZE) {
		if (Move::RandomProbabilityGenerator(float(20) / 100)) {
			std::cout << this->pokemonName << " was defrosted!" << std::endl;
			this->statusCondition == StatusCondition::NORMAL;
		}
		else {
			std::cout << this->pokemonName << " is frozen solid!";
			return false;
		}
	}
	else if (this->statusCondition == StatusCondition::PARALYSIS) {
		if (Move::RandomProbabilityGenerator(float(25) / 100)) {
			std::cout << this->pokemonName << " is fully paralyzed!" << std::endl;
			return false;
		}
	}
	else if (this->statusCondition == StatusCondition::POISON) {
		std::cout << this->pokemonName << " is hurt by poison!" << std::endl;
		this->TakeDamage(this->maxHitPoints / 8);
	}
	else if (this->statusCondition == StatusCondition::SLEEP) {
		if (this->effectTurnsEnd == 0) {
			std::cout << this->pokemonName << " is woke up." << std::endl;
			this->statusCondition == StatusCondition::NORMAL;
			this->effectTurnsEnd -= 1;
		}
		else {
			std::cout << this->pokemonName << " is fast asleep." << std::endl;
			this->effectTurnsEnd -= 1;
			return false;
		}
	}

	if (this->isFlinch) {
		std::cout << this->pokemonName << " flinched and couldn't move!" << std::endl;
		return false;
	}

	if (this->currentHitPoints <= 0)
		return false;

	return true;
}

bool Pokemon::IsAlive() {

	if (this == NULL)
		return false;
	else
		return this->currentHitPoints > 0;
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
	{ new Tackle(), new SleepPowder(), new MagicalLeaf(), new RazorLeaf() }
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
	{ new Scratch(), new WillOWisp(), new FireFang(), new FlameThrower() }
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
	{ new Tackle(), new Withdraw(), new AquaTail(), new WaterGun() }
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
	{ new QuickAttack(), new ThunderWave(), new Spark(), new Thunderbolt() }
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
	{ new BodySlam(), new DefenseCurl(), new IceFang(), new IceBeam() }
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
	{ new QuickAttack(), new SwordsDance(), new PowerUpPunch(), new VacuumWave() }
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
	{ new Tackle(), new PoisonGas(), new SelfDestruct(), new Sludge() }
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
	{ new Scratch(), new Screech(), new Bulldoze(), new EarthPower() }
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
	{ new Tackle(), new Agility(), new WingAttack(), new AirSlash() }
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
	{ new MegaPunch(), new CalmMind(), new PsychoCut(), new Psyshock() }
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
	{ new QuickAttack(), new Leer(), new XScissor(), new BugBuzz() }
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
	{ new Tackle(), new Harden(), new RockThrow(), new PowerGem() }
) {}
