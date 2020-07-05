#include "pokemon.h"
#include "move.h"

// Default constructor
Pokemon::Pokemon() = default;

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

// Copy constructor
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

// Destructor
Pokemon::~Pokemon() {

	for (auto move : this->moves)
		delete move;
}

// Hiện 4 move của Pokemon
void Pokemon::ShowPokemonMoves() {
	
	for (int i = 0; i < this->moves.size(); i++) 
		std::cout << "(" << i + 1 << ") " << moves[i]->moveName << std::endl;
}

// Thực hiện đòn đánh
void Pokemon::Attack(Move* move, Pokemon* target) {

	// MoveCategory PHYSICAL và SPECIAL
	if (move->category == CategoryMove::PHYSICAL || move->category == CategoryMove::SPECIAL) {
		std::cout << this->pokemonName << " used " << move->moveName << " on " << target->pokemonName << "!" << std::endl;
		move->DealDamage(this, target);
	}
	// MoveCategory STATUS
	else if (move->category == CategoryMove::STATUS) {
		std::cout << this->pokemonName << " used " << move->moveName << "!" << std::endl;
		move->DealEffect(this, target);
	}
}

// Nhận damage
void Pokemon::TakeDamage(int damage) {

	// 1000 là số damage mặc định cho những Move tự sát
	if (damage == 1000)
		damage = this->currentHitPoints;
	this->currentHitPoints -= damage;
	std::cout << this->pokemonName << " took " << damage << " damage!" << std::endl;
	if (this->currentHitPoints<= 0)
		std::cout << this->pokemonName << " has fainted!" << std::endl; // Thông báo ngất
	else
		std::cout << this->pokemonName << " has " << this->currentHitPoints << " HP left" << std::endl;

}

// Nhận effect
void Pokemon::TakeEffect(std::string effect) {

	// Không thể nhận 2 Effect cùng lúc (không tính NORMAL)
	if (this->statusCondition == StatusCondition::NORMAL) {
		// Hiệu ứng Burn: Pokemon có type = FIRE không thể bị dính Burn
		if (effect == "burn") {
			if (this->type == BasicType::FIRE) {
				std::cout << this->pokemonName << " is immune to burn!" << std::endl;
			}
			else {
				std::cout << this->pokemonName << " was burned!" << std::endl;
				this->statusCondition = StatusCondition::BURN;
			}
		}
		// Hiệu ứng Freeze: Pokemon có type = ICE không thể bị dính Freeze
		else if (effect == "freeze") {
			if (this->type == BasicType::ICE) {
				std::cout << this->pokemonName << " is immune to freeze!" << std::endl;
			}
			else {
				std::cout << this->pokemonName << " was frozen solid!" << std::endl;
				this->statusCondition = StatusCondition::FREEZE;
			}
		}
		// Hiệu ứng Paralysis: Pokemon có type = ELECTRIC không thể bị dính Paralysis
		else if (effect == "paralysis") {
			if (this->type == BasicType::ELECTRIC) {
				std::cout << this->pokemonName << " is immune to paralysis!" << std::endl;
			}
			else {
				std::cout << this->pokemonName << " is paralyzed! It may be unable to move!" << std::endl;
				this->statusCondition = StatusCondition::PARALYSIS;
				// Paralysis giảm 1 / 2 speed
				this->speed /= 2;
			}
		}
		// Hiệu ứng Poison: Pokemon có type = POISON không thể bị dính Poison
		else if (effect == "poison") {
			if (this->type == BasicType::POISON) {
				std::cout << this->pokemonName << " is immune to poison!";
			}
			else {
				std::cout << this->pokemonName << " was poisoned!" << std::endl;
				this->statusCondition = StatusCondition::POISON;
			}
		}
		// Hiệu ứng Sleep: Không thể tấn công trong (random 1 -> 3) turn
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

// Tăng chỉ số
void Pokemon::RaiseStat(std::string stat, int value) {

	if (stat == "attack") { this->attack += value; }
	else if (stat == "defense") { this->defense += value; }
	else if (stat == "specialAttack") { this->specialAttack += value; }
	else if (stat == "specialDefense") { this->specialDefense += value; }
	else if (stat == "speed") { this->speed += value; }
	std::cout << "Raised " << this->pokemonName << "'s " << stat << " by " << value << "." << std::endl;
}

// Giảm chỉ số
void Pokemon::LowerStat(std::string stat, int value) {

	if (stat == "attack") { this->attack -= value; }
	else if (stat == "defense") { this->defense -= value; }
	else if (stat == "specialAttack") { this->specialAttack -= value; }
	else if (stat == "specialDefense") { this->specialDefense -= value; }
	else if (stat == "speed") { this->speed -= value; }
	std::cout << "Lowered " << this->pokemonName << "'s " << stat << " by " << value << "." << std::endl;

}

// Khả năng thực hiện đòn đánh dựa trên effect
bool Pokemon::CanAttack() {

	// Burn: trừ HP = 1/8 MaxHP
	if (this->statusCondition == StatusCondition::BURN) {
		std::cout << this->pokemonName << " is hurt by its burn!" << std::endl;
		this->TakeDamage(this->maxHitPoints / 8);
	}
	// Freeze: bỏ turn. Có 20% giải Effect
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
	// Paralysis: 25% bỏ turn
	else if (this->statusCondition == StatusCondition::PARALYSIS) {
		if (Move::RandomProbabilityGenerator(float(25) / 100)) {
			std::cout << this->pokemonName << " is fully paralyzed!" << std::endl;
			return false;
		}
	}
	// Poison: trừ HP = 1/8 MaxHP
	else if (this->statusCondition == StatusCondition::POISON) {
		std::cout << this->pokemonName << " is hurt by poison!" << std::endl;
		this->TakeDamage(this->maxHitPoints / 8);
	}
	// Sleep: bỏ turn. Sau (random 1 -> 3) turn sẽ giải Effect
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

	// Flinch: bỏ lượt
	if (this->isFlinch) {
		std::cout << this->pokemonName << " flinched and couldn't move!" << std::endl;
		return false;
	}

	// HP <= 0 không thể tấn công
	if (this->currentHitPoints <= 0)
		return false;

	return true;
}

// Kiểm tra trạng thái 
bool Pokemon::IsFainted() {

	// NULL khi chưa chọn Pokemon (xem thêm tại GameManager::Run)
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
