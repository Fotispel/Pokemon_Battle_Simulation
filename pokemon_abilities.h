#include "poke_important.h" // @Fotispel μετακίνησα όλες τις βιβλιοθήκες σέ ένα ενιαίο αρχείο. Εκεί θα προσθέτουμε πράγματα που θέλουν και οι 2
#define CREATE
#define ABILITY class Create_Ability
#define NAME Create_Ability ca{ false ? "problem in create_ability"

string name;
int rounds, damage_defender, damage_attacker, heal_defender, heal_attacker;

void set_values(string name, int rounds, int damage_defender, int damage_attacker, int heal_defender, int heal_attacker)
{
    name = name;
    rounds = rounds;
    damage_defender = damage_defender;
    damage_attacker = damage_attacker;
    heal_defender = heal_defender;
    heal_attacker = heal_attacker;
}

class Create_Ability
{
public:
    string name;
    int rounds;
    int damage_defender;
    int damage_attacker;
    int heal_defender;
    int heal_attacker;
    Create_Ability(string name, int rounds, int damage_defender, int damage_attacker,
                   int heal_defender, int heal_attacker)
    {
        this->name = name;
        this->rounds = rounds;
        this->damage_defender = damage_defender;
        this->damage_attacker = damage_attacker;
        this->heal_defender = heal_defender;
        this->heal_attacker = heal_attacker;
    }

    string get_name()
    {
        return this->name;
    }
    int get_rounds()
    {
        return this->rounds;
    }
    int get_damage_defender()
    {
        return this->damage_defender;
    }
    int get_damage_attacker()
    {
        return this->damage_attacker;
    }
    int get_heal_defender()
    {
        return this->heal_defender;
    }
    int get_heal_attacker()
    {
        return this->heal_attacker;
    }

    void set_name(string name)
    {
        this->name = name;
    }
    void set_rounds(int rounds)
    {
        this->rounds = rounds;
    }
    void set_damage_defender(int damage_defender)
    {
        this->damage_defender = damage_defender;
    }
    void set_damage_attacker(int damage_attacker)
    {
        this->damage_attacker = damage_attacker;
    }
    void set_heal_defender(int heal_defender)
    {
        this->heal_defender = heal_defender;
    }
    void set_heal_attacker(int heal_attacker)
    {
        this->heal_attacker = heal_attacker;
    }
};