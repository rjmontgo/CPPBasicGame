#include "deck.h"
#include <string>
#include <iostream>
#include <vector>

#define DECK_SIZE 52
#define NUM_SUITS 4

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

  Card(Suit suit, Value value) {
    this->suit = suit;
    this->value = value;
  }

  enum Suit getSuit() {
    return suit;
  }

  enum Value getValue() {
    return value;
  }
};


class Deck {
  vector<Card> deck;
  int size;

  Deck(int numDecks) {
    size = numDecks * DECK_SIZE;
    deck.resize(DECK_SIZE * numDecks);

    for (int i = 0; i < numDecks; i++) {
      for (int j = 2; j <= ACE; j++) {
        for (int k = 0; k < NUM_SUITS; k++) {
          //deck.push_back(Card(k, j)); CAN'T CONVERT FROM INT TO SUIT
        }
      }
    }
  }

  
};


int main() {
  Card *test = new Card(SPADES, KING);

  if (test->getValue() == 14) {
    cout << "Successful"; 
  }
}