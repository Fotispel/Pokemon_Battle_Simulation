#include "poke_important.h"

#define ABILITY Ability
#define ABILITIES Ability abil; Ability abi = abil
#define IF if
#define ELSE else
#define DO
#define HEAL ;healValues
#define DAMAGE ;damageValues[allAbilitiesInOrder[t]]
#define POKEBALL ;pokeball
#define ATTACKER ["attacker"+to_string(i++)] = 
#define DEFENDER ["defender"+to_string(v++)] =
#define ACTION false ? ([]() {})
#define START []() { t++; map<string, map<string, int>> damageValues; map<string,map<string, int>> healValues; map<string,string> pokeball[100]; i = 1; v = 1;
#define FOR ;for(int f=0; f<
#define ROUNDS ; f++) {
#define END ;cout <<"RESULTS for " << allAbilitiesInOrder[t] << endl;\
        for (i=0; i<100; i++) \
        { if (damageValues[allAbilitiesInOrder[t]]["attacker"+to_string(i)]!=0) {cout<<damageValues[allAbilitiesInOrder[t]]["attacker"+to_string(i)]; damageValues[allAbilitiesInOrder[t]]["attacker"+to_string(i)]=0; cout << " ";}} \
        cout<<endl;\
        for (i=0; i<100; i++) \
        { if (damageValues[allAbilitiesInOrder[t]]["defender"+to_string(i)]!=0) {cout<<damageValues[allAbilitiesInOrder[t]]["defender"+to_string(i)]; damageValues[allAbilitiesInOrder[t]]["defender"+to_string(i)]=0; cout << " ";}} \
        cout<<endl;\
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
};
ostream &operator<<(ostream &out, Ability const &data)
{
    out << "Name: " << data.getAbilityName() << endl;
    return out;
}
