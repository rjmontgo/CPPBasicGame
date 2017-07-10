#include <iostream>
#include <unistd.h>
#include "interface.h"

using namespace std;

int main()
{

  int action = openingMenu();

  if (action == 1) {
    //New game action
  } else if (action == 2) {
    //Load game action

  } else if (action == 3) {
    cout << endl << "Thanks for playing!" << endl;
    return 0;

  }



  return 0;
}