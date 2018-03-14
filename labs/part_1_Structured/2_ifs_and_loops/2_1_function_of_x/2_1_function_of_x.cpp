#include <iostream>

using namespace std;
int main() {
  setlocale(LC_ALL, "Russian");
  float x, y;
  cout << "Введите значение аргумента x: ";
  cin >> x;
  if (x < -2)                 y = 0;
  else if (x >= -2 && x < -1) y = -x-2;
  else if (x >= -1 && x < 1)  y = x;
  else if (x >= -1 && x < 2)  y = -x+2;
  else                        y = 0;
  cout << "Для значения x = " << x << " y = " << y << endl;
  return 0;
}
