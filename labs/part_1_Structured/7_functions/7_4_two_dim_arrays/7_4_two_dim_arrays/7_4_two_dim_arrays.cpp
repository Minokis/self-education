// 7_4_two_dim_arrays.cpp: определяет точку входа для консольного приложения.
// в какой строке матрицы mxn содержится больше всего одинаковых элементов?

#include "stdafx.h"
#include <fstream>
#include <iostream>

// Returns a row count from 1 to n - the first row with the longest sequence. If returns 0, no duplicates are found.
int max_seq_row(int **a, const int m, const int n);

int main()
{
	std::ifstream fin("test.txt");
	if (!fin) { std::cout << "Couldn't open the file" << std::endl; return 1; }

	int m, n, i=0, j = 0;
	fin >> n >> m;
	int **arr = new int *[n];
	for (i = 0; i < n; i++) arr[i] = new int[m];

	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)	fin >> arr[i][j];

	// Control output 
	// for (i = 0; i < n; i++) {
	// 	for (j = 0; j < m; j++)
	// 		std::cout << arr[i][j] << ' ';
	// 	std::cout << '\n';
	// }

	int line = max_seq_row(arr, m, n);
	if(line >= 0) std::cout << "The row with longest sequence is " << line << std::endl;
	else std::cout << "No series in the matrix.\n";
    return 0;
}

int max_seq_row(int **a, const int m, const int n) {
	int i, j, count, line = -1, maxcount = 0;
	for (i = 0; i < n; i++) {
		count = 0;
		for (j = 0; j < m -1; j++) {
			if (a[i][j] == a[i][j+1]) count++;
			else {
				if (count > maxcount) { 
					maxcount = count; line = i;}
					count = 0;
			}
		}
		if (count > maxcount) { maxcount = count; line = i;}
	}
	return line;
}
