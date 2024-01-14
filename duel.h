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
            if (player[0].isInPokeball() && player[1].isInPokeball()) {\
                break;\
            }\
            isAttacking = 0;\
            isDefending = 1;\
            Attacker_duel = player[isAttacking];\
            Defender_duel = player[isDefending];\
            for (int i = 0; i < int(round_for.size()); i++) {\
                if (round <= round_for[i] && for_actions[i]["player1"]) {\
                    for_actions[i]["player1"]();\
                }\
            }\
            cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;\
            cout << "Round " << round << endl;\
            cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;\
            if (!player[isAttacking].isInPokeball()) {\
                cout << player[0].getPokemonName() << "(Player" << isAttacking + 1 <<") select ability: " << endl;\
                cout << "------------------------------------------" << endl;\
                print_PokemonAbilities(player[isAttacking].getPokemonName());\
                cout << "------------------------------------------" << endl;\
                do {\
                    getline(cin, ability);\
                } while (!check_if_ability_exists(ability));\
                do_ability_actions(ability);\
                player[isAttacking] = Attacker_duel;\
                player[isDefending] = Defender_duel;\
                cout << endl << "#############################" << endl;\
                print_pokemon_info(player[0]);\
                cout << "#############################" << endl;\
                cout << endl << endl << endl;\
                cout << "#############################" << endl;\
                print_pokemon_info(player[1]);\
                cout << "#############################" << endl << endl << endl;\
            }\
            else {\
                cout << player[isAttacking].getPokemonName() << "(Player" << isAttacking + 1 << ") has not a pokemon out of pokeball so he can't cast an ability." << endl;\
            }\
            \
            isAttacking = 1;\
            isDefending = 0;\
            Attacker_duel = player[isAttacking];\
            Defender_duel = player[isDefending];\
            if (player[isAttacking].isInPokeball() && player[isDefending].isInPokeball()) {\
                break;\
            }\
            for (int r = 0; r < int(round_for.size()); r++) {\
                printf ("round = %d, round_for[%d] = %d\n", round, r, round_for[r]);\
                if (round <= round_for[r] && for_actions[r]["player2"]) {\
                    for_actions[r]["player2"]();\
                }\
            }\
            if (!player[isAttacking].isInPokeball()) {\
                cout << player[0].getPokemonName() << "(Player" << isAttacking + 1 <<") select ability: " << endl;\
                cout << "------------------------------------------" << endl;\
                print_PokemonAbilities(player[isAttacking].getPokemonName());\
                cout << "------------------------------------------" << endl;\
                do {\
                    getline(cin, ability);\
                } while (!check_if_ability_exists(ability));\
                do_ability_actions(ability);\
                player[isAttacking] = Attacker_duel;\
                player[isDefending] = Defender_duel;\
                cout << endl << "#############################" << endl;\
                print_pokemon_info(player[0]);\
                cout << "#############################" << endl;\
                cout << endl << endl << endl;\
                cout << "#############################" << endl;\
                print_pokemon_info(player[1]);\
                cout << "#############################" << endl << endl << endl;\
            }\
            else {\
                cout << player[isAttacking].getPokemonName() << "(Player" << isAttacking + 1 << ") has not a pokemon out of pokeball so he can't cast an ability." << endl;\
            }\
            \
            round++;\
        }\
        cout << endl << "------------------------------------------" << endl;\
        cout << "Result:" << endl;\
        find_Winner(player[0], player[1]);


void do_ability_actions(string abilityName) {
    Ability_with_actions[abilityName]();
}


void print_PokemonAbilities(string pokemon_name) {
    for (const auto &ability : allPokemons[pokemon_name].pokeAbilities) {
        if (ability.first != "\0")
            cout << ability.first << endl;
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

int find_WhoIsDefender(int round) {
    if (round % 2 == 1) {
        return 1;
    }
    else {
        return 0;
    }
}

void print_AllPokemons() {
    for (const auto &pokemon : allPokemons) {
        cout << pokemon.second.getPokemonName() << endl;
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
    if (allPokemons[Attacker_duel.getPokemonName()].pokeAbilities.find(ability) == allPokemons[Attacker_duel.getPokemonName()].pokeAbilities.end()) {
        cout << "Ability does not exist. Try again." << endl;
        return false;
    }
    else {
        return true;
    }
}

void find_Winner(Pokemon player1, Pokemon player2) {
    if (player2.getHealthPoints() <= 0) {
        cout << player1.getPokemonName() << "(Player1) wins!" << endl;
    }
    else if (player1.getHealthPoints() <= 0) {
        cout << player2.getPokemonName() << "(Player2) wins!" << endl;
    }
    else {
        cout << "Draw!" << endl;
    }
}