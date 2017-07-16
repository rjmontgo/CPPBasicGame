CC=g++
CFLAGS=-g -std=c++11 -Wall -pedantic

game: game.o deck.o player.o interface.o
game.o: deck.hpp player.hpp interface.hpp
deck.o: player.hpp
player.o: deck.hpp

