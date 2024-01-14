#ifndef POKEMON_ABILITIES_H
#define POKEMON_ABILITIES_H
#include "poke_important.h"
extern vector <string> allAbilitiesInOrder;
extern map<string, function<void()>> Ability_with_actions;
extern map<int,map<string, function<void()>>> for_actions;
extern string name_ability;
extern bool heal, damage, for_state, after_state;
extern  int isAttacking, isDefending;
extern int f;
extern vector<int> round_for;

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