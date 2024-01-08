#include "pokemon_abilities.h"
#include "poke_important.h"
#include "pokemon.h"
vector<string> allAbilitiesInOrder;
map<string, function<void()>> Ability_with_actions;
string name_ability;
map<string, Ability> allAbilities;
bool heal, damage;
int t = 0, i, v;
Ability::Ability(Ability *copy)
{ // deep copy constructor
	name = copy->name;
	// action = copy->action;
}
Ability::Ability(string name)
{
	this->name = name;
	allAbilitiesInOrder.push_back(name);
	Ability dummy(this);
	allAbilities[getAbilityName()] = dummy;
}
Ability::Ability(string name, function<void()> action) : name(name), action(action)
{
	allAbilities.insert(make_pair(name, *this));
	allAbilitiesInOrder.push_back(name);
	name_ability = name;
	executeAction();
}
string Ability::getAbilityName() const
{
	return this->name;
}
void Ability::executeAction()
{
	if (action)
	{
		action();
	}
	else
	{
		cout << "No action defined for " << name << endl;
	}
}
Ability Ability::operator,(Ability ab)
{
	uselessVector.push_back(ab);
	return *this;
}
Ability Ability::operator[](Ability ab)
{
	return ab;
}
Ability Ability::operator[](string s)
{
	Ability ab2;
	stringstream splitter(s);
	string AbilityName;
	extern map<string, Pokemon> allPokemons;
	while (!splitter.eof())
	{
		getline(splitter, AbilityName, '@');
		(allPokemons[tempPokemon]).pokeAbilities.insert(make_pair(AbilityName, allAbilities[AbilityName]));
	}
	return ab2;
}
ostream &operator<<(ostream &out, Ability const &data)
{
	out << "Name: " << data.getAbilityName() << endl;
	return out;
}
string operator+(string ppp)
{
	return ppp;
}