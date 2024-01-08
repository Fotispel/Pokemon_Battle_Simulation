#include "poke_important.h"
#ifndef POKEBALL_H
#define POKEBALL_H
extern map<string,map<int,string>> pokeballMapAttacker;
extern map<string,map<int,string>> pokeballMapDefender;
class Pokeball {
    public:
		Pokeball() {};
		Pokeball(string);
		Pokeball operator-();
		Pokeball operator--();
		string getName();
	private:
		string value;
};
#endif
