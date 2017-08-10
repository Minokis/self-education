// Very basic calculator
#include <iostream>
using namespace std;

int main() {
  int num1, num2;
  char op;
  cout << "Enter two numbers: " << endl;
  cin >> num1 >> num2;
  cout << "Enter operator: " << endl;
  cin >> op;
  cout << num1 << " " << op << " " << num2 << " = ";

  switch(op) {
    case '+':
      cout << num1 + num2 << endl;
      break;
    case '-':
      cout << num1 - num2 << endl;
      break;
    case '*':
      cout << num1 * num2 << endl;
      break;
    case '/':
      cout << num1 / num2 << endl;
      break;
    case '%':
      cout << num1 % num2 << endl;
      break;
    default:
      cout << "Invalid output. :(" << endl;
  }
  return 0;
}
