#include <string>
#include <vector>
#include <map>

/**


 */
class Card {

  string name;
  int value;
  string suit;

public:
  Card(string name, int value, string suit);

  string toString();

  string getName();

  int getValue();

  string getSuit();
}




/**


 */
class Deck {

  vector<Card *> *cards;
  map<string, int> *cardMapping;
public:
  Deck(int numOfDecks);

  Card *draw();

  string printDeck();

  void returnHand(vector<Card *> hand);
}