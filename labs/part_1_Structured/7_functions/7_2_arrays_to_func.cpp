// 2 arrays with n int numbers.
// Which one has more positive elements?

#include <iostream>
#include <fstream>

using namespace std;

int n_posit(const int *arr, const int n);

int main(int argc, char *argv[]) {
  if (argc < 2) { cout << "Usage: enter a filename with 2 arrays.\n"; return 1;}
  ifstream fin(argv[1]);
  if (!fin) { cout << "Couldn't open the file. :(\n"; return 1;}
  int i, n;
  fin >> n;
  int *a = new int[n];
  int *b = new int[n];
  for (i = 0; i<n; i++) {
    fin >> a[i];
  }
  for (i = 0; i<n; i++) {
    fin >> b[i];
  }
  // cout << "\nControl output:\n";
  // for (i = 0; i<n; i++) {
  //   cout << a[i] << ' ';
  // }
  // cout << endl;
  // for (i = 0; i<n; i++) {
  //   cout << b[i] << ' ';
  // }
  // cout << endl;
  int n_pos_a = n_posit(a,n);
  int n_pos_b = n_posit(b,n);

  n_pos_a > n_pos_b ? cout << "First array has more positive elements.\n" : \
    n_pos_a < n_pos_b ? cout << "Second array has more positive elements.\n" : \
    cout << "Arrays have the same number of positive elements.\n";

  return 0;

}

int n_posit(const int *arr, const int n) {
  int n_pos = 0;
  for (int i = 0; i < n; i++) if(arr[i] > 0) n_pos++;
  return n_pos;
}
