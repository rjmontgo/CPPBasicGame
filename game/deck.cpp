#include "deck.hpp"
#include <string>
#include <vector>
#include <map>

#define DECK_SIZE 52
#define NUM_SUITS 4

using namespace std;

Card::Card(string name, int value, string suit) {
  this->name = name;
  this->value = value;
  this->suit = suit;
}

string Card::toString() {
  return this->name + " of " + this->suit;
}

string Card::getName() {
  return this->name;
}

int Card::getValue() {
  return this->value;
}

string Card::getSuit() {
  return this->suit;
}



Deck::Deck(int numOfDecks) {
  cardMapping = new map<string, int>();
  cards = new vector<Card *>();

  (*cardMapping)["Two"] = 2;
  (*cardMapping)["Three"] = 3;
  (*cardMapping)["Four"] = 4;
  (*cardMapping)["Five"] = 5;
  (*cardMapping)["Six"] = 6;
  (*cardMapping)["Seven"] = 7;
  (*cardMapping)["Eight"] = 8;
  (*cardMapping)["Nine"] = 9;
  (*cardMapping)["Ten"] = 10;
  (*cardMapping)["Jack"] = 10;
  (*cardMapping)["Queen"] = 10;
  (*cardMapping)["King"] = 10;
  (*cardMapping)["Ace"] = 11;

  for (int i = 0; i < numOfDecks; i++)
    // Tried to use auto, but could not resolve issue with compiler not being able to resolve the type.
    for (map<string, int>::iterator iter = cardMapping->begin(); iter != cardMapping->end(); iter++) {
      cards->push_back(new Card(iter->first, iter->second, "Spades"));
      cards->push_back(new Card(iter->first, iter->second, "Clubs"));
      cards->push_back(new Card(iter->first, iter->second, "Diamonds"));
      cards->push_back(new Card(iter->first, iter->second, "Hearts"));        
    }
}

Card *Deck::draw() {
  //Will need to delete card later pop_back is called
  //pop_back will just remove the pointer and not delete the objec
  Card *ret = cards->back();
  cards->pop_back();
  return // NOT DONE HERE ret;
}

/**
    This method is used for debugging purposes only and serves no use in the game.
 */
void Deck::printDeck() {
  
}

void Deck::returnHand(vector<Card *> hand) {

}

void Deck::shuffle() {

}