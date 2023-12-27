#include "poke_important.h"

#define POKEMON Pokemon
#define HP false ? -22
#define TYPE NAME
class Pokemon;
map<string, Pokemon> allPokemons;
class Pokemon{
	private:
		string name;
		string type;
		int health_points;
	public:
		Pokemon(){}
		Pokemon(Pokemon* copy){//deep copy constructor
			name=copy->name;
			type=copy->type;
			health_points=copy->health_points;
		}
		Pokemon(string name,string type,int hp){
			this->name=name;
			this->type=type;
			this->health_points=hp;
			Pokemon dummy(this); //or Pokemon *dummy = new Pokemon(this);
			allPokemons.insert(pair<string,Pokemon>(getPokemonName(),dummy));
			//delete dummy;
		}
		string getPokemonName() const{
			return this->name;
		}
		string getPokemonType() const{
			return this->type;
		}
		int getHealthPoints() const{
			return this->health_points;
		}
		void setHealthPoints(int hp){
			this->health_points=hp;
		}
};
ostream& operator<<(ostream &out, Pokemon const& data){
	out<<"Name: "<<data.getPokemonName()<<" Type: "<<data.getPokemonType()<<" Health points: "<<data.getHealthPoints()<<endl;
	return out;
}
/*Για να φτιαξω το προβλημα με το ΠΟΚΕΜΟΝΣ[] μπορω να κανω οβερλοαντ το κομμα το οποιο θα λαμβανει το δεξι μερος και θα το βαζει σε βεκτορ
και θα επιστρεφει το βεκτορ*/