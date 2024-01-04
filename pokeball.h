#include "poke_important.h"
#ifndef POKEBALL_H
#define POKEBALL_H
class Pokeball {
    private:
        string value;
    public:
    Pokeball operator-();
    Pokeball operator--();
    Pokeball(string);
};
#endif
