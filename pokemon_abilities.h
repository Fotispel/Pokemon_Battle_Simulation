#include "poke_important.h"

#define ABILITY Ability
#define ABILITIES Ability abil; Ability abi = abil
#define IF if
#define ELSE else
#define DO
#define HEAL ;healValues
#define DAMAGE ;damageValues
#define POKEBALL ;pokeball
#define ATTACKER ["attacker"+to_string(i++)] = 
#define DEFENDER ["defender"+to_string(v++)] =
#define ACTION false ? ([]() {})
#define START []() { map<string, int> damageValues; map<string, int> healValues; map<string,string> pokeball; int i = 1; int v = 1;
#define FOR ;for(int f=0; f<
#define ROUNDS ; f++) {
#define END ;cout <<"RESULTS: "<<endl;\
        for (i=0; i<100; i++) \
        { if (damageValues["attacker"+to_string(i)]!=0) {cout<<damageValues["attacker"+to_string(i)]; damageValues["attacker"+to_string(i)]=0; cout << " ";}} \
        cout<<endl;\
        for (i=0; i<100; i++) \
        { if (damageValues["defender"+to_string(i)]!=0) {cout<<damageValues["defender"+to_string(i)]; damageValues["defender"+to_string(i)]=0; cout << " ";}} \
        cout<<endl;\
        for (i=0; i<100; i++) \
        {if (healValues["attacker"+to_string(i)]!=0) {cout<<healValues["attacker"+to_string(i)]; healValues["attacker"+to_string(i)]=0; cout<<" ";}} \
        cout<<endl;\
        for (i=0; i<100; i++) \
        {if (healValues["defender"+to_string(i)]!=0) {cout<<healValues["defender"+to_string(i)]; healValues["defender"+to_string(i)]=0; cout<<" ";}} \
        cout<<endl;\
        } 

class Ability;
map<string, Ability> allAbilities;

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
        Ability dummy(this);
        allAbilities.insert(pair<string, Ability>(getAbilityName(), dummy));
    }
    Ability(string name, function<void()> action) : name(name), action(action){
        allAbilities.insert(make_pair(name, *this));
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
