// 3_3_quicksort.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h" //uncomment in Visual Studio
#include <iostream>
#include <math.h>

// Knuth's improvement:
// store long part to stack, process the short part immediately
// then stack size is log2(n)
using namespace std;

int main()
{
	const int n = 20;
	//float arr[n], middle, temp;
	float middle, temp;
	int m = log2(n);
	int *stackl = new int[m], *stackr = new int[m], sp = 0;
	// int *stackl = new int[n], *stackr = new int[n], sp = 0;
	int i, j, left, right;
	int counter = 0; bool switched = false;

	// Create an array
	float arr[n] = { 1.7, -18, 34.1, 1.8, 2.8, -9.2, -3, 0.6, 26.1, 5, \
		             11,  -2.5, -3,   0,  2.6,  7.1, -5, 5.9, 19,   0.7 };

	///*cout << "Enter elements: ";
	//for (i = 0; i < n; i++) cin >> a[i];*/
	// for (int q = 0; q < n; q++) cout << arr[q] << ' ';

  // Sorting
	// step 1: sorted fragment is the array itself: store it in the stack
	sp = 1; stackl[1] = 0; stackr[1] = n - 1;
	while(sp > 0) {
		// Extracting the part on the top of stack
		left = stackl[sp]; // 0 on step 1
		right = stackr[sp]; // 19 on step 1
		sp--;   // 0 on step 1
		while (left < right) {
			// Dividing arr[left] .. arr[right]
			i = left; j = right;  // 0, 19 on step 1
			middle = arr[(left + right) / 2];  // 5 on step 1
			while (i < j) {
				while (arr[i] < middle) i++; // 2 on step 1
				while (middle < arr[j]) j--; // 19 on step 1
				if (i <= j) {
					temp = arr[i]; arr[i] = arr[j]; arr[j] = temp; // { 1.7,  -18,  0.7, 1.8, 2.8, -9.2, -3, 0.6, 26.1, 5, \
						                                           //    11, -2.5,   -3,   0, 2.6,  7.1, -5, 5.9, 19,  34.1  };
					switched = true;
					i++; j--;  //  3, 18, on step 1, return to while
				}
			}  // while(i < j)


			if (i - left <= right - j) {
				// cout << "Left part is smaller and is " << i - left << endl;
				if (i < right) {
					// let's store a long part in the stack. It is from i, which went to the middle, to 'right'
					sp++; // 1 again
					stackl[sp] = i;
					stackr[sp] = right;
				} // if (i < right)
				right = j; // Now 'left' and 'right' bind the next pert to process: the left one, which is smaller.
			}
			else {
				// cout << "Left part is bigger. Right part is " << right - j << endl;
				if (j > left) {
					// let's store a long part in the stack. It is from left to j, which went to the middle
					sp++;
					stackl[sp] = left;
					stackr[sp] = j;
				} // if (j > left)
				left = i;
			}

			counter++;
			cout << "Cycle " << counter << ", pivot = " << middle << endl;
			if(!switched) cout << "not SWITCHED!" << endl;
			for (int q = 0; q < n; q++) cout << arr[q] << ' ';
			cout << "Next part is from " << left << " to " << right << endl;

			switched = false;
		//	cout << "Stack status: " << sp << endl;

			// If left = right and there's nothing to sort, we go to ther stack and extract the last written piece!

		} // while (left < right) {


	} // while(sp > 0)

    return 0;
}
