/*
��������� � ���� ���������: ��������� � ������������ �������
����� ������� ������� �� �������� 142 ��������
����� ����������� ����� 18 �� �������� 142

������:
���� ������������� ������������� �������. ����������:
1) ���������� �����, ���������� ���� �� ���� ������� �������
2) ����� �������, � ������� ��������� ����� ������� ����� ���������� ���������

1) ���������� ������
a. �������� �������� ������ � �����������, �� �������
	�������� ������: ��������� ����. ������ ��� �������� - ���������� �����
	� ��������, ����� �������� ����� ������
	���������: ����� ����� ����� �� �����, ����� ������� ��� ��������� � ���,
	��� �� ������
	b. �������� ������, ��������
	1) �������� �� �������, ��� ���������� ���� ��������� ������� ����� � ������� � ���������,
	������� ������� �� �����
	2) �������� �� ��������. ��� ��� ��� �����, �������� ���� ������.
	����� ����� ���� � ���������. ��������� ��������� ������ ���������
	 � ��������� �� ����������. ����� ������� ���������� � ���� ���������� ���
	 ������� � ��������� ������ ���� ����� � ���� ������� ��������� ����������
	 �����. ����� ������� �������� ����� ������� ����� ��� �������. Ÿ �����
	 ������� � ������.
	 ����� ��������� ���� ������� ����� ������������ ������� � �������. ��� ������
	 � ����� ������� �������.
	 ���� ��������� ����������, �� ����� ������� ����� ���. ������� ������� -
	 ������� ����� ������ �������.
	 ������� ������� - ��������� ������ � ������� ���������, ��� ����� �������
	 ����� ���. ��������, ��� ���������� ������ �� �������� ������� is_found = 0
	 � ������ ������. � ���� �� ������� - �� � �� �������.
	 ���� ����� ����� ���, �� ������ ����� �� ������
*/

#include "stdafx.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
	int i, j;
	const int nrow = 12;
	const int ncol = 3;
	int arr[nrow][ncol] = { { 0, 0, 1 }, \
	{2, 1, 2}, \
	{3, 1, 3}, \
	{4, 1, 0}, \
	{4, 1, 5}, \
	{4, 2, 5}, \
	{4, 3, 5}, \
	{5, 5, 6}, \
	{6, 5, 7}, \
	{6, 5, 7}, \
	{6, 5, 7}, \
	{0, 5, 7} };


	// dynamic array
	// if(argc != 2) { cout << "Usage: enter a filename.txt.\n"; return 1; }
	// ifstream input(argv[1]);
	// if(!input) { cout << "Cannot open the file.\n"; return 1; }
	//
	// int nrow, ncol;
	// input >> nrow >> ncol;
	// int ** arr = new int*[nrow];
	// for (i = 0; i < nrow; i++) arr[i] = new int[ncol];
	//
	// for (i = 0; i < nrow; i++)
	//   for(j = 0; j < ncol; j++)
	//     input >> arr[i][j];


	// control output
	for (i = 0; i < nrow; i++) {
		for (j = 0; j < ncol; j++)
			cout << arr[i][j] << '\t';
		cout << '\n';
	}


	// part 1: number of rows with at least 1 zero element
	int rows_with_0 = 0;
	for (i = 0; i < nrow; i++) {
		for (j = 0; j < ncol; j++) {
			// cout << "check i = " << i << ", j = " << j << endl;
			if (0 == arr[i][j]) {
				rows_with_0 += 1;
				break;
			}
		}
	}
	cout << "Number of rows with zero is " << rows_with_0 << endl;

	// part 2: the longest sequence in the columns
 // iteration 3: there can be several sequences in one column

	// array for sequences - we need it to find the index of a column with the longest sequence
	int seqs[ncol];
	// special array for SEVERAL sequences in one column j
	int seqs_in_j[nrow / 2];
	// counter for this special array
	int s;
	bool onseq;
	int max_seq_in_j_index;


	for (j = 0; j < ncol; j++) {
		s = 0;
		seqs_in_j[s] = 1;
		onseq = false;

		for (i = 1; i < nrow; i++) {
			if (arr[i - 1][j] == arr[i][j]) {
				// sequence detected
				onseq = true;
				seqs_in_j[s] += 1;
			}
			else { 
				if (onseq) { // sequence is ended
					s += 1;
					seqs_in_j[s] = 1;
					onseq = false;
				}
			}
		}
		// what sequence is the longest in one column?
		max_seq_in_j_index = 0;
		for (int k = 0; k <= s; k++)
			if (seqs_in_j[k]>seqs_in_j[max_seq_in_j_index]) max_seq_in_j_index = k;
		// let's write it in the array of sequences
		seqs[j] = seqs_in_j[max_seq_in_j_index];
	}

	// control output of sequences
	cout << "Sequences: \n";
	for (j = 0; j < ncol; j++)
		cout << seqs[j] << ' ';
	cout << endl;

	bool max_found = false;
	int max_seq_index = 0;
	for (j = 0; j < ncol; j++) {
		if (seqs[j] > seqs[max_seq_index]) { max_seq_index = j; max_found = true; }
		if (seqs[i] == seqs[max_seq_index]) max_found = false;
	}

	if (max_found)
		cout << "The longest sequence is " << seqs[max_seq_index] << ", column " \
		<< max_seq_index + 1 << endl;
	else
		cout << "There's no longest sequence.\n";

	return 0;

	}
