// palindrome_filter.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool IsPalindrom(const string s) {
	// перебираем половину символов 
	for (size_t i = 0; i < s.size() / 2; ++i) {
		// и сравниваем со второй половиной с конца
		if (s[i] != s[s.size() - i - 1]) {
			return false;
		}
	}
	return true;
}

// возвращает все строки из вектора words, которые являются палиндромами и имеют длину не меньше minLength
vector<string> PalindromFilter(const vector<string>& words, const int minLength) {
	vector<string> result;
	for (string word : words) {
		if (IsPalindrom(word) && word.size() >= minLength)
			result.push_back(word);
	}
	return result;
}

vector<string> PalindromFilter1(const vector<string>& words, const int minLength) {
	vector<string> result;
	bool isPalindrom = true;
	for (string word : words) {
		for (size_t i = 0; i < word.size() / 2; ++i) {
			if (word[i] != word[word.size() - i - 1]) {
				isPalindrom = false;
			}
		}
		
		if (isPalindrom && word.size() >= minLength)
			result.push_back(word);
	}
	return result;
}


int main()
{	
	vector<string> sample = {"abacaba", "aba", "weew", "bro", "code", ""};
	int minLength = 4;
	vector<string> result = PalindromFilter(sample, minLength);
	for (string word : result) {
		cout << word << ' ';
	}
	cout << endl;
	
    return 0;
}

