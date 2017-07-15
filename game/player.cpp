#include "player.hpp"
#include <string>

using namespace std;

Player::Player(int cash) {
  this->cash = cash;
  hand = vector<Card>();
}

void Player::drawCard(Card card) {
  hand.push_back(card);
}

vector<Card> Player::returnPlayerHand() {
  vector<Card> ret = vector<Card>();
  for (vector<Card>::iterator iter = hand.end(); iter != hand.begin(); iter--) {
    ret.push_back(*iter);
    hand.pop_back();
  }
  return ret;
}

string Player::stringHand() {
  string cards = "";
  for (vector<Card>::iterator iter = hand.begin(); iter != hand.end(); iter++) {
    cards += iter->toString() + "\n";
  }
  return cards;
}