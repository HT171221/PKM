#include <iostream>
#include <vector>
using namespace std;
enum class Basic_Type {
	Normal,
	Fire,
	Water,
	Grass,
	Electric,
	Ice,
	Fighting,
	Poison,
	Ground,
	Flying,
	Psychic,
	Bug,
	Rock
};
enum class Status_Condition {
	Poison,
	Burn,
	Paralysis,
	Frezze
};
class Pokemon {
	string Name;
	Basic_Type Type;
	int HP, Attack, Defense, Special_Attack, Special_Defense, Speed;
	Status_Condition Status;
	bool Alive;
public:
	Pokemon(string Name2, Basic_Type Type2, int HP2, int Attack2, int Defense2, int Special_Attack2, int Special_Defense2, int Speed2);

};
class User {
	string Username;
	int Number_Of_Pokemon;
	//mảng lưu pokemon
	//current pokemon
public:
	User(string name, int pokenum);
	//hàm push pokemon vào mảng
	//
};