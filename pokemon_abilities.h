#include "poke_important.h"

#define ABILITY Ability
#define IF if
#define ELSE else
#define DO 
#define START
#define END
#define ROUNDS ; i++)
#define HEAL +
#define DAMAGE -
#define ATTACKER
#define DEFENDER
#define ACTION false ? -1
#define FOR for(int i=0; i<

class Ability;
map<string, Ability> allAbilities;

class Ability{
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
		allAbilities.insert(pair<string, Ability>(getAbilityName(), dummy));
	}
    string getAbilityName() const
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
    out << "Name: " << data.getAbilityName() << endl;
    return out;
}
