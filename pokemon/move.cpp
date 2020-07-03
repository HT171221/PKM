#include "move.h"
#include "pokemon.h"
Move::Move(std::string moveName, int power, int accuracy, BasicType type, CategoryMove category) {

	this->moveName = moveName;
	this->power = power;
	this->accuracy = accuracy;
	this->type = type;
	this->category = category;
}

void Move::ShowMoveName() {

	std::cout << this->moveName << std::endl;
}

bool Move::RandomProbabilityGenerator(int probability) {
	
	srand(time(0));
	return rand() % 100 < probability;
}

int Move::RandomNumberGenerator(int minNumber, int maxNumber) {

	srand(time(0));
	return minNumber + rand() % (maxNumber + 1 - minNumber);
}

void Move::Effect(Pokemon* pokemonAttacked, Pokemon* pokemonBeAttacked) {} // default implemetation: do nothing

Tackle::Tackle() : Move(
	"Tackle",
	40,
	100,
	BasicType::NORMAL,
	CategoryMove::PHYSICAL
) {}

SleepPowder::SleepPowder() : Move(
	"Sleep Powder",
	0,
	75,
	BasicType::GRASS,
	CategoryMove::STATUS
) {}

//void SleepPowder::Effect(Pokemon& pokemonAttacked, Pokemon& PokemonBeAttaked) {
//	if (this->RandomProbabilityGenerator(this->accuracy)) {
//		PokemonBeAttaked.statusCondition = StatusCondition::SLEEP;
//		std::cout << "Enemy " << PokemonBeAttaked.pokemonName << " fell asleep" << std::endl;
//		// 
//	}
//}

MagicalLeaf::MagicalLeaf() : Move(
	"Magical Leaf",
	60,
	100,
	BasicType::GRASS,
	CategoryMove::SPECIAL
) {}

RazorLeaf::RazorLeaf() : Move(
	"Razor Leaf",
	55,
	95,
	BasicType::GRASS,
	CategoryMove::PHYSICAL
) {}
//

Scratch::Scratch() : Move(
	"Scratch",
	40,
	100,
	BasicType::NORMAL,
	CategoryMove::PHYSICAL
) {}

WillOWisp::WillOWisp() : Move(
	"Will-O-Wisp",
	0,
	85,
	BasicType::FIRE,
	CategoryMove::STATUS
) {}
//

FireFang::FireFang() : Move(
	"Fire Fang",
	65,
	95,
	BasicType::FIRE,
	CategoryMove::PHYSICAL
) {}
//

FlameThrower::FlameThrower() : Move(
	"Flamethrower",
	90,
	100,
	BasicType::FIRE,
	CategoryMove::SPECIAL
) {}
//

Withdraw::Withdraw() : Move(
	"Withdraw",
	0,
	0,
	BasicType::WATER,
	CategoryMove::STATUS
) {}
//

AquaTail::AquaTail() : Move(
	"Aqua Tail",
	90,
	90,
	BasicType::WATER,
	CategoryMove::PHYSICAL
) {}

WaterGun::WaterGun() : Move(
	"Water Gun",
	40,
	100,
	BasicType::WATER,
	CategoryMove::SPECIAL
) {}

QuickAttack::QuickAttack() : Move(
	"Quick Attack",
	40,
	100,
	BasicType::NORMAL,
	CategoryMove::PHYSICAL
) {}
//

ThunderWave::ThunderWave() : Move(
	"Thunder Wave",
	0,
	90,
	BasicType::ELECTRIC,
	CategoryMove::STATUS
) {}
//

Spark::Spark() : Move(
	"Spark",
	65,
	100,
	BasicType::ELECTRIC,
	CategoryMove::PHYSICAL
) {}
//

Thunderbolt::Thunderbolt() : Move(
	"Thunderbolt",
	90,
	100,
	BasicType::ELECTRIC,
	CategoryMove::SPECIAL
) {}
//

BodySlam::BodySlam() : Move(
	"Body Slam",
	40,
	100,
	BasicType::NORMAL,
	CategoryMove::PHYSICAL
) {}
//

DefenseCurl::DefenseCurl() : Move(
	"Defense Curl",
	0,
	0,
	BasicType::NORMAL,
	CategoryMove::STATUS
) {}
//

IceFang::IceFang() : Move(
	"Ice Fang",
	65,
	95,
	BasicType::ICE,
	CategoryMove::PHYSICAL
) {}
//

IceBeam::IceBeam() : Move(
	"Ice Beam",
	90,
	100,
	BasicType::ICE,
	CategoryMove::SPECIAL
) {}
//

SwordsDance::SwordsDance() : Move(
	"Swords Dance",
	0,
	0,
	BasicType::NORMAL,
	CategoryMove::STATUS
) {}
//

PoweUpPunch::PoweUpPunch() : Move(
	"Power-Up Punch",
	40,
	100,
	BasicType::FIGHTING,
	CategoryMove::PHYSICAL
) {}
//

VacuumWave::VacuumWave() : Move(
	"Vacuum Wave",
	40,
	100,
	BasicType::FIGHTING,
	CategoryMove::SPECIAL
) {}
//

PoisonGas::PoisonGas() : Move(
	"Poison Gas",
	0,
	90,
	BasicType::POISON,
	CategoryMove::STATUS
) {}
//

SelfDestruct::SelfDestruct() : Move(
	"Self-Destruct",
	200,
	100,
	BasicType::NORMAL,
	CategoryMove::PHYSICAL
) {}
//

Sludge::Sludge() : Move(
	"Sludge",
	65,
	100,
	BasicType::POISON,
	CategoryMove::SPECIAL
) {}
//

Screech::Screech() : Move(
	"Screech",
	0,
	85,
	BasicType::NORMAL,
	CategoryMove::STATUS
) {}
//

Bulldoze::Bulldoze() : Move(
	"Bulldoze",
	60,
	100,
	BasicType::GROUND,
	CategoryMove::PHYSICAL
) {}
//

EarthPower::EarthPower() : Move(
	"Earth Power",
	90,
	100,
	BasicType::GROUND,
	CategoryMove::SPECIAL
) {}
//

Agility::Agility() : Move(
	"Agility",
	0,
	0,
	BasicType::PSYCHIC,
	CategoryMove::STATUS
) {}
//

WingAttack::WingAttack() : Move(
	"WingAttack",
	60,
	100,
	BasicType::FLYING,
	CategoryMove::PHYSICAL
) {}

AirSlash::AirSlash() : Move(
	"Air Slash",
	75,
	95,
	BasicType::FLYING,
	CategoryMove::SPECIAL
) {}
//

MegaPunch::MegaPunch() : Move(
	"Mega Punch",
	80,
	85,
	BasicType::NORMAL,
	CategoryMove::PHYSICAL
) {}

CalmMind::CalmMind() : Move(
	"Calm Mind",
	0,
	0,
	BasicType::PSYCHIC,
	CategoryMove::STATUS
) {}
//

PsychoCut::PsychoCut() : Move(
	"Psycho Cut",
	70,
	100,
	BasicType::PSYCHIC,
	CategoryMove::PHYSICAL
) {}
//

Psyshock::Psyshock() : Move(
	"Psyshock",
	80,
	100,
	BasicType::PSYCHIC,
	CategoryMove::SPECIAL
) {}
//

Leer::Leer() : Move(
	"Leer",
	0,
	100,
	BasicType::NORMAL,
	CategoryMove::STATUS
) {}
//

FuryCutter::FuryCutter() : Move(
	"Fury Cutter",
	40,
	95,
	BasicType::BUG,
	CategoryMove::PHYSICAL
) {}
//

BugBuzz::BugBuzz() : Move(
	"Bug Buzz",
	90,
	100,
	BasicType::BUG,
	CategoryMove::SPECIAL
) {}
//

Harden::Harden() : Move(
	"Harden",
	0,
	0,
	BasicType::NORMAL,
	CategoryMove::STATUS
) {}
//

RockThrow::RockThrow() : Move(
	"Rock Throw",
	50,
	90,
	BasicType::ROCK,
	CategoryMove::PHYSICAL
) {}

PowerGem::PowerGem() : Move(
	"Power Gem",
	80,
	100,
	BasicType::ROCK,
	CategoryMove::SPECIAL
) {}