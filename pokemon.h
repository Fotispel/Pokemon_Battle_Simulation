#include "poke_important.h"
#ifndef POKEMON_LIBRARY_H
#define POKEMON_LIBRARY_H
#include "pokemon_abilities.h"
class Pokemon;
extern map<string, Pokemon> allPokemons;
class Pokemon{
private:
	string name;
	string type;
	int health_points;
	bool inPokeball = false;
public:
	Pokemon() {}
	map<string, Ability> pokeAbilities;
	vector<Pokemon> uselessVector;
	Pokemon(Pokemon*);
	Pokemon(string, string, int);
	string getPokemonName() const;
	void putAttackerInPokeball();
	void putDefenderInPokeball(Pokemon);
	void DamageAttacker(int);
	void HealAttacker(int);
	void HealDefender(Pokemon, int);
	bool isInPokeball();//getter
	void putInPokeball();//setter
	void DamageDefender(Pokemon, int);
	string getPokemonType() const;
	int getHealthPoints() const;
	void setHealthPoints(int);
	Pokemon operator,(Pokemon);
	Pokemon operator[](Pokemon);
};
ostream &operator<<(ostream, Pokemon const);
#endif