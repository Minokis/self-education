// This simple exercise shows that char contains ASCII codes.
// Sometimes you don't need casting.

#include <iostream>
using namespace std;
int main() {
char character;
cout << "Enter a character! ";
cin >> character;
cout << "Now let's see its ASCII code. It's: " << static_cast<int>(character) << endl;
return 0;
}
