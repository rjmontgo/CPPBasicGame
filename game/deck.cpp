#include "deck.h"
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <math.h>

#define DECK_SIZE 52
#define NUM_SUITS 4


using namespace std;

class Card {
  string name;
  string suit;
  int value;

public:
  Card(string name, string suit, int value) {
    this->name = name;
    this->suit = suit;
    this->value = value;
  }

  string getName() {
    return name;
  }

  int getValue() {
    return value;
  }

  string toString() {
    return name + " of " + suit;
  }

};



class Deck {
  map<string, int> cardMapping;
  vector<Card> deck;
  int numCards;

public:
  Deck(int numDecks) {
    cardMapping["Two"] = 2;
    cardMapping["Three"] = 3;
    cardMapping["Four"] = 4;
    cardMapping["Five"] = 5;
    cardMapping["Six"] = 6;
    cardMapping["Seven"] = 7;
    cardMapping["Eight"] = 8;
    cardMapping["Nine"] = 9;
    cardMapping["Ten"] = 10;
    cardMapping["Jack"] = 10;
    cardMapping["Queen"] = 10;
    cardMapping["King"] = 10;
    cardMapping["Ace"] = 11;
    this->numCards = numDecks * DECK_SIZE;
    
    for (int i = 0; i < numDecks; i++) {
      for (map<string, int>::iterator iter = cardMapping.begin(); iter != cardMapping.end(); iter++) {
        deck.push_back(Card(iter->first, "Spades", iter->second));
        deck.push_back(Card(iter->first, "Clubs", iter->second));
        deck.push_back(Card(iter->first, "Diamonds", iter->second));
        deck.push_back(Card(iter->first, "Hearts", iter->second));
      }
    }
  }


  int getValueFromName(string name) {
    return cardMapping[name];
  }

  void printDeck() {
    for (vector<Card>::iterator iter = deck.begin(); iter != deck.end(); iter++) {
      cout << (*iter).toString() + "\n";
    }
  }

  /*
    https://math.stackexchange.com/questions/127492/how-many-2-card-swaps-until-a-card-deck-is-close-to-true-random
  */
  void shuffle() {
    int index1, index2, numSwaps = ceil((0.5) * numCards * log( numCards ));
    srand(time(NULL));
    for (int i = 0; i < numSwaps; i++) {
      index1 = rand() % numCards;
      index2 = rand() % numCards;
      Card hold = deck[index1];
      deck[index1] = deck[index2];
      deck[index2] = hold;
    }
  }
};

int main() {
  Deck deck = Deck(2);
  deck.printDeck();
  deck.shuffle();
  deck.printDeck();
}