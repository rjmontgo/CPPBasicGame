#include "deck.hpp"
#include <vector>
#include <string>

#ifndef PLAYER
#define PLAYER 1
class Player {
  std::vector<Card> hand;
  int cash;

public:
  Player(int cash);

  void drawCard(Card card);

  std::vector<Card> returnPlayerHand();

  std::string stringHand();

};
#endif
