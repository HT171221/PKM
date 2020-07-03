#pragma once
#include <string>
enum class BasicType;

enum class CategoryMove {

	PHYSICAL,
	SPECIAL,
	STATUS
};

class Pokemon;

class Move {
private:
	std::string moveName;
	int power;
	int accuracy;
	BasicType type;
	CategoryMove category;

public:
	Move(std::string moveName, int power, int accuracy, BasicType type, CategoryMove category);
	void ShowMoveName();
	bool RandomProbabilityGenerator(int probability);
	int RandomNumberGenerator(int minNumber, int maxNumber);
	virtual void Effect(Pokemon* pokemonAttacked, Pokemon* PokemonBeAttaked);
};

class Tackle : public Move {
public:
	Tackle();
};

class SleepPowder : public Move {
public:
	SleepPowder();
	//void Effect(Pokemon& pokemonAttacked, Pokemon& PokemonBeAttaked) override;
};

class MagicalLeaf : public Move {
public:
	MagicalLeaf();
};

class RazorLeaf : public Move {
public:
	RazorLeaf();
	//
};

class Scratch : public Move {
public:
	Scratch();
};

class WillOWisp : public Move {
public:
	WillOWisp();
	//
};

class FireFang : public Move {
public:
	FireFang();
	//
};

class FlameThrower : public Move {
public:
	FlameThrower();
	//
};

class Withdraw : public Move {
public:
	Withdraw();
	//
};

class AquaTail : public Move {
public:
	AquaTail();
};

class WaterGun : public Move {
public:
	WaterGun();
};

class QuickAttack : public Move {
public:
	QuickAttack();
};
//

class ThunderWave : public Move {
public:
	ThunderWave();
};
//

class Spark : public Move {
public:
	Spark();
};
//

class Thunderbolt : public Move {
public:
	Thunderbolt();
};
//

class BodySlam : public Move {
public:
	BodySlam();
};
//

class DefenseCurl : public Move {
public:
	DefenseCurl();
};
//

class IceFang : public Move {
public:
	IceFang();
};
//

class IceBeam : public Move {
public:
	IceBeam();
};
//

class SwordsDance : public Move {
public:
	SwordsDance();
};
//

class PoweUpPunch : public Move {
public:
	PoweUpPunch();
};
//

class VacuumWave : public Move {
public:
	VacuumWave();
};
//

class PoisonGas : public Move {
public:
	PoisonGas();
};
//

class SelfDestruct : public Move {
public:
	SelfDestruct();
};
//

class Sludge : public Move {
public:
	Sludge();
};
//

class Screech : public Move {
public:
	Screech();
};
//

class Bulldoze : public Move {
public:
	Bulldoze();
};
//

class EarthPower : public Move {
public:
	EarthPower();
};
//

class Agility : public Move {
public:
	Agility();
};
//

class WingAttack : public Move {
public:
	WingAttack();
};

class AirSlash : public Move {
public:
	AirSlash();
};
//

class MegaPunch : public Move {
public:
	MegaPunch();
};

class CalmMind : public Move {
public:
	CalmMind();
};
//

class PsychoCut : public Move {
public:
	PsychoCut();
};
//

class Psyshock: public Move {
public:
	Psyshock();
};
//

class Leer : public Move {
public:
	Leer();
};
//

class FuryCutter : public Move {
public:
	FuryCutter();
};
//

class BugBuzz : public Move {
public:
	BugBuzz();
};
//

class Harden : public Move {
public:
	Harden();
};
//

class RockThrow : public Move {
public:
	RockThrow();
};

class PowerGem : public Move {
public:
	PowerGem();
};

