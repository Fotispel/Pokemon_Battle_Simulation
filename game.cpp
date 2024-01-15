#include "pokemon.h"
#include "pokemon_abilities.h"
#include "pokeball.h"
#include "duel.h"
#include "attacker_defender.h"

BEGIN_GAME

CREATE POKEMON{
    NAME : "Charizard",
    TYPE : "Fire",
    HP : 110
}

CREATE POKEMON{
    NAME : "Blastoise",
    TYPE : "Water",
    HP : 100
}

CREATE POKEMON{
    NAME : "Pikachu",
    TYPE : "Electric",
    HP : 100
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
        IF GET_HP(ATTACKER) > 50 DO
            DAMAGE ATTACKER 20
        END
    END
}

CREATE ABILITY {
NAME: "Electric_shock",
ACTION :  START
        IF OR(AND(GET_HP(ATTACKER) > 50 , GET_TYPE(ATTACKER) == "Electric"),AND(GET_HP(DEFENDER) > 50 , GET_TYPE(ATTACKER) == "Fire")) DO
            DAMAGE DEFENDER 20
        END
    END
}

CREATE ABILITY {
NAME: "Water_fight",
ACTION :  START
        IF GET_TYPE(ATTACKER) == "Water" DO
            DAMAGE DEFENDER 20
        END
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
DAMAGE ATTACKER 20
END
}

CREATE ABILITY {
NAME: "Nothing",
ACTION : START
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
ABILITY_NAME(Electric_shock)
ABILITY_NAME(Nothing)
ABILITY_NAME(Fire)
];
DEAR "Pikachu" LEARN [
ABILITY_NAME(Bite)
ABILITY_NAME(Slash)
ABILITY_NAME(Solar_Power)
ABILITY_NAME(Electric_shock)
ABILITY_NAME(Blaze)
ABILITY_NAME(Nothing)
];

DEAR "Ho Oh" LEARN [
ABILITY_NAME(Bite)
ABILITY_NAME(Solar_Power)
ABILITY_NAME(Blaze)
ABILITY_NAME(Water_fight)
];

DEAR "Bulbasaur" LEARN [
ABILITY_NAME(Bite)
ABILITY_NAME(Solar_Power)
];


DUEL
END_GAME