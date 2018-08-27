// 3_3_quicksort.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h" //uncomment in Visual Studio
#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	const int n = 20;
	//float arr[n], middle, temp;
	float middle, temp;
	int *stackl = new int[n], *stackr = new int[n], sp = 0;
	int i, j, left, right;
	int counter = 0;

	// Create an array
	float arr[n] = { 1.7, -18, 34.1, 1.8, 2.8, -9.2, -3, 0.6, 26.1, 5, \
		             11,  -2.5, -3,   0,  2.6,  7.1, -5, 5.9, 19,   0.7 };

	///*cout << "Enter elements: ";
	//for (i = 0; i < n; i++) cin >> a[i];*/
	// for (int q = 0; q < n; q++) cout << arr[q] << ' ';

  // Sorting
	// step 1: sorted fragment is the array itself
	sp = 1; stackl[1] = 0; stackr[1] = n - 1;
	while(sp > 0) {
		// Extracting the last 'right part' which is on the top of stack
		left = stackl[sp]; // 0
		right = stackr[sp]; // 19
		sp--;   // 0
		while (left < right) {
			// Dividing arr[left] .. arr[right]
			i = left; j = right;  // 0, 19
			middle = arr[(left + right) / 2];  // 5
			cout << "middle is " << middle << endl;
			while (i < j) {
				while (arr[i] < middle) i++; // 2
				while (middle < arr[j]) j--; // 19
				if (i <= j) {
					temp = arr[i]; arr[i] = arr[j]; arr[j] = temp; // { 1.7,  -18,  0.7, 1.8, 2.8, -9.2, -3, 0.6, 26.1, 5, \
						                                           //    11, -2.5,   -3,   0, 2.6,  7.1, -5, 5.9, 19,  34.1  };
					i++; j--;  //  3, 18, возврат к while
				}
			}  // while(i < j)
			

			if (i < right) {
				// let's store our right part in the stack. It is from i, which went to the middle, to 'right' 
				sp++; // 1 again
				stackl[sp] = i;
				stackr[sp] = right;
			} // if (i < right)
			right = j; // making our part smaller. Now 'left' and 'right' bind the left half of prosessed part.

			counter++;
			cout << "Cycle " << counter << ", pivot = " << middle << endl;
			for (int q = 0; q < n; q++) cout << arr[q] << ' ';
			cout << "Next part is from " << left << " to " << right << endl;

			// If left = right and there's nothing to sort, we go to ther stack and extract the last written piece!

		} // while (left < right) {


	} // while(sp > 0)

    return 0;
}
