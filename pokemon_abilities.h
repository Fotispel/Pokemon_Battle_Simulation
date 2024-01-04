#ifndef POKEMON_ABILITIES_H
#define POKEMON_ABILITIES_H
#include "poke_important.h"
extern vector <string> allAbilitiesInOrder;
extern map<string, map<string, int>> damageValues;
extern map<string,map<string, int>> healValues;
class Ability;
extern map<string, Ability> allAbilities;
class Ability{
private:
    string name;
    function<void()> action;
public:
    vector<Ability> uselessVector;
    Ability() {}
    Ability(Ability*);
    Ability(string);
    Ability(string, function<void()>);
    string getAbilityName() const;
    void executeAction();
    Ability operator,(Ability);
    Ability operator[](Ability);
	Ability operator[](string);
};
ostream &operator<<(ostream, Ability const);
string operator+(string);
#endif