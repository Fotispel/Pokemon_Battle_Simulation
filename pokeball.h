#include "poke_important.h"
#ifndef POKEBALL_H
#define POKEBALL_H
class Pokeball {
    public:
		Pokeball() {};
		Pokeball operator-();
		Pokeball operator--();
		Pokeball(int);
	private:
		string value;
};
#endif
