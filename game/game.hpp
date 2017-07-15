#ifndef GAME
#define GAME 1
#include "deck.hpp"
#include "player.hpp"
void initiateGame();
void loadGame(/** String path to file */);
void playGame(Deck deck, Player player);
#endif