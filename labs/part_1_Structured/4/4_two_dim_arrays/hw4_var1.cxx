#include <iostream>

using namespace std;

int main () {
  int i, j;
	const int nrow = 10;
	const int ncol = 3;
	int arr[nrow][ncol] ={ {0, 1, 1}, \
												 {2, 1, 2}, \
												 {3, 1, 3}, \
												 {4, 1, 0}, \
												 {4, 1, 5}, \
												 {4, 2, 5}, \
												 {4, 3, 5}, \
												 {5, 4, 6}, \
												 {6, 5, 7}, \
												 {0, 6, 8} };

	// control output
	for (i = 0; i < nrow; i++) {
	  for(j = 0; j < ncol; j++)
	    cout << arr[i][j] << '\t';
	  cout << '\n';
	}

	int seq_in_col;
	int seqs[ncol];

	for(j = 0; j < ncol; j++) {
		seq_in_col = 1;
		for (i = 1; i < nrow; i++) {
			if (arr[i - 1][j] == arr[i][j]) {
				seq_in_col +=1;
			}
		}
		if(1 != seq_in_col) seqs[j] = seq_in_col;
	}

	// control output of sequences
  cout << "Sequences: \n";
	for(j = 0; j < ncol; j++)
		cout << seqs[j] << ' ';
  cout << endl;

	int max_seq_index = 0;
	for(j = 0; j < ncol; j++) {
		if (seqs[j] > seqs[max_seq_index]) max_seq_index = j;

	cout << "The longest sequence is " << seqs[max_seq_index] << ", column " \
				 << max_seq_index + 1 << endl;

	return 0;

}
