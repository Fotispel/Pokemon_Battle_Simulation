build:
	g++ -std=c++11 -Wall pokemon.cpp pokemon_abilities.cpp pokeball.cpp game.cpp -o pokebattle
prepross:
	g++ -std=c++11 -Wall -E pokemon.cpp pokemon_abilities.cpp pokeball.cpp game.cpp -o pokebattle
clear:
	rm *.exe
nowarnings:
	g++ -std=c++11 pokemon.cpp pokemon_abilities.cpp pokeball.cpp game.cpp -o pokebattle