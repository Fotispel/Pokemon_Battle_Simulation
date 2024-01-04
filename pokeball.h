#include "poke_important.h"
#ifndef POKEBALL_H
#define POKEBALL_H
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
