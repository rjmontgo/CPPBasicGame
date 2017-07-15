#ifndef DECK
#define DECK

#include <string>
#include <vector>
#include <map>

/**


 */
class Card {

  std::string name;
  int value;
  std::string suit;

public:
  Card(std::string name, int value, std::string suit);

  std::string toString();

  std::string getName();

  int getValue();

  std::string getSuit();
};




/**


 */
class Deck {

  std::vector<Card *> *cards;
  std::map<std::string, int> *cardMapping;
public:
  Deck(int numOfDecks);

  Card *draw();

  std::string printDeck();

  void returnHand(std::vector<Card *> hand);

  void shuffle();
};


#endif