// Demonstrating casting
#include <iostream>
#include <cmath>
using namespace std;

int main() {
  for(int i = 0; i < 10; i++) {
    cout << sqrt((double)i) << "\t";
  }
  cout << endl;
  for (int j = 0; j < 10; j++) {
    cout << sqrt(static_cast<double>(j)) << "\t";
  }
  return 0;
}
