#include "pokemon.h"
map<string, Pokemon> allPokemons;
Pokemon Attacker_duel, Defender_duel;
string tempPokemon;//for the overload at abilities
Pokemon::Pokemon(Pokemon *copy){ // deep copy constructor
	name = copy->name;
	type = copy->type;
	health_points = copy->health_points;
}
Pokemon::Pokemon(string name, string type, int hp){
	this->name = name;
	this->type = type;
	this->health_points = hp;
	Pokemon dummy(this); // or Pokemon *dummy = new Pokemon(this);
	allPokemons[getPokemonName()] = dummy;
	// delete dummy;
}
string Pokemon::getPokemonName() const{
	return this->name;
}
void Pokemon::putAttackerInPokeball(){
	this->inPokeball = true;
}
void Pokemon::putDefenderInPokeball(Pokemon p){
	p.putInPokeball();
}
void Pokemon::DamageAttacker(int damage){
	if (this->health_points - damage <= 0){
		this->health_points = 0;
	}
	else
		this->health_points -= damage;

}
void Pokemon::HealAttacker(int heal){
	this->health_points += heal;
}
void Pokemon::HealDefender(Pokemon p, int heal){
	p.setHealthPoints(p.getHealthPoints() + heal);
}
bool Pokemon::isInPokeball(){//getter
	return this->inPokeball;
}
void Pokemon::putInPokeball(){//setter
	this->inPokeball = true;
}
void Pokemon::putOutPokeball(){//setter
	this->inPokeball = false;
}
void Pokemon::DamageDefender(Pokemon p, int damage){
	p.setHealthPoints(p.getHealthPoints() - damage);
	if (Defender_duel.getHealthPoints() - damage <= 0){
		Defender_duel.setHealthPoints(0);
	}
	else
		Defender_duel.setHealthPoints(Defender_duel.getHealthPoints() - damage);
}
string Pokemon::getPokemonType() const{
	return this->type;
}
int Pokemon::getHealthPoints() const{
	return this->health_points;
}
void Pokemon::setHealthPoints(int hp){
	this->health_points = hp;
}
Pokemon Pokemon::operator,(Pokemon p){
	uselessVector.push_back(p);
	return *this;
}
Pokemon Pokemon::operator[](Pokemon p){
	return p;
}
ostream &operator<<(ostream &out, Pokemon const &data){
	out << "Name: " << data.getPokemonName() << " Type: " << data.getPokemonType() << " Health points: " << data.getHealthPoints() << endl;
	return out;
}