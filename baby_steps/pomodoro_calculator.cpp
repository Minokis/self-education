// Calculation of gross time worked
#include <iostream>
using namespace std;

int main() {
  int hours, minutes;
  cout << "Enter hours and minutes: " << endl;
  cin >> hours >> minutes;
  int net_time = hours * 60 + minutes;
  int bulk_halves = net_time / 25;
  int residual = net_time%25;

  cout << "You worked for " << static_cast<float>(bulk_halves)/2;
  if (residual !=0)
    cout << " plus " << residual << endl;
  return 0;
}
