#include "pokemon.h"
#include "pokemon_abilities.h"
#include "pokeball.h"
#include "duel.h"
#include "attacker_defender.h"

BEGIN_GAME

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
    HP: 80
},
POKEMON{
    NAME: "Bulbasaur",
    TYPE: "Grass",
    HP: 85
}
]
;

CREATE ABILITY {
NAME: "Blaze",
ACTION :  START
        // t++; i = 1; v = 1; name_ability = allAbilitiesInOrder[allAbilitiesInOrder.size()-1];
        // IF GET_HP(ATTACKER) < 50 DO
        //     DAMAGE ATTACKER 20
        // END

        FOR 2 ROUNDS DO DAMAGE ATTACKER 10 END
    END
}



CREATE ABILITIES [
    ABILITY{
    NAME: "Bite",
    ACTION: START
        DAMAGE ATTACKER 20
    END
    },
    ABILITY{
    NAME: "Solar_Power",
    ACTION: START
        DAMAGE ATTACKER 10
        HEAL ATTACKER 5
    END
    }
]
;


CREATE ABILITY {
NAME: "Fire",
ACTION : START
POKEBALL ATTACKER _
POKEBALL DEFENDER _
DAMAGE ATTACKER 20
END
}


CREATE ABILITY {
NAME: "Slash",
ACTION: START
    DAMAGE ATTACKER 22
END
}
;


DEAR "Charizard" LEARN [
ABILITY_NAME(Bite)
ABILITY_NAME(Solar_Power)
ABILITY_NAME(Slash)
ABILITY_NAME(Blaze)
];
DEAR "Pikachu" LEARN [
ABILITY_NAME(Bite)
ABILITY_NAME(Slash)
ABILITY_NAME(Electric_Shock)
ABILITY_NAME(Solar_Power)
ABILITY_NAME(Blaze)
];

DEAR "Ho Oh" LEARN [
ABILITY_NAME(Bite)
ABILITY_NAME(Solar_Power)
ABILITY_NAME(Blaze)
];

DEAR "Bulbasaur" LEARN [
ABILITY_NAME(Bite)
ABILITY_NAME(Solar_Power)
];


DUEL
END_GAME