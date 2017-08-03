#include "interface.hpp"
#include "player.hpp"
#include <unistd.h>
#include <iostream>
#include <limits>


using namespace std;

int openingMenu();
int openingOptionChooser();
void displayOpeningOptions();

int openingMenu()
{

  cout << "Black-Jack Player" << endl << endl;
  int choice = openingOptionChooser();

  return choice;
}

int openingOptionChooser()
{
  int choice = -1;

  displayOpeningOptions();
  while (!(cin >> choice) || !( choice == 1 || choice == 2 || choice == 3) ) {
    cout << endl << "You did not enter a valid option." << endl;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    displayOpeningOptions();

  }

  return choice;
}

void displayOpeningOptions()
{
  cout << "What would you like to do?" << endl;
  cout << "1) Start a new game" << endl;
  cout << "2) Continue a previous game" << endl;
  cout << "3) Quit" << endl;
  cout << "Choice: ";

}


int playRoundMenu() {
  int choice = -1;
  cout << "Would you like to play a round?" << endl << "1) Yes" << endl << "2) No" << endl;
  cout << "Choice: ";
  while (!(cin >> choice) || !(choice == 1 || choice == 2)) {
    cout << endl << "You did not enter a valid option." << endl;
    cout << "Would you like to play a round?" << endl << "1) Yes" << endl << "2) No" << endl;
    cout << "Choice: ";
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }

  return choice;
}


void endGameNoMoney() {
  cout << "Not enough money to make minimum bid." << endl << "Quitting game." << endl;
}

int placePlayerBetMenu(int playerMoney) {
  int amount = -1;
  cout << "Enter an amount to bet" << endl << endl << "Must be atleast 100" << endl << endl;
  cout << "You have " << playerMoney << " dollars to bet." << endl << "Amount: ";
  while (!(cin >> amount) || !(amount >= 100 && amount <= playerMoney)) {
    cout << endl << "You did not enter a valid amount." << endl;
    cout << "Enter an amount to bet" << endl << "Must be atleast 100" << endl << endl << "Amount: ";
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }

  return amount;
}

void dealerTurnStart( int value ) {
  cout << endl << "Dealer turn has started." << endl << "Dealer hand value: " << value << flush;
  // Sleeping to slow down time between dealer hits, so player can read it easily.
  sleep(1);
}

void dealerTurnHit( int value ) {
  cout << endl << "Dealer hits." << endl << "Dealer hand value: " << value << flush;
  //Sleeping to slow down time between dealer hits, so player can read it easily.
  sleep(1);
}

void dealerTurnEnd( int value ) {
  if ( value > 21) {
    cout << endl << "Dealer busts." << endl;
    cout << "You win the round!";
  } else {
    cout << endl << "Dealer stands." << endl << "Dealer hand value: " << value << endl;
  }
}

int playerMenu( Player *player ) {
  cout << endl << "Your hand is:" << endl << player->handToString() << endl;
  cout << "What would you like to do?" << endl << "1) Hit" << endl << "2) Stand" << endl;
  cout << "Choice: ";
  int choice = -1;
  while (!(cin >> choice) || !(choice == 1 || choice == 2)) {
    cout << endl << "You did not enter a valid option" << endl;
    cout << "What would you like to do?" << endl << "1) Hit" << endl << "2) Stand" << endl;
    cout << "Choice: ";
  }
  return choice;
}

void playerBust() {
  cout << endl << "You busted!" << endl;
}

void playerWin() {
  cout << endl << "You Won!" << endl;
}

