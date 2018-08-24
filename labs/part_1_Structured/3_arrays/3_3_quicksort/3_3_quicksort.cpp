// 3_3_quicksort.cpp: ���������� ����� ����� ��� ����������� ����������.
//

//#include "stdafx.h" //uncomment in Visual Studio
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
	/*cout << "Enter elements: ";
	for (i = 0; i < n; i++) cin >> a[i];*/

	// Create an array
	float arr[n] = { 1.7, -18, 34.1, 1.8, 2.8, -9.2, -3, 0.6, 26.1, 5, \
		               11,  -2.5, -3,   0,  2.6,  7.1, -5, 5.9, 19,   0.7 };

  // Sorting
	// step 1: sorted fragment is the array itself
	sp = 1; stackl[1] = 0; stackr[1] = n - 1;
	// while(sp > 0) {
	  left = stackl[sp]; // 0
		right = stackr[sp]; // 19
		sp--;   // 0
	  while (left < right) {
			// Dividing arr[left] .. arr[right]
			i = left; j = right;  // 0, 19
			middle = arr[(left+right)/2];  // 5
			while(i<j) {
				while (arr[i] < middle) i++; // 1
				while (middle < arr[j]) j--; // 19
				if (i <= j) {
					temp = arr[i]; arr[i] = arr[j]; arr[j] = temp; // { 1.7,  0.7  34.1, 1.8, 2.8, -9.2, -3, 0.6, 26.1, 5, \
						                                             //    11, -2.5,   -3,   0, 2.6,  7.1, -5, 5.9, 19,  -18,  };
					i++; j--;  //  2, 18
				}
			}
		}


  // } // while(sp > 0)

    return 0;
}
