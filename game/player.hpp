#ifndef PLAYER
#define PLAYER

#include <string>
#include <vector>

class Player {

  std::vector<Card *> *hand;
  int cash;

public:

  Player(int cash);

  std::string handToString();

  void addCardToHand(Card *card);

  int getHandValue();

  std::vector<Card *> *returnHand();

  int getCash();

  void removeCash(int cash);

  void addCash(int cash);

};

#endif