//============================================================================
// Name        : temperature.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

int CalcAvg(const vector<int>& v) {
	if(v.size() == 0)
		return 0;
	int result = 0;
	for (int value: v) {
		result += value;
	}
	result /= v.size();
	return result;
}

void PrintIndices(const vector<int>& v, const int& avg) {
	vector<int> indices;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] > avg) {
			indices.push_back(i);
		}
	}
	cout << indices.size() << endl;
	for (int index: indices) {
		cout << index << ' ';
	}
}

int main() {
	int n;
	cin >> n;
	vector<int> t(n);
	for (int i = 0; i< n; i++) {
		cin >> t[i];
	}
	int avg = CalcAvg(t);
	//cout << "avg = " << avg << endl;
	PrintIndices(t, avg);
	return 0;
}
