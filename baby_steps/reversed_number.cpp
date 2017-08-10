// A quick way to reverse a number

#include <iostream>
using namespace std;
int main() {
  int n, reversedNumber = 0, remainder;
  cout << "Enter an integer: ";
  cin >> n;
  while (n != 0) {
    remainder = n%10;
    reversedNumber = reversedNumber*10 + remainder;
    n /= 10;
  }
  cout << "Reversed number is " << reversedNumber << endl;
  return 0;
}
