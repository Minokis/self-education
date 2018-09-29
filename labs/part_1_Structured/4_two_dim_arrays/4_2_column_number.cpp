#include <iostream>
#include <fstream>
#include <iomanip>  // for setw()

using namespace std;

int main(int argc, char *argv[]) {
  if(argc != 2) { cout << "Usage: enter a filename with the matrix.\n"; return 1; }
  ifstream input(argv[1]);
  if(!input) { cout << "Cannot open input file.\n"; return 1; }

  int nrow, ncol;
  input >> nrow >> ncol;
  int i, j; // counters for loops

  // Control output
  cout << "nrow = " << nrow << endl;
  cout << "ncol = " << ncol << endl;
  // end

  int ** arr = new int* [nrow];
  for (i=0; i < nrow; i++)    arr[i] = new int[ncol];
  for (i=0; i < nrow; i++)
      for (j = 0; j < ncol; j++)
        input >> arr[i][j];

  // Control output
  cout << "Array: \n";
	for (i = 0; i < nrow; i++) {
		for (j = 0; j < ncol; j++)	cout << setw(4) << arr[i][j] << ' ';
		cout << endl;
	}
  //end

  //int num = -1; // indicator of the column
  bool all_posit; // indicator of the condition

  for(j = 0; j < ncol; j++) {
    all_posit = true;
    for (i = 0; i < nrow; i++)
      if (arr[i][j] <= 0) {
        all_posit = false;
        break;
      }
    if(all_posit) {
      //num = j; break;
      cout << "The column with all positive numbers is " << j+1 << endl;
      return 0;
    }
  }
  //
  // if(-1 == num) {
  //   cout << "No columns with all positive numbers.\n";
  // }
  // else {
  //   cout << "The column with all positive numbers is " << j << endl;
  // }
  cout << "No columns with all positive numbers.\n";
  return 0;
}
