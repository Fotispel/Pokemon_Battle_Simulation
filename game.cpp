#include "pokemon.h"
#include "pokemon_abilities.h"
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
    NAME: "Bite",
    ACTION: START
    END
    },
    ABILITY{
    NAME: "Solar_Power",
    ACTION: START
    END
    },
    ABILITY{
    NAME: "Extra Attack",
    ACTION: START
    END
    }
]
;

CREATE ABILITY {
NAME: "Slash",
ACTION: START
    DAMAGE ATTACKER 22
    DAMAGE ATTACKER 25
    DAMAGE DEFENDER 23
    POKEBALL ATTACKER ---α
    HEAL DEFENDER 24
    HEAL DEFENDER 25

END
}

;for (const auto &ability : allAbilitiesInOrder) {
    cout << ability << endl;
}
    
;for (const auto &pokemon : allPokemons) {
    cout << "Name: " << pokemon.second.getPokemonName() << ", Type: " << pokemon.second.getPokemonType() << ", HP: " << pokemon.second.getHealthPoints() << endl << endl;
}

Pokemon player1 = Pokemon(allPokemons["Charizard"]);
Pokemon player2 = Pokemon(allPokemons["Pikachu"]);

Pokemon attacker = player1;
Pokemon defender = player2;

GET_TYPE(attacker);
GET_NAME(attacker);
IS_IN_POKEBALL(attacker);

if (AND(GET_NAME(attacker) == "Charizard", GET_TYPE(attacker) == "Fire")) {
    cout << "Attacker is Charizard" << endl;
}



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
];
END_GAME