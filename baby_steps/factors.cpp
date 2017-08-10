// Finding factors of the number

#include <iostream>
using namespace std;

int main() {
    unsigned int num;
    cout << "Enter a natural number: ";
    cin >> num;
    cout << "Factors of this number are: ";
    for (int i = 1; i < num; i++) {
      if(num % i == 0)
        cout << i << ", ";
    }
    cout << num << "." << endl;
    return 0;
}
