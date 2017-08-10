// Guess a number from 0 to 9.
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
  int magic;
  int guess;
  srand((unsigned)time(NULL));
  magic = rand()%10;
  cout << "I came up with a magic number from 0 to 9. Guess it! If you want to leave, enter a number < 0. ";
  cin >> guess;

  while (guess != magic) {
    if (guess < 0) {
      cout << "Too bad. :( \nBye!\n";
      return 0;
    }
    if (guess > magic)
      cout << "Too big! Try again: ";
    else
      cout << "Too small! Try again: ";
    cin >> guess;
  }
  cout << "Finally! You're right! Bye for now. :)\n";
  return 0;
}
