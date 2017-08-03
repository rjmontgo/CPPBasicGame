#ifndef INTERFACE
#define INTERFACE
#include "player.hpp"

int openingMenu();

int playRoundMenu();

void endGameNoMoney();

int placePlayerBetMenu( int playerMoney );

void dealerTurnStart( int value );

void dealerTurnHit( int value );

void dealerTurnEnd( int value );

int playerMenu(Player *player);

void playerBust();

void playerWin();

#endif