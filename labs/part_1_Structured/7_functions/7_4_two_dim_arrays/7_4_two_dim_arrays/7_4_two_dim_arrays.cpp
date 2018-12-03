// 7_4_two_dim_arrays.cpp: определяет точку входа для консольного приложения.
// в какой строке матрицы mxn содержится больше всего одинаковых элементов?

#include "stdafx.h"
#include <fstream>
#include <iostream>

// Returns a row count from 1 to n - the first row with the longest sequence. If returns 0, no duplicates are found.
int max_seq_row(int **a, const int m, const int n);
// Returns a longest sequence in a row
int count_dupl(const int *row, const int m);
int max_index(const int* a, const int len);

int main()
{
	std::ifstream fin("test.txt");
	if (!fin) { std::cout << "Couldn't open the file" << std::endl; return 1; }

	int m, n, i=0, j = 0;
	fin >> n >> m;
	int ** arr = new int*[n];
	for (i = 0; i < n; i++) arr[i] = new int[m];

	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			fin >> arr[i][j];

	// Control output 
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++)
			std::cout << arr[i][j] << ' ';
		std::cout << '\n';
	}

	//std::cout << "Test 1: max_index\n";
	//for (i = 0; i < n; i++)
	//	std::cout << "Index of max in row " << i << " is " << max_index(arr[i], m) << std::endl;
  
	std::cout << "Test 2: count_dupl\n";
	for (i = 0; i < n; i++)
		std::cout << "Duplicate count for row with index " << i << " is " << count_dupl(arr[i], m) << std::endl;

	std::cout << "Test 3: max_seq_row\n";

	std::cout << "The row with longest sequence is " << max_seq_row(arr, m, n) << std::endl;

    return 0;
}

int max_seq_row(int **a, const int m, const int n) {
	int *seqs = new int[n];
	
	for (int i = 0; i < n; i++) 
		seqs[i] = count_dupl(a[i], m);
	
	return max_index(seqs, n)+1;
}

// Counts duplicates in a row and returns the longest sequence (out of many, if they exist)
int count_dupl(const int *row, const int m) {
	int *seqs = new int[m / 2];
	int seq_count = 0;
	seqs[seq_count] = 1;
	bool on_seq = false;
	for (int j = 1; j < m; j++) {
		if (row[j - 1] == row[j]) {
			on_seq = true;
			seqs[seq_count]++;
		}
		else if (on_seq) {
			on_seq = false;
			seq_count++;
			seqs[seq_count] = 1;
		}
	}
	int result = seqs[max_index(seqs, m / 2)];
	delete[] seqs;
	return result;
}

int max_index(const int* a, const int len) {
	int index = 0;
	for (int i = 0; i < len; i++)
		if (a[i] > a[index])
			index = i;
	//std::cout << "I counted index as " << index << ", gonna return.\n";
	return index;
}

