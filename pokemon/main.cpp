#include "pokemon.h"

int main() {
	   
	std::vector <Pokemon> pokedex{
		Pokemon("Pikachu", 324, 306, 229, 306, 284, 350, BasicType::ELECTRIC),
		Pokemon("Venusaur", 364, 289, 291, 328, 328, 284, BasicType::GRASS),
		Pokemon("Charizard", 360, 293, 280, 348, 295, 328, BasicType::FIRE),
		Pokemon("Blastoise", 362, 291, 238, 295, 339, 280, BasicType::WATER),
		Pokemon("Walrein", 424, 284, 306, 317, 306, 251, BasicType::ICE),
		Pokemon("Lucario", 344, 350, 262, 361, 262, 306, BasicType::FIGHTING),
		Pokemon("Weezing", 334, 306, 372, 295, 262, 240, BasicType::POISON),
		Pokemon("Dugtrio", 274, 328, 218, 218, 262, 372, BasicType::GROUND),
		Pokemon("Pidgeot", 370, 284, 273, 262, 262, 331, BasicType::FLYING),
		Pokemon("Alakazam", 314, 218, 207, 405, 317, 372, BasicType::PSYCHIC),
		Pokemon("Scyther", 344, 350, 284, 229, 284, 339, BasicType::BUG),
		Pokemon("Onix", 274, 207, 460, 174, 207, 262, BasicType::ROCK)
	};

	std::cout << "Chon Pokemon: \n";
	for (int i = 0; i < pokedex.size(); i++) {
		if (i % 3 == 0) std::cout<<"\n";
		std::cout << "(" << i + 1 << ")";
		pokedex[i].ShowName();
	}

	//std::vector <Pokemon> Player;
	//int n;
	//std::cout << "Nhap pokemon muon chon: "; std::cin >> n;
	//Player.push_back(pokedex[n - 1]);

	return 0;
}