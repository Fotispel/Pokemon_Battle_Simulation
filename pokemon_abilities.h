#include "poke_important.h"

#define ABILITY Ability
#define ABILITIES Ability abil; Ability abi = abil
#define IF if
#define ELSE else
#define DO
#define END })
#define ROUNDS ; i++)
#define HEAL
#define DAMAGE
#define ATTACKER
#define DEFENDER
#define ACTION false ? ([]() {})
#define START ([]() {
#define FOR for(int i=0; i<

class Ability;
map<string, Ability> allAbilities;

class Ability
{
private:
    string name;
    function<void()> action;
    string str;

public:
    vector<Ability> uselessVector;

    Ability() {}
    Ability(Ability *copy)
    { // deep copy constructor
        name = copy->name;
        //action = copy->action;
    }
    Ability(string name)
    {
        this->name = name;
        Ability dummy(this);
        allAbilities.insert(pair<string, Ability>(getAbilityName(), dummy));
    }
    Ability(string name, function<void()> action) : name(name), action(action){
        allAbilities.insert(make_pair(name, *this));
    }
    string getAbilityName() const
    {
        return this->name;
    }

    Ability operator,(Ability ab)
    {
        uselessVector.push_back(ab);
        return *this;
    }
    Ability operator[](Ability ab)
    {
        return ab;
    }
};
ostream &operator<<(ostream &out, Ability const &data)
{
    out << "Name: " << data.getAbilityName() << endl;
    return out;
}
