#include "deck.h"
#include <string>
#include <iostream>

using namespace std;

enum Value {
  TWO = 2,
  THREE,
  FOUR,
  FIVE,
  SIX,
  SEVEN,
  EIGHT,
  NINE,
  TEN,
  JACK,
  QUEEN,
  KING,
  ACE
};

enum Suit {
  SPADES,
  CLUBS,
  DIAMONDS,
  HEARTS
};


class Card {
 
  enum Suit suit;
  enum Value value;


public:

  Card(enum Suit, enum Value) {
    this->suit = suit;
    this->value = value;
  }

  Card() {

  }

  ~Card(void) {

  }

  enum Suit getSuit() {
    return suit;
  }

  enum Value getValue() {
    return value;
  }
};


class Deck {
  Card cards[];

  
};


int main() {
  Card *test = new Card(SPADES, ACE);
  
}