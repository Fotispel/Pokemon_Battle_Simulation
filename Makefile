build:
	g++ -std=c++11 -Wall -Werror game.cpp -o pokebattle
prepross:
	g++ -std=c++11 -Wall -E -Werror game.cpp -o pokebattle
clear:
	rm *.exe