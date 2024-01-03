#include "pokemon_abilities.h"
#include "pokemon.h"
/*BEGIN_GAME
class Create_Ability {
    Create_Ability ca{
        false ? "problem in create_ability" : "Solar_Power"
    };
};
END_GAME*/
BEGIN_GAME
/*CREATE ABILITY {
NAME: "Bite",
ACTION: START
//Επιστρέφει το αντίπαλο pokemon στο pokeball
POKEBALL DEFENDER _
// Μετά απο 2 γύρους ξαναβγάζει τον αντίπαλο(DEFENDER)
AFTER 2 ROUNDS DO
POKEBALL DEFENDER ---α
END
}
END
CREATE ABILITY {
NAME: "Solar_Power",
ACTION: START
// Για 5 γύρους κάνει 8 damage στον αντίπαλο (DEFENDER)
FOR 5 ROUNDS DO
DAMAGE DEFENDER 8
END
END
}
CREATE ABILITY {
NAME: "Slash",
ACTION: START
// Κάνει 22 damage στον αντίπαλο (DEFENDER)
DAMAGE DEFENDER 22
END
}
CREATE ABILITY {
NAME: "Blaze",
ACTION: START
// Κάνει heal στον εαυτό του (ATTACKER)
HEAL ATTACKER 30
END
}*/
CREATE POKEMON{
    NAME : "Charizard",
    TYPE : "Fire",
    HP : 100
}

CREATE POKEMON{
    NAME : "Pikachu",
    TYPE : "Electric",
    HP : 90
}

CREATE POKEMONS [
POKEMON{
    NAME: "Ho Oh",
    TYPE: "Fire",
    HP: 120
},
POKEMON{
    NAME: "Bulbasaur",
    TYPE: "Grass",
    HP: 85
}
]
;

CREATE ABILITIES [
    ABILITY{
    NAME: "Bite"
    },
    ABILITY{
    NAME: "Solar_Power"
    }
]
;

CREATE ABILITY {
NAME: "Slash",
ACTION: START
    //damageValues["attacker1"] = 22;
    DAMAGE ATTACKER 22
    DAMAGE ATTACKER 25
    DAMAGE DEFENDER 23
    HEAL ATTACKER 30
    HEAL DEFENDER 35
    ;cout << "heal " << healValues["attacker1"] << endl;
END
}

    
;for (const auto &pokemon : allPokemons) {
    cout << "Name: " << pokemon.second.getPokemonName() << ", Type: " << pokemon.second.getPokemonType() << ", HP: " << pokemon.second.getHealthPoints() << endl << endl;
}

;for (const auto &ability : allAbilities) {
    cout << ability.second.getAbilityName() << endl;
}


/*
DEAR "Charizard" LEARN [
ABILITY_NAME(Bite)
ABILITY_NAME(Solar_Power)
ABILITY_NAME(Slash)
ABILITY_NAME(Blaze)
]
DEAR "Pikachu" LEARN [
ABILITY_NAME(Bite)
ABILITY_NAME(Slash)
ABILITY_NAME(Electric_Shock)
]
DUEL*/
END_GAME