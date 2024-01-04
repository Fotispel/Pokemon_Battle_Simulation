#include "poke_important.h"
#include "pokemon.h"
#include "pokemon_abilities.h"
#include "pokeball.h"

#define DUEL\
        int round = 1;\
        string pokemon1, pokemon2, ability;\
        cout << "--------------------------------POKEMON THE GAME--------------------------------" << endl;\
        cout << "Player 1 select pokemon: " << endl;\
        cout << "------------------------------------------" << endl;\
        print_AllPokemons();\
        cout << "------------------------------------------" << endl;\
        do {\
            getline(cin, pokemon1);\
        } while (!check_if_pokemon_exists(pokemon1));\
        cout << endl;\
        cout << "Player 2 select pokemon: " << endl;\
        cout << "------------------------------------------" << endl;\
        do {\
            getline(cin, pokemon2);\
        } while (!check_if_pokemon_exists(pokemon2));\
        Pokemon player[2];\
        player[0] = Pokemon(allPokemons[pokemon1]);\
        player[1] = Pokemon(allPokemons[pokemon2]);\
        while (player[0].getHealthPoints() > 0 && player[1].getHealthPoints() > 0) {\
            int isAttacking = find_WhoIsAttacker(round);\
            int isDefending = isAttacking == 0 ? 1 : 0;\
            cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;\
            cout << "Round " << round << endl;\
            cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;\
            cout << player[0].getPokemonName() << "(Player" << isAttacking + 1 <<") select ability: " << endl;\
            cout << "------------------------------------------" << endl;\
            print_AllAbilities();\
            cout << "------------------------------------------" << endl;\
            do {\
                getline(cin, ability);\
            } while (!check_if_ability_exists(ability));\
            do_ability_actions(player[isAttacking], player[isDefending], ability);\
            cout << endl << "#############################" << endl;\
            print_pokemon_info(player[0]);\
            cout << "#############################" << endl;\
            cout << endl << endl << endl;\
            cout << "#############################" << endl;\
            print_pokemon_info(player[1]);\
            cout << "#############################" << endl << endl << endl;\
            round++;\
        }\
        cout << endl << "------------------------------------------" << endl;\
        cout << "Result:" << endl;\
        find_Winner(player[0], player[1]);


void do_ability_actions(Pokemon &attacker, Pokemon &defender, string ability) {
    int i;
    for (i = 0; i<100 ; i++) {
        if (damageValues[ability]["attacker" + to_string(i)] != 0) {
            attacker.DamageAttacker(damageValues[ability]["attacker" + to_string(i)]);
        }
    }
    for (i = 0; i<100 ; i++) {
        if (damageValues[ability]["defender" + to_string(i)] != 0) {
            defender.DamageAttacker(damageValues[ability]["defender" + to_string(i)]);
        }
        if (healValues[ability]["attacker" + to_string(i)] != 0) {
            attacker.HealAttacker(healValues[ability]["attacker" + to_string(i)]);
        }
        if (healValues[ability]["defender" + to_string(i)] != 0) {
            defender.HealAttacker(healValues[ability]["defender" + to_string(i)]);
        }
    }

    for (i = 0; i<100 ; i++) {
        if (pokeballMap[ability]["attacker" + to_string(i)].getName() == "_") {
            attacker.putInPokeball();
        }
        if (pokeballMap[ability]["defender" + to_string(i)].getName() == "_") {
            defender.putInPokeball();
        }
        if (pokeballMap[ability]["attacker" + to_string(i)].getName() == "α") {
            attacker.putInPokeball();
        }
        if (pokeballMap[ability]["defender" + to_string(i)].getName() == "α") {
            defender.putInPokeball();
        }
    }
}



int find_WhoIsAttacker(int round) {
    if (round % 2 == 1) {
        return 0;
    }
    else {
        return 1;
    }
}

void print_AllPokemons() {
    for (const auto &pokemon : allPokemons) {
        cout << pokemon.second.getPokemonName() << endl;
    }
}

void print_AllAbilities() {
    for (const auto &ability : allAbilitiesInOrder) {
        cout << ability << endl;
    }
}

void print_pokemon_info(Pokemon pokemon) {
    cout << "Name: " << pokemon.getPokemonName() << endl\
        << "Type: " << pokemon.getPokemonType() << endl\
        << "HP: " << pokemon.getHealthPoints() << endl;
}

bool check_if_pokemon_exists(string pokemon) {
    if (allPokemons.find(pokemon) == allPokemons.end()) {
        cout << "Pokemon does not exist. Try again." << endl;
        return false;
    }
    else {
        return true;
    }
}

bool check_if_ability_exists(string ability) {
    if (allAbilities.find(ability) == allAbilities.end()) {
        cout << "Ability does not exist. Try again." << endl;
        return false;
    }
    else {
        return true;
    }
}

void find_Winner(Pokemon player1, Pokemon player2) {
    if (player1.getHealthPoints() > player2.getHealthPoints()) {
        cout << player1.getPokemonName() << "(Player1) wins!" << endl;
    }
    else if (player1.getHealthPoints() < player2.getHealthPoints()) {
        cout << player2.getPokemonName() << "(Player2) wins!" << endl;
    }
    else {
        cout << "Draw!" << endl;
    }
}