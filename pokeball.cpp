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
string Pokeball::getName(){
	return this->value;
}
map<string,map<string,Pokeball>> pokeballMap;
Pokeball α("α");
Pokeball _("_");