CC= g++
CFLAGS= -Wall -std=c++11

main: main.o interface.o game.o deck.o player.o
main.o: main.cpp main.hpp interface.hpp
interface.o: interface.cpp interface.hpp
game.o: game.hpp deck.hpp player.hpp
player.o: player.hpp deck.hpp
deck.o: deck.hpp

