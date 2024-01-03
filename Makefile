build:
	g++ -std=c++11 -Wall game.cpp -o pokebattle
prepross:
	g++ -std=c++11 -Wall -E game.cpp -o pokebattle
clear:
	rm *.exe
nowarnings:
	g++ -std=c++11 game.cpp -o pokebattle