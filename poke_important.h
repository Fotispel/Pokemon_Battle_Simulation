//για κοινόχρηστα define & include
#ifndef POKE_IMPORTANT
#define POKE_IMPORTANT
#include <iostream>
#include <fstream>
#include <string>
#include <typeinfo>
#include <sstream>
#include <vector>
#include <map>
#include <functional>
#include<bits/stdc++.h>
using namespace std;
#define CREATE ;
class Pokeball;
extern int t,i, v;
extern string tempPokemon;
extern Pokeball α;
extern char _;
extern map<string,map<int,string>> pokeballMapAttacker;
extern map<string,map<int,string>> pokeballMapDefender;
#define BEGIN_GAME \
    int main(){\
	Ability dummyAbility; Ability dummyAbility2; \

#define END_GAME \
    ;            \
    return 0;    \
    }
#define ABILITY Ability
#define ABILITIES Ability abil; Ability abi = abil
#define POKEMON Pokemon
#define POKEMONS Pokemon pk; Pokemon pok = pk
#define HP false ? -22
#define TYPE NAME
#define POKEMON_NAME(name) +string(#name)+"@"
#define DEAR ; tempPokemon=
#define LEARN ; dummyAbility=dummyAbility2
#define ABILITY_NAME(name) +string(#name)+"@"
#define GET_HP(Pokemon) Pokemon.getHealthPoints()
#define GET_TYPE(temp) temp.getPokemonType()
#define GET_NAME(Pokemon) Pokemon.getPokemonName()
#define IS_IN_POKEBALL(Pokemon) Pokemon.isInPokeball()
#define IF if (
#define ELSE_IF }else if (
#define ELSE }else {
#define AND(...) AndProMax(__VA_ARGS__)
#define OR(...) OrProMax(__VA_ARGS__)
#define NOT !
#define DO ){
#define HEAL ;heal=true; damage=false;
#define DAMAGE ;damage=true; heal=false;
#define NAME name_ability = false ? "lathos" 
#define ATTACKER attacker,
#define DEFENDER defender,
#define ACTION false ? ([]() {})
#define START Ability_with_actions[name_ability] = []() { t++; i = 1; v = 1; name_ability = allAbilitiesInOrder[allAbilitiesInOrder.size()-1];
#define FOR ;for(int f=0; f<
#define POKEBALL ;
#define ROUNDS ; f++
#define END ;}


template <typename T>
T AndProMax(T arg1, T arg2){
	return arg1 && arg2;
}
template<typename T, typename... Args>
T AndProMax(T arg1, T arg2, Args... args){
	return arg1 && AndProMax(args...);
}
template <typename T>
T OrProMax(T arg1, T arg2){
	return arg1 || arg2;
}
template<typename T, typename... Args>
T OrProMax(T arg1, T arg2, Args... args){
	return arg1 || AndProMax(args...);
}


#endif