#ifndef INTERFACE
#define INTERFACE
int openingMenu();

int playRoundMenu();

void endGameNoMoney();

int placePlayerBetMenu( int playerMoney );

void dealerTurnStart( int value );

void dealerTurnHit( int value );

void dealerTurnEnd( int value );
#endif