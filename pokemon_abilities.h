#include "poke_important.h"

#define ABILITY Ability
#define ABILITIES Ability abil; Ability abi = abil
#define POKEMON_NAME(name)
#define DEAR ; tempPokemon=
#define LEARN ; Ability dummyAbility; Ability dummyAbility2 = dummyAbility
#define DUMMY(s1,s2) s1 ## s2
#define ABILITY_NAME(name) DUMMY(#name,"@")
#define GET_HP(Pokemon) Pokemon.getHealthPoints()
#define GET_TYPE(Pokemon) Pokemon.getPokemonType()
#define GET_NAME(Pokemon) Pokemon.getPokemonName()
#define IS_IN_POKEBALL(Pokemon) Pokemon.isInPokeball()
#define IF if (
#define ELSE }else {
#define AND(case1, case2) case1 && case2
#define OR(case1, case2) case1 || case2
#define NOT !
#define DO ){
#define HEAL ;healValues[allAbilitiesInOrder[t]]
#define DAMAGE ;damageValues[allAbilitiesInOrder[t]]
#define POKEBALL ;pokeball
#define ATTACKER ["attacker"+to_string(i++)] = 
#define DEFENDER ["defender"+to_string(v++)] =
#define ACTION false ? ([]() {})
#define START []() { t++; i = 1; v = 1;
#define FOR ;for(int f=0; f<
#define ROUNDS ; f++
#define END ;/*cout <<"RESULTS for " << allAbilitiesInOrder[t] << endl;\
        for (i=0; i<100; i++) \
        { if (damageValues[allAbilitiesInOrder[t]]["attacker"+to_string(i)]!=0) {cout<<damageValues[allAbilitiesInOrder[t]]["attacker"+to_string(i)]; cout << " ";}} \
        cout<<endl;\
        for (i=0; i<100; i++) \
        { if (damageValues[allAbilitiesInOrder[t]]["defender"+to_string(i)]!=0) {cout<<damageValues[allAbilitiesInOrder[t]]["defender"+to_string(i)]; cout << " ";}} \
        cout<<endl;\
        for (i=0; i<100; i++) \
        { if (healValues[allAbilitiesInOrder[t]]["attacker"+to_string(i)]!=0) {cout<<healValues[allAbilitiesInOrder[t]]["attacker"+to_string(i)]; cout << " ";}} \
        cout<<endl;\
        for (i=0; i<100; i++) \
        { if (healValues[allAbilitiesInOrder[t]]["defender"+to_string(i)]!=0) {cout<<healValues[allAbilitiesInOrder[t]]["defender"+to_string(i)]; cout << " ";}} \
        cout<<endl;*/\
        }


#define DUEL \
        cout << "--------------------------------POKEMON THE GAME--------------------------------" << endl;\
        cout << "Player 1 select pokemon: " << endl;\
        cout << "------------------------------------------" << endl;\
        for (const auto &pokemon : allPokemons) { \
            cout << pokemon.second.getPokemonName() << endl;\
        } \
        cout << "------------------------------------------" << endl;\
        string pokemon1; \
        cin >> pokemon1; \
        cout << endl;\
        cout << "Player 2 select pokemon: " << endl;\
        cout << "------------------------------------------" << endl;\
        string pokemon2; \
        cin >> pokemon2; \
        cout << endl;\
        cout << "------------------------------------------" << endl;\
        cout << "Round1" << endl;\
        cout << "------------------------------------------" << endl;\
        cout << "Player 1 select ability: " << endl;\



class Ability;
map<string, map<string, int>> damageValues; 
map<string,map<string, int>> healValues; 
map<string,string> pokeball;
int t=-1 ,i, v;
map<string, Ability> allAbilities;
vector <string> allAbilitiesInOrder;

class Ability
{
private:
    string name;
    function<void()> action;

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
        allAbilitiesInOrder.push_back(name);
        Ability dummy(this);
        allAbilities[getAbilityName()] = dummy;
    }
    Ability(string name, function<void()> action) : name(name), action(action){
        allAbilities.insert(make_pair(name, *this));
        allAbilitiesInOrder.push_back(name);
        executeAction();
    }
    string getAbilityName() const
    {
        return this->name;
    }

    void executeAction() {
        if (action) {
            action();
        } else {
            cout << "No action defined for " << name << endl;
        }
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
	Ability operator[](string s){
		Ability ab2;
		stringstream splitter(s);
		string AbilityName;
		Pokemon dummyPokemon=allPokemons[tempPokemon];
		while(!splitter.eof()){
			getline(splitter, AbilityName, '@');
			dummyPokemon.pokeAbilities.insert(make_pair(AbilityName,allAbilities[AbilityName]));
		}
		return ab2;
	}
};
ostream &operator<<(ostream &out, Ability const &data)
{
    out << "Name: " << data.getAbilityName() << endl;
    return out;
}
Ability operator+(string ppp){
		Ability ab;

}