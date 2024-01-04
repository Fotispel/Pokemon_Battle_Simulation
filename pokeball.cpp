#include "pokeball.h"
Pokeball Pokeball::operator-(){
	return *this;
}
Pokeball Pokeball::operator--(){
	return *this;
}
Pokeball::Pokeball(string value){
	this->value = value;
}
Pokeball α;
Pokeball _;
map<string,map<string,Pokeball>> pokeballMap;