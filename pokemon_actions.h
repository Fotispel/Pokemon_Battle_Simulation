#include "poke_important.h"

#define POKEMON Pokemon pok =

class Pokemon{
	private:
		string name;
		string type;
		int health_points;
	public:
		Pokemon(string name,string type,int hp){
			this->name=name;
			this->type=type;
			this->health_points=hp;
		}
		string getPokemonName(){
			return this->name;
		}
		string getPokemonType(){
			return this->type;
		}
		int getHealthPoints(){
			return this->health_points;
		}
		void setHealthPoints(int hp){
			this->health_points=hp;
		}
		void PrintPokemon(){
			cout<<"Name: "<<this->name<<"Type: "<<this->type<<"Health points: "<<this->health_points<<endl;
		}
};