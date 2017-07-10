#include "interface.h"
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