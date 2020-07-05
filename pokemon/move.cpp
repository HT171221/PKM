#include "move.h"
#include "pokemon.h"

Move::Move() = default;

Move::Move(std::string moveName, int power, int accuracy, int priority, BasicType type, CategoryMove category) {

	this->moveName = moveName;
	this->power = power;
	this->accuracy = accuracy;
	this->priority = priority;
	this->type = type;
	this->category = category;
}

bool Move::RandomProbabilityGenerator(float probability) {

	std::vector <float> random;
	srand(time(0));
	for (int i = 0; i < 100; i++)
		random.push_back((float)(rand()) / (float)(RAND_MAX));
	return  random[Move::RandomNumberGenerator(1, 99)] >= 1 - probability;
}

int Move::RandomNumberGenerator(int minNumber, int maxNumber) {

	srand((time(0)));
	return minNumber + rand() % (maxNumber + 1 - minNumber);
}

// typeVar = Critical * random * stab * type * Burn
void Move::DealDamage(Pokemon& attacker, Pokemon& target, float criticalChance) {
	
	if (!this->CanAttack(attacker, (float)this->accuracy / 100)) {
		return;
	}

	int damage;
	float modifier;
	float typeVar = 1;
	float critical;
	float stab;
	float burn;
	float random = (float)this->RandomNumberGenerator(85, 100) / 100;

	if (this->RandomProbabilityGenerator(criticalChance)) {
		std::cout << "A critical hit" << std::endl;
		critical = 1.5;
	}
	else {
		critical = 1;
	}

	if (this->type == attacker.type) {
		stab = 1.5;
	}
	else {
		stab = 1;
	}

	if (attacker.statusCondition == StatusCondition::BURN) {
		burn = 0.5;
	}
	else {
		burn = 1;
	}

	if (this->type == BasicType::NORMAL) {
		if (target.type == BasicType::ROCK) {
			std::cout << "It's not very effective." << std::endl;
			typeVar = 0.5;
		}
	}
	else if (this->type == BasicType::FIRE) {
		if (target.type == BasicType::GRASS || target.type == BasicType::ICE || target.type == BasicType::BUG) {
			std::cout << "It's super effective!" << std::endl;
			typeVar = 2;
		}
		else if (target.type == BasicType::FIRE || target.type == BasicType::WATER || target.type == BasicType::ROCK) {
			std::cout << "It's not very effective." << std::endl;
			typeVar = 0.5;
		}
	}
	else if (this->type == BasicType::WATER) {
		if (target.type == BasicType::GROUND || target.type == BasicType::ROCK || target.type == BasicType::FIRE || target.type == BasicType::ICE) {
			std::cout << "It's super effective!" << std::endl;
			typeVar = 2;
		}
		else if (target.type == BasicType::WATER || target.type == BasicType::GRASS) {
			std::cout << "It's not very effective." << std::endl;
			typeVar = 0.5;
		}
	}
	else if (this->type == BasicType::ELECTRIC) {
		if (target.type == BasicType::FLYING || target.type == BasicType::WATER) {
			std::cout << "It's super effective!" << std::endl;
			typeVar = 2;
		}
		else if (target.type == BasicType::GRASS || target.type == BasicType::ELECTRIC) {
			std::cout << "It's not very effective." << std::endl;
			typeVar = 0.5;
		}
		else if (target.type == BasicType::GROUND) {
			std::cout << "No effect." << std::endl;
			typeVar = 0;
		}
	}
	else if (this->type == BasicType::GRASS) {
		if (target.type == BasicType::GROUND || target.type == BasicType::ROCK || target.type == BasicType::WATER) {
			std::cout << "It's super effective!" << std::endl;
			typeVar = 2;
		}
		else if (target.type == BasicType::FLYING || target.type == BasicType::POISON || target.type == BasicType::BUG || target.type == BasicType::FIRE || target.type == BasicType::GRASS) {
			std::cout << "It's not very effective." << std::endl;
			typeVar = 0.5;
		}
	}
	else if (this->type == BasicType::ICE) {
		if (target.type == BasicType::FLYING || target.type == BasicType::GROUND || target.type == BasicType::GRASS) {
			std::cout << "It's super effective!" << std::endl;
			typeVar = 2;
		}
		else if (target.type == BasicType::FIRE || target.type == BasicType::WATER || target.type == BasicType::ICE) {
			std::cout << "It's not very effective." << std::endl;
			typeVar = 0.5;
		}
	}
	else if (this->type == BasicType::FIGHTING) {
		if (target.type == BasicType::NORMAL || target.type == BasicType::ROCK || target.type == BasicType::ICE) {
			std::cout << "It's super effective!" << std::endl;
			typeVar = 2;
		}
		else if (target.type == BasicType::FLYING || target.type == BasicType::POISON || target.type == BasicType::BUG || target.type == BasicType::PSYCHIC) {
			std::cout << "It's not very effective." << std::endl;
			typeVar = 0.5;
		}
	}
	else if (this->type == BasicType::POISON) {
		if (target.type == BasicType::GRASS) {
			std::cout << "It's super effective!" << std::endl;
			typeVar = 2;
		}
		else if (this->type == BasicType::POISON || this->type == BasicType::GROUND || this->type == BasicType::ROCK) {
			std::cout << "It's not very effective." << std::endl;
			typeVar = 0.5;
		}
	}
	else if (this->type == BasicType::GROUND) {
		if (target.type == BasicType::POISON || target.type == BasicType::ROCK || target.type == BasicType::FIRE || target.type == BasicType::ELECTRIC) {
			std::cout << "It's super effective!" << std::endl;
			typeVar = 2;
		}
		else if (target.type == BasicType::BUG || target.type == BasicType::GRASS) {
			std::cout << "It's not very effective." << std::endl;
			typeVar = 0.5;
		}
		else if (target.type == BasicType::FLYING) {
			std::cout << "No effect." << std::endl;
			typeVar = 0;
		}
	}
	else if (this->type == BasicType::FLYING) {
		if (this->type == BasicType::FIGHTING || this->type == BasicType::BUG || this->type == BasicType::GRASS) {
			std::cout << "It's super effective!" << std::endl;
			typeVar = 2;
		}
		else if (this->type == BasicType::ROCK || this->type == BasicType::ELECTRIC) {
			std::cout << "It's not very effective." << std::endl;
			typeVar = 0.5;
		}
	}
	else if (this->type == BasicType::PSYCHIC) {
		if (this->type == BasicType::FIGHTING || this->type == BasicType::POISON) {
			std::cout << "It's super effective!" << std::endl;
			typeVar = 2;
		}
		else if (this->type == BasicType::PSYCHIC) {
			std::cout << "It's not very effective." << std::endl;
			typeVar = 0.5;
		}
	}
	else if (this->type == BasicType::BUG) {
		if (this->type == BasicType::GRASS || this->type == BasicType::PSYCHIC) {
			std::cout << "It's super effective!" << std::endl;
			typeVar = 2;
		}
		else if (this->type == BasicType::FIGHTING || this->type == BasicType::FLYING || this->type == BasicType::POISON || this->type == BasicType::FIRE) {
			std::cout << "It's not very effective." << std::endl;
			typeVar = 0.5;
		}
	}
	else if (this->type == BasicType::ROCK) {
		if (this->type == BasicType::FLYING || this->type == BasicType::BUG || this->type == BasicType::FIRE || this->type == BasicType::ICE) {
			std::cout << "It's super effective!" << std::endl;
			typeVar = 2;
		}
		else if (this->type == BasicType::FIGHTING || this->type == BasicType::GROUND) {
			std::cout << "It's not very effective." << std::endl;
			typeVar = 0.5;
		}
	}
	
	modifier = critical * random * stab * typeVar * burn;
	if (modifier != 0) {
		if (this->category == CategoryMove::PHYSICAL) {
			damage = ((((((2 * 100) / 5) + 2) * this->power * (attacker.attack / target.defense)) / 50) + 2) * modifier;
		}
		else if (this->category == CategoryMove::SPECIAL) {
			damage = ((((((2 * 100) / 5) + 2) * this->power * (attacker.specialAttack / target.specialDefense)) / 50) + 2) * modifier;
		}
	}

	target.TakeDamage(damage);
	DealEffect(attacker, target);
}

void Move::DealEffect(Pokemon& attacker, Pokemon& target) {}

void Move::ShowMoveName() {

	std::cout << this->moveName << std::endl;
}

bool Move::CanAttack(Pokemon& attacker, float probability) {

	if (this->RandomProbabilityGenerator(probability)) {
		return true;
	}
	else {
		std::cout << attacker.pokemonName << "'s attack missed!" << std::endl;
		return false;
	}
}

Tackle::Tackle() : Move(
	"Tackle",
	40,
	100,
	0,
	BasicType::NORMAL,
	CategoryMove::PHYSICAL
) {}

SleepPowder::SleepPowder() : Move(
	"Sleep Powder",
	0,
	75,
	0,
	BasicType::GRASS,
	CategoryMove::STATUS
) {}

void SleepPowder::DealEffect(Pokemon& attacker, Pokemon& target) {

	if (this->CanAttack(attacker, (float)this->accuracy / 100)) 
		target.TakeEffect("sleep");
}

MagicalLeaf::MagicalLeaf() : Move(
	"Magical Leaf",
	60,
	100,
	0,
	BasicType::GRASS,
	CategoryMove::SPECIAL
) {}

RazorLeaf::RazorLeaf() : Move(
	"Razor Leaf",
	55,
	95,
	0,
	BasicType::GRASS,
	CategoryMove::PHYSICAL
) {}

void RazorLeaf::DealDamage(Pokemon& attacker, Pokemon& target, float criticalChance) {

	Move::DealDamage(attacker, target, (float)1 / 8);
}

Scratch::Scratch() : Move(
	"Scratch",
	40,
	100,
	0,
	BasicType::NORMAL,
	CategoryMove::PHYSICAL
) {}

WillOWisp::WillOWisp() : Move(
	"Will-O-Wisp",
	0,
	85,
	0,
	BasicType::FIRE,
	CategoryMove::STATUS
) {}

void WillOWisp::DealEffect(Pokemon& attacker, Pokemon& target) {

	if (this->CanAttack(attacker, (float)this->accuracy / 100)) 
		target.TakeEffect("burn");
}


FireFang::FireFang() : Move(
	"Fire Fang",
	65,
	95,
	0,
	BasicType::FIRE,
	CategoryMove::PHYSICAL
) {}

void FireFang::DealEffect(Pokemon& attacker, Pokemon& target) {

	if (this->RandomProbabilityGenerator((float)10 / 100)) 
		target.TakeEffect("burn");

}

FlameThrower::FlameThrower() : Move(
	"Flamethrower",
	90,
	100,
	0,
	BasicType::FIRE,
	CategoryMove::SPECIAL
) {}

void FlameThrower::DealEffect(Pokemon& attacker, Pokemon& target) {

	if (this->RandomProbabilityGenerator((float)10 / 100)) 
		target.TakeEffect("burn");
}

Withdraw::Withdraw() : Move(
	"Withdraw",
	0,
	0,
	0,
	BasicType::WATER,
	CategoryMove::STATUS
) {}

void Withdraw::DealEffect(Pokemon& attacker, Pokemon& target) {

	attacker.RaiseStat("defense", 20);
}

AquaTail::AquaTail() : Move(
	"Aqua Tail",
	90,
	90,
	0,
	BasicType::WATER,
	CategoryMove::PHYSICAL
) {}

WaterGun::WaterGun() : Move(
	"Water Gun",
	40,
	100,
	0,
	BasicType::WATER,
	CategoryMove::SPECIAL
) {}

QuickAttack::QuickAttack() : Move(
	"Quick Attack",
	40,
	100,
	1,
	BasicType::NORMAL,
	CategoryMove::PHYSICAL
) {}

ThunderWave::ThunderWave() : Move(
	"Thunder Wave",
	0,
	90,
	0,
	BasicType::ELECTRIC,
	CategoryMove::STATUS
) {}

void ThunderWave::DealEffect(Pokemon& attacker, Pokemon& target) {

	if (this->CanAttack(attacker, (float)this->accuracy / 100)) 
		target.TakeEffect("paralysis");
}


Spark::Spark() : Move(
	"Spark",
	65,
	100,
	0,
	BasicType::ELECTRIC,
	CategoryMove::PHYSICAL
) {}

void Spark::DealEffect(Pokemon& attacker, Pokemon& target) {

	if (this->RandomProbabilityGenerator((float)30 / 100)) 
		target.TakeEffect("paralysis");
}

Thunderbolt::Thunderbolt() : Move(
	"Thunderbolt",
	90,
	100,
	0,
	BasicType::ELECTRIC,
	CategoryMove::SPECIAL
) {}

void Thunderbolt::DealEffect(Pokemon& attacker, Pokemon& target) {

	if (this->RandomProbabilityGenerator((float)10 / 100))
		target.TakeEffect("paralysis");
}

BodySlam::BodySlam() : Move(
	"Body Slam",
	40,
	100,
	0,
	BasicType::NORMAL,
	CategoryMove::PHYSICAL
) {}

void BodySlam::DealEffect(Pokemon& attacker, Pokemon& target) {

	if (this->RandomProbabilityGenerator((float)30 / 100)) 
		target.TakeEffect("paralysis");
}

DefenseCurl::DefenseCurl() : Move(
	"Defense Curl",
	0,
	0,
	0,
	BasicType::NORMAL,
	CategoryMove::STATUS
) {}

void DefenseCurl::DealEffect(Pokemon& attacker, Pokemon& target) {

	attacker.RaiseStat("defense", 20);
}

IceFang::IceFang() : Move(
	"Ice Fang",
	65,
	95,
	0,
	BasicType::ICE,
	CategoryMove::PHYSICAL
) {}

void IceFang::DealEffect(Pokemon& attacker, Pokemon& target) {

	if (this->RandomProbabilityGenerator((float)10 / 100)) 
		target.TakeEffect("ice");

	if (!this->RandomProbabilityGenerator((float)10 / 100))
		target.TakeEffect("flinch");
}

IceBeam::IceBeam() : Move(
	"Ice Beam",
	90,
	100,
	0,
	BasicType::ICE,
	CategoryMove::SPECIAL
) {}

void IceBeam::DealEffect(Pokemon& attacker, Pokemon& target) {

	if (!this->RandomProbabilityGenerator((float)10 / 100)) 
		target.TakeEffect("ice");
}

SwordsDance::SwordsDance() : Move(
	"Swords Dance",
	0,
	0,
	0,
	BasicType::NORMAL,
	CategoryMove::STATUS
) {}

void SwordsDance::DealEffect(Pokemon& attacker, Pokemon& target) {

	attacker.RaiseStat("attack", 20);
}

PowerUpPunch::PowerUpPunch() : Move(
	"Power-Up Punch",
	40,
	100,
	0,
	BasicType::FIGHTING,
	CategoryMove::PHYSICAL
) {}

void PowerUpPunch::DealEffect(Pokemon& attacker, Pokemon& target) {

	attacker.RaiseStat("attack", 20);
}

VacuumWave::VacuumWave() : Move(
	"Vacuum Wave",
	40,
	100,
	1,
	BasicType::FIGHTING,
	CategoryMove::SPECIAL
) {}

PoisonGas::PoisonGas() : Move(
	"Poison Gas",
	0,
	90,
	0,
	BasicType::POISON,
	CategoryMove::STATUS
) {}

void PoisonGas::DealEffect(Pokemon& attacker, Pokemon& target) {

	if (this->CanAttack(attacker, (float)this->accuracy / 100))
		target.TakeEffect("poison");
}

SelfDestruct::SelfDestruct() : Move(
	"Self-Destruct",
	200,
	100,
	0,
	BasicType::NORMAL,
	CategoryMove::PHYSICAL
) {}

void SelfDestruct::DealEffect(Pokemon& attacker, Pokemon& target) {

	attacker.TakeDamage(1000);
}

Sludge::Sludge() : Move(
	"Sludge",
	65,
	100,
	0,
	BasicType::POISON,
	CategoryMove::SPECIAL
) {}

void Sludge::DealEffect(Pokemon& attacker, Pokemon& target) {

	if (this->RandomProbabilityGenerator((float)30 / 100)) 
		target.TakeEffect("poison");
}

Screech::Screech() : Move(
	"Screech",
	0,
	85,
	0,
	BasicType::NORMAL,
	CategoryMove::STATUS
) {}

void Screech::DealEffect(Pokemon& attacker, Pokemon& target) {

	if (this->CanAttack(attacker, (float)this->accuracy / 100)) 
		target.LowerStat("defense", 20);
}

Bulldoze::Bulldoze() : Move(
	"Bulldoze",
	60,
	100,
	0,
	BasicType::GROUND,
	CategoryMove::PHYSICAL
) {}

void Bulldoze::DealEffect(Pokemon& attacker, Pokemon& target) {

	target.LowerStat("speed", 20);
}

EarthPower::EarthPower() : Move(
	"Earth Power",
	90,
	100,
	0,
	BasicType::GROUND,
	CategoryMove::SPECIAL
) {}

void EarthPower::DealEffect(Pokemon& attacker, Pokemon& target) {

	if (this->RandomProbabilityGenerator((float)30 / 100))
		target.LowerStat("defense", 20);
}

Agility::Agility() : Move(
	"Agility",
	0,
	0,
	0,
	BasicType::PSYCHIC,
	CategoryMove::STATUS
) {}

void Agility::DealEffect(Pokemon& attacker, Pokemon& target) {

	attacker.RaiseStat("speed", 20);
}

WingAttack::WingAttack() : Move(
	"WingAttack",
	60,
	100,
	0,
	BasicType::FLYING,
	CategoryMove::PHYSICAL
) {}

AirSlash::AirSlash() : Move(
	"Air Slash",
	75,
	95,
	0,
	BasicType::FLYING,
	CategoryMove::SPECIAL
) {}

void AirSlash::DealEffect(Pokemon& attacker, Pokemon& target) {

	if (this->RandomProbabilityGenerator((float)30 / 100))
		target.TakeEffect("flinch");
}

MegaPunch::MegaPunch() : Move(
	"Mega Punch",
	80,
	85,
	0,
	BasicType::NORMAL,
	CategoryMove::PHYSICAL
) {}

CalmMind::CalmMind() : Move(
	"Calm Mind",
	0,
	0,
	0,
	BasicType::PSYCHIC,
	CategoryMove::STATUS
) {}

void CalmMind::DealEffect(Pokemon& attacker, Pokemon& target) {

	attacker.RaiseStat("specialAttack", 20);
	attacker.RaiseStat("specialDefense", 20);
}

PsychoCut::PsychoCut() : Move(
	"Psycho Cut",
	70,
	100,
	0,
	BasicType::PSYCHIC,
	CategoryMove::PHYSICAL
) {}

void PsychoCut::DealDamage(Pokemon& attacker, Pokemon& target, float criticalChance) {

	Move::DealDamage(attacker, target, (float)1 / 8);
}

Psyshock::Psyshock() : Move(
	"Psyshock",
	80,
	100,
	0,
	BasicType::PSYCHIC,
	CategoryMove::SPECIAL
) {}

Leer::Leer() : Move(
	"Leer",
	0,
	100,
	0,
	BasicType::NORMAL,
	CategoryMove::STATUS
) {}

void Leer::DealEffect(Pokemon& attacker, Pokemon& target) {

	attacker.LowerStat("defense", 20);
}

XScissor::XScissor() : Move(
	"X-Scissor",
	80,
	100,
	0,
	BasicType::BUG,
	CategoryMove::PHYSICAL
) {}

BugBuzz::BugBuzz() : Move(
	"Bug Buzz",
	90,
	100,
	0,
	BasicType::BUG,
	CategoryMove::SPECIAL
) {}

void BugBuzz::DealEffect(Pokemon& attacker, Pokemon& target) {

	if (this->RandomProbabilityGenerator((float)10 / 100))
		target.LowerStat("defense", 20);
}

Harden::Harden() : Move(
	"Harden",
	0,
	0,
	0,
	BasicType::NORMAL,
	CategoryMove::STATUS
) {}

void Harden::DealEffect(Pokemon& attacker, Pokemon& target) {

	attacker.RaiseStat("defense", 20);
}

RockThrow::RockThrow() : Move(
	"Rock Throw",
	50,
	90,
	0,
	BasicType::ROCK,
	CategoryMove::PHYSICAL
) {}

PowerGem::PowerGem() : Move(
	"Power Gem",
	80,
	100,
	0,
	BasicType::ROCK,
	CategoryMove::SPECIAL
) {}