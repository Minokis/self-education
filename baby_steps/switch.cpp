// Basic example of switch statement usage.

#include <iostream>
using namespace std;

int main() {
  int choice;
  cout << "Enter an integer from 1 to 4: ";
  cin >> choice;

  switch (choice)
  {
    case 1:
      cout << "I see 1.\n";
      break;
    case 2:
      cout << "I see 2.\n";
      break;
    case 3:
      cout << "I see 3.\n";
      break;
    case 4:
      cout << "I see 4.\n";
      break;
    default:
      cout << "Hey, I asked you to enter 1 - 4!\n";
  }
  return 0;
}
