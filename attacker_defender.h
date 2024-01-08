#ifndef ATTACKER_DEFENDER_H
#define ATTACKER_DEFENDER_H
#include "poke_important.h"
#include "pokemon.h"
#include "pokemon_abilities.h"
#include "pokeball.h"
class attacker_defender
{
private:
    string is_attacker_defender;

public:
    attacker_defender(string is_attacker_defender1)
    {
        this->is_attacker_defender = is_attacker_defender1;
    }

    void operator,(int hp_change)
    {
        if (is_attacker_defender == "attacker" && damage == true)
        {
            Attacker_duel.DamageAttacker(hp_change);
        }
        else if (is_attacker_defender == "attacker" && heal == true)
        {
            Attacker_duel.HealAttacker(hp_change);
        }
        else if (is_attacker_defender == "defender" && damage == true)
        {
            Defender_duel.DamageDefender(Defender_duel, hp_change);
        }
        else if (is_attacker_defender == "defender" && heal == true)
        {
            Defender_duel.HealDefender(Defender_duel, hp_change);
        }
    }

    void operator,(Pokeball pokeball)
    {
        if (is_attacker_defender == "attacker")
        {
            Attacker_duel.putOutPokeball();
        }
        else if (is_attacker_defender == "defender")
        {
            Defender_duel.putOutPokeball();
        }
    }

    void operator,(char character_)
    {
        if (is_attacker_defender == "attacker")
        {
            Attacker_duel.putInPokeball();
        }
        else if (is_attacker_defender == "defender")
        {
            Defender_duel.putInPokeball();
        }
    }
};

attacker_defender attacker("attacker");
attacker_defender defender("defender");
attacker_defender pokeball("pokeball");

#endif