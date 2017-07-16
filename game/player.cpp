#include "player.hpp"
#include "deck.hpp"
#include <string>
#include <vector>

Player::Player( int cash ) {
  this->cash = cash;
  this->hand = new vector<Card *>();
}

string Player::handToString() {
  string ret = "Hand:\n";
  for(vector<Card *>::iterator iter = hand->begin(); iter != hand->end(); iter++) {
    ret += (*iter)->toString() + "\n";
  }
  return ret;
}

void Player::addCardToHand(Card *card) {
  hand->push_back(card);
}

int Player::getHandValue() {
  bool aceFlag = false;
  int sum = 0;
  for(vector<Card *>::iterator iter = hand->begin(); iter != hand->end(); iter++) {
    if ((*iter)->getValue() == 11)
      aceFlag = true;
    sum += (*iter)->getValue();
  }

  if (sum > 21 && aceFlag)
    sum -= 10; // Subtracting 11 and adding 1

  return sum;
}

vector<Card *> *Player::returnHand() {
  vector<Card *> ret = new vector<Card *>();
  for ( vector<Card *>::iterator iter = hand->begin(); iter != hand->end(); iter++) {
    ret->push_back((*iter));
  }
  hand->erase(hand->begin());

  return ret;
}

int Player::getCash() {
  return cash;
}

void Player::removeCash(int cash) {
  this->cash -= cash;
}

void Player::addCash(int cash) {
  this->cash += cash;
}