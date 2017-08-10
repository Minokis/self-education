// Check if a number is an Armstrong number
#include <iostream>
#include <math.h>
using namespace std;

int count_digits(int n) {
  int digits = 0;
  do {
    n /= 10;
    digits++;
  } while (n != 0);
  cout << digits << " digits." << endl;
  return digits;
}

int calc_sum(int n) {
  int digits = count_digits(n);
  int digit, sum = 0;
  for (int i = 1; i <= digits; i++) {
    digit = n % 10;
    sum += pow(digit, digits);
    n /= 10;
  }
  return sum;
}

int main() {
  unsigned int n;
  cout << "Enter a positive integer: ";
  cin >> n;
  int sum = calc_sum(n);
  if (sum == n)
    cout << "This is an Armstrong number." << endl;
  else
    cout << "This is not an Armstrong number." << endl;
  return 0;
}
