#include "deck.hpp"
#include "interface.hpp"
#include "player.hpp"
#include <vector>

#define DEFAULT_DECKSIZE 4
#define DEFAULT_CASH_START 20000
#define MINIMUM_CASH 100

using namespace std;

void playGame(Deck *deck, Player *player) {
  vector<Card *> *dealerHand = new vector<Card *>();
  while (playRoundMenu() == 1) {
    if (player->getCash() < MINIMUM_CASH) {
      endGameNoMoney();
      break;
    }

    //Deal-hands
    dealerHand->push_back(deck->draw());
    dealerHand->push_back(deck->draw());

    player->addCardToHand(deck->draw());
    player->addCardToHand(deck->draw());

    // Place bets

    // Dealers turn. (Hit until 17 is reached)

    // Players turn. (let player decide what to do)

    // Reset deck and player hands
  }
  // Delete dealerhand
  // delete player and deck objects
}

void newGame() {
  Deck *deck = new Deck(DEFAULT_DECKSIZE);
  deck->shuffle();
  Player *player = new Player(DEFAULT_CASH_START);

  playGame(deck, player);
}

int main() {
  int choice = openingMenu();

  if (choice == 1) {
    newGame();
  } else if (choice == 2) {
    // load game
  }
}