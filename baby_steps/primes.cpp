// A way to find prime numbers
// Try other methods: Eratosphen, Sundaram, Atkin.
#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int n, num = 3;
  bool isUsed = false;
  cout << "How many numbers do you want? ";
  cin >> n;

  if (n >= 1) {
    cout << "First " << n << " numbers are:\n2\n";
    for (int count = 2; count <= n;) {
      for (int search = 2; search <= (int)sqrt(num); search++) {
        if (num % search == 0) {
          isUsed = true;
          break;
        }
      }
      if (!isUsed) {
        cout << num << endl;
        count ++;
      }
      isUsed = false;
      num++;
    }
  }
  else
    cout << "First number is 2, if you wished to know that." << endl;
  return 0;
}
