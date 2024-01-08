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
ACTION : START
    DAMAGE ATTACKER 20
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
];

DEAR "Ho Oh" LEARN [
ABILITY_NAME(Bite)
ABILITY_NAME(Solar_Power)
];

DEAR "Bulbasaur" LEARN [
ABILITY_NAME(Bite)
ABILITY_NAME(Solar_Power)
];

DUEL
END_GAME