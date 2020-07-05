#pragma once
#include <string>
#include <vector>
enum class BasicType;

enum class CategoryMove {

	PHYSICAL,
	SPECIAL,
	STATUS
};

class Pokemon;

class Move {
protected:
	std::string moveName;
	int power;
	int accuracy;
	int priority;
	BasicType type;
	CategoryMove category;

public:
	Move();
	Move(std::string moveName, int power, int accuracy, int priority, BasicType type, CategoryMove category);
	static bool RandomProbabilityGenerator(float probability);
	static int RandomNumberGenerator(int minNumber, int maxNumber);
	virtual void DealDamage(Pokemon* attacker, Pokemon* target, float criticalChance = (float)1 / 24);
	virtual void DealEffect(Pokemon* attaker, Pokemon* target);
	bool CanAttack(Pokemon* attacker, float probability);

	friend class Pokemon;
	friend class GameManager;
};

class Tackle : public Move {
public:
	Tackle();
};

class SleepPowder : public Move {
public:
	SleepPowder();
	void DealEffect(Pokemon* attacker, Pokemon* target) override;
};

class MagicalLeaf : public Move {
public:

	MagicalLeaf();
};

class RazorLeaf : public Move {
public:
	RazorLeaf();
	void DealDamage(Pokemon* attacker, Pokemon* target, float criticalChance) override;
};

class Scratch : public Move {
public:
	Scratch();
};

class WillOWisp : public Move {
public:
	WillOWisp();
	void DealEffect(Pokemon* attacker, Pokemon* target) override;
};

class FireFang : public Move {
public:
	FireFang();
	void DealEffect(Pokemon* attacker, Pokemon* target) override;
};

class FlameThrower : public Move {
public:
	FlameThrower();
	void DealEffect(Pokemon* attacker, Pokemon* target) override;
};

class Withdraw : public Move {
public:
	Withdraw();
	void DealEffect(Pokemon* attacker, Pokemon* target) override;
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

class ThunderWave : public Move {
public:
	ThunderWave();
	void DealEffect(Pokemon* attacker, Pokemon* target) override;
};

class Spark : public Move {
public:
	Spark();
	void DealEffect(Pokemon* attacker, Pokemon* target) override;
};

class Thunderbolt : public Move {
public:
	Thunderbolt();
	void DealEffect(Pokemon* attacker, Pokemon* target) override;
};

class BodySlam : public Move {
public:
	BodySlam();
	void DealEffect(Pokemon* attacker, Pokemon* target) override;
};

class DefenseCurl : public Move {
public:
	DefenseCurl();
	void DealEffect(Pokemon* attacker, Pokemon* target) override;
};

class IceFang : public Move {
public:
	IceFang();
	void DealEffect(Pokemon* attacker, Pokemon* target) override;
};

class IceBeam : public Move {
public:
	IceBeam();
	void DealEffect(Pokemon* attacker, Pokemon* target) override;
};

class SwordsDance : public Move {
public:
	SwordsDance();
	void DealEffect(Pokemon* attacker, Pokemon* target) override;
};

class PowerUpPunch : public Move {
public:
	PowerUpPunch();
	void DealEffect(Pokemon* attacker, Pokemon* target) override;
};

class VacuumWave : public Move {
public:
	VacuumWave();
};

class PoisonGas : public Move {
public:
	PoisonGas();
	void DealEffect(Pokemon* attacker, Pokemon* target) override;
};

class SelfDestruct : public Move {
public:
	SelfDestruct();
	void DealEffect(Pokemon* attacker, Pokemon* target) override;
};

class Sludge : public Move {
public:
	Sludge();
	void DealEffect(Pokemon* attacker, Pokemon* target) override;
};

class Screech : public Move {
public:
	Screech();
	void DealEffect(Pokemon* attacker, Pokemon* target) override;
};

class Bulldoze : public Move {
public:
	Bulldoze();
	void DealEffect(Pokemon* attacker, Pokemon* target) override;
};

class EarthPower : public Move {
public:
	EarthPower();
	void DealEffect(Pokemon* attacker, Pokemon* target) override;
};

class Agility : public Move {
public:
	Agility();
	void DealEffect(Pokemon* attacker, Pokemon* target) override;
};

class WingAttack : public Move {
public:
	WingAttack();
};

class AirSlash : public Move {
public:
	AirSlash();
	void DealEffect(Pokemon* attacker, Pokemon* target) override;
};

class MegaPunch : public Move {
public:
	MegaPunch();
};

class CalmMind : public Move {
public:
	CalmMind();
	void DealEffect(Pokemon* attacker, Pokemon* target) override;
};

class PsychoCut : public Move {
public:
	PsychoCut();
	void DealDamage(Pokemon* attacker, Pokemon* target, float criticalChance) override;
};

class Psyshock: public Move {
public:
	Psyshock();
};

class Leer : public Move {
public:
	Leer();
	void DealEffect(Pokemon* attacker, Pokemon* target) override;
};

class XScissor : public Move {
public:
	XScissor();
};

class BugBuzz : public Move {
public:
	BugBuzz();
	void DealEffect(Pokemon* attacker, Pokemon* target) override;
};
//

class Harden : public Move {
public:
	Harden();
	void DealEffect(Pokemon* attacker, Pokemon* target) override;
};

class RockThrow : public Move {
public:
	RockThrow();
};

class PowerGem : public Move {
public:
	PowerGem();
};

