#include "interface.hpp"
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