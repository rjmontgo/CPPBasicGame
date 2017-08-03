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
    int betsize = placePlayerBetMenu(player->getCash());
    player->removeCash( betsize );

    // Dealers turn. (Hit until 17 is reached)
    dealerTurnStart(deck->getHandValue(dealerHand));
    int val;
    while ( deck->getHandValue(dealerHand) < 17 ) {
      dealerHand->push_back(deck->draw());
      dealerTurnHit(deck->getHandValue(dealerHand));
    }

    int dealerHandVal = deck->getHandValue(dealerHand);
    dealerTurnEnd(dealerHandVal);

    if (dealerHandVal > 21) {
      playerWin();
      player->addCash(betsize * 2);
      deck->returnHand(dealerHand);
      deck->returnHand(player->returnHand());
      continue;
    }

    // Players turn. (let player decide what to do)
    while (player->getHandValue() <= 21 && playerMenu(player) != 2) {
      player->addCardToHand(deck->draw());
    }

    if (player->getHandValue() > 21) {
      playerBust();
    } else if (player->getHandValue() > dealerHandVal) {
      playerWin();
      player->addCash( betsize * 2);
    }

    // Reset deck and player hands
    deck->returnHand(dealerHand);
    deck->returnHand(player->returnHand());

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
  }
}