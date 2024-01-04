#include "pokeball.h"
Pokeball Pokeball::operator-(){
	return *this;
}
Pokeball Pokeball::operator--(){
	return *this;
}
Pokeball::Pokeball(int value){
	this->value = value;
}
map<string,map<string,Pokeball>> pokeballMap;
Pokeball α;
Pokeball _;