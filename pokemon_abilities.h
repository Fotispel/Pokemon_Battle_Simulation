#include "poke_important.h"

#define ABILITY Ability
#define IF if
#define ELSE else
#define DO ,
#define START
#define END
#define ROUNDS
#define HEAL +
#define DAMAGE -
#define ATTACKER
#define DEFENDER
#define ACTION false ? -1
#define FOR

class Ability;
map<string, Ability> allAbilities;

class Ability
{
private:
    string name;
    int action;

public:
    Ability() {}
    Ability(Ability *copy)
    { // deep copy constructor
        name = copy->name;
        action = copy->action;
    }
	Ability(string name, int action)
	{
		this->name = name;
		this->action = action;
		Ability dummy(this);
		allAbilities.insert(pair<string, Ability>(getAbilitynName(), dummy));
	}


    string getAbilitynName() const
    {
        return this->name;
    }
    int getAbilityAction() const
    {
        return this->action;
    }
};
ostream &operator<<(ostream &out, Ability const &data)
{
    out << "Name: " << data.getAbilitynName() << endl;
    return out;
}
