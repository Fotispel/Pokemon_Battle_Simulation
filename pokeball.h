#include "poke_important.h"

class Pokeball {
    public:
    Pokeball operator-(){
        return *this;
    }

    Pokeball operator--(){
        return *this;
    }
};
Pokeball α;

map<string,map<string,Pokeball>> pokeballMap;

#define POKEBALL ;pokeballMap[allAbilitiesInOrder[t]]

