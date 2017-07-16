#ifndef PLAYER
#define PLAYER


class Player {

  vector<Card *> *hand;
  int cash;

public:

  Player();

  string handToString();

};

#endif