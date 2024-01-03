#include "poke_important.h"

#define POKEMON Pokemon
#define POKEMONS Pokemon pk; Pokemon pok = pk
#define HP false ? -22
#define TYPE NAME

class Pokemon;
map<string, Pokemon> allPokemons;
class Pokemon{
private:
	string name;
	string type;
	int health_points;
	bool inPokeball;
public:
	Pokemon() {}
	vector<Pokemon> uselessVector;
	Pokemon(Pokemon *copy)
	{ // deep copy constructor
		name = copy->name;
		type = copy->type;
		health_points = copy->health_points;
	}
	Pokemon(string name, string type, int hp)
	{
		this->name = name;
		this->type = type;
		this->health_points = hp;
		Pokemon dummy(this); // or Pokemon *dummy = new Pokemon(this);
		allPokemons[getPokemonName()] = dummy;
		// delete dummy;
	}
	string getPokemonName() const{
		return this->name;
	}
	void putAttackerInPokeball(){
		this->inPokeball = true;
	}
	void putDefenderInPokeball(Pokemon p){
		p.putInPokeball();
	}
	void DamageAttacker(int damage){
		this->health_points -= damage;
	}
	void HealAttacker(int heal){
		this->health_points += heal;
	}
	void HealDefender(Pokemon p, int heal){
		p.setHealthPoints(p.getHealthPoints() + heal);
	}
	bool isInPokeball(){//getter
		return this->inPokeball;
	}
	void putInPokeball(){//setter
		this->inPokeball = true;
	}
	void DamageDefender(Pokemon p, int damage){
		p.setHealthPoints(p.getHealthPoints() - damage);
	}
	string getPokemonType() const{
		return this->type;
	}
	int getHealthPoints() const{
		return this->health_points;
	}
	void setHealthPoints(int hp){
		this->health_points = hp;
	}
	Pokemon operator,(Pokemon p){
	    uselessVector.push_back(p);
	    return *this;
	}
	Pokemon operator[](Pokemon p){
	    return p;
	}
};
ostream &operator<<(ostream &out, Pokemon const &data){
	out << "Name: " << data.getPokemonName() << " Type: " << data.getPokemonType() << " Health points: " << data.getHealthPoints() << endl;
	return out;
}