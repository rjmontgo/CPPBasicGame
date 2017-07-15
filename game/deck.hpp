#include <map>
#include <string>
#include <vector>

#ifndef CARD
#define CARD 1
class Card {
  std::string name;
  std::string suit;
  int value;

public:
  Card(std::string name, std::string suit, int value);

  std::string getName();
  
  int getValue();
  
  std::string toString();

};

class Deck {
  std::map<std::string, int> cardMapping;
  std::vector<Card> deck;
  int numCards;

public:
  Deck(int numDecks);

  int getValueFromName(std::string name);

  void printDeck();

  void shuffle();

  Card draw();

  void returnHand(std::vector<Card> vect);
};

#endif