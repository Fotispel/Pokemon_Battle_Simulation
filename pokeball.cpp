#include "pokeball.h"
char _;
Pokeball Pokeball::operator-(){
	return *this;
}
Pokeball Pokeball::operator--(){
	return *this;
}
Pokeball::Pokeball(string value){
	this->value = value;
}
string Pokeball::getName(){
	return this->value;
}
map<string,map<int,string>> pokeballMapAttacker;
map<string,map<int,string>> pokeballMapDefender;
Pokeball α("α");