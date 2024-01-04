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
#define NAME false ? "Smarty"
class Pokeball;
extern int t,i, v;
extern string tempPokemon;
extern Pokeball α;
extern Pokeball _;
extern map<string,map<string,Pokeball>> pokeballMap;
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
#define ABILITY_NAME(name) #name
#define GET_HP(Pokemon) Pokemon.getHealthPoints()
#define GET_TYPE(Pokemon) Pokemon.getPokemonType()
#define GET_NAME(Pokemon) Pokemon.getPokemonName()
#define IS_IN_POKEBALL(Pokemon) Pokemon.isInPokeball()
#define IF if (
#define ELSE }else {
#define AND(...) AndProMax(__VA_ARGS__)
#define OR(...) OrProMax(__VA_ARGS__)
#define NOT !
#define DO ){
#define HEAL ;healValues[allAbilitiesInOrder[t]]
#define DAMAGE ;damageValues[allAbilitiesInOrder[t]]
#define POKEBALL ;pokeballMap[allAbilitiesInOrder[t]]
#define ATTACKER ["attacker"+to_string(i++)] = 
#define DEFENDER ["defender"+to_string(v++)] =
#define ACTION false ? ([]() {})
#define START []() { t++; i = 1; v = 1;
#define FOR ;for(int f=0; f<
#define POKEBALL ;pokeballMap[allAbilitiesInOrder[t]]
#define ROUNDS ; f++
#define END ;/*cout <<"RESULTS for " << allAbilitiesInOrder[t] << endl;\
        for (i=0; i<100; i++) \
        { if (damageValues[allAbilitiesInOrder[t]]["attacker"+to_string(i)]!=0) {cout<<damageValues[allAbilitiesInOrder[t]]["attacker"+to_string(i)]; cout << " ";}} \
        cout<<endl;\
        for (i=0; i<100; i++) \
        { if (damageValues[allAbilitiesInOrder[t]]["defender"+to_string(i)]!=0) {cout<<damageValues[allAbilitiesInOrder[t]]["defender"+to_string(i)]; cout << " ";}} \
        cout<<endl;\
        for (i=0; i<100; i++) \
        { if (healValues[allAbilitiesInOrder[t]]["attacker"+to_string(i)]!=0) {cout<<healValues[allAbilitiesInOrder[t]]["attacker"+to_string(i)]; cout << " ";}} \
        cout<<endl;\
        for (i=0; i<100; i++) \
        { if (healValues[allAbilitiesInOrder[t]]["defender"+to_string(i)]!=0) {cout<<healValues[allAbilitiesInOrder[t]]["defender"+to_string(i)]; cout << " ";}} \
        cout<<endl;*/\
        }


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