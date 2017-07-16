#include "deck.hpp"
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <cstdlib>
#include <math.h>

#define DECK_SIZE 52
#define NUM_SUITS 4

using namespace std;

Card::Card(string name, int value, string suit) {
  this->name = name;
  this->value = value;
  this->suit = suit;
}

string Card::toString() {
  string test = "";
  test += this->name;
  test += " of ";
  test += this->suit;
  return test;
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
  numCards = numOfDecks * DECK_SIZE;

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
  return ret;
}

/**
    This method is used for debugging purposes only and serves no use in the game.
 */
string Deck::printDeck() {
  string ret = "";
  for (vector<Card *>::iterator iter = cards->begin(); iter != cards->end(); iter++) {
    ret += (*iter)->toString() + "\n";
  }
  return ret;
}

void Deck::returnHand(vector<Card *> *hand) {
  for (vector<Card *>::iterator iter = hand->begin(); iter != hand->end(); iter++) {
    cards->push_back((*iter));
  }
  hand->erase(hand->begin());
  delete hand;
}

/**
    https://math.stackexchange.com/questions/127492/how-many-2-card-swaps-until-a-card-deck-is-close-to-true-random
 */
void Deck::shuffle() {
  int index1, index2, numSwaps = ceil((0.5) * numCards * log( numCards ));
  srand(time(NULL));
  for (int i = 0; i < numSwaps; i++) {
    index1 = rand() % numCards;
    index2 = rand() % numCards;
    Card *hold = (*cards)[index1];
    (*cards)[index1] = (*cards)[index2];
    (*cards)[index2] = hold;
  }
}