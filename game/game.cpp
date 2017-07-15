#include "game.hpp"
#include "player.hpp"
#include "deck.hpp"
#include "interface.hpp"
#include <iostream>

#define START_MONEY 20000
#define START_DECK_COUNT 4

void initiateGame();
void loadGame();
void playGame(Deck deck, Player player);

void initiateGame() {
  Deck deck = Deck(START_DECK_COUNT);
  deck.shuffle();
  Player player = Player(START_MONEY);

  playGame(deck, player);

}

void loadGame(/** String path to file */) {

}

void playGame(Deck deck, Player player) {
  int choice = playRoundMenu();
  // Check if there is enough money to play
  while (choice == 1) {
    player.drawCard(deck.draw());
    player.drawCard(deck.draw());

    // Bet menu, must bet atleast 100 bucks.
    // Print out the players hand and options to play and bet
    int option = 0; // Put the returned option here
    while (option) {
      if (option == 1) {

      } else if (option == 2) {

      } else if (option == 3) {

      }
    }

    // Process hand to see if the player has blackjack and reward accordingly

  }
}