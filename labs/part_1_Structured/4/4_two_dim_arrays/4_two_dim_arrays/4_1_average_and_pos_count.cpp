// Create 10x20 matrix
// Calculate average of all the elements
// count positive elements in every row
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <iomanip>  // for setw()

using namespace std;

int main(int argc, char *argv[]) {
	if (argc != 2) { cout << "Usage: enter a filename with numbers.\n"; return 1; }
	ifstream input(argv[1]);
	if (!input) { std::cout << "Cannot open input file.\n"; return 1; }

	int nrow, ncol;
	int i, j;   // counters
	input >> nrow >> ncol;
	cout << "nrow = " << nrow << endl;
	cout << "ncol = " << ncol << endl;
	int ** arr = new int* [nrow];
	for (i = 0; i < nrow; i++) {
		arr[i] = new int[ncol];
	}

	for (i = 0; i < nrow; i++)
		for (j = 0; j < ncol; j++)
			input >> *(arr[i] + j);

	cout << "Array: \n";
	for (i = 0; i < nrow; i++) {
		for (j = 0; j < ncol; j++)	cout << setw(4) << arr[i][j] << ' ';
		cout << endl;
	}

	double sum = 0;
	int n_pos_el;

	for (i = 0; i < nrow; i++) {
		n_pos_el = 0;
		for (j = 0; j < ncol; j++) {
			sum += arr[i][j];
			if (arr[i][j] > 0) n_pos_el++;
		}
		cout << "Row " << i << ": " << n_pos_el << " positive elements.\n";
	}

	cout << "Average is " << sum / (ncol * nrow) << endl;
	return 0;
}
