// 2_5_sum.cpp: îïðåäåëÿåò òî÷êó âõîäà äëÿ êîíñîëüíîãî ïðèëîæåíèÿ.
// Çàäà÷à íà ñõîäèìîñòü ñóììû ðÿäà

#include "stdafx.h"
#include <iostream>
#include <math.h>


int main()
{
	setlocale(LC_ALL, "Russian");
	using namespace std;
	cout << "Ââåäèòå àðãóìåíò x è òî÷íîñòü: ";
	double y = 1, current = 1, x, eps;
	cin >> x >> eps;
	const int MaxIter = 500;

	for (int n = 0; n < 5; ++n) {
		current *= x * x / (2 * n + 1) / (2 * n + 2);
		y += current;
		cout << "current = " << current << ", y = " << y << endl;
	}
	
// 	for (int n = 0; n < MaxIter; ++n) {
// 		current *= x * x / (2 * n + 1) / (2 * n + 2);
// 		if(current < epsilon) {
// 			cout << "Result: y = " << y << ", " << n << " iterations." << endl;
// 			break;
// 		}
// 		y += current;
// 		if (n = MaxIter-1) {
// 			cout << "Couldn't reach the answer. Current result: y = " << y << ", " << n << " iterations." << endl;
// 		}
// 	}
    return 0;
}

