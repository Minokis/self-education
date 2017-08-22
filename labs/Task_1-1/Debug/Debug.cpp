// Debug.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "Man.h"

const int maxn_record = 10;
const char filename[] = "dbase.txt";

int main(int argc, char *argv[])
{	
	Man man[maxn_record];
	char buf[l_buf + 1];
	char name[l_name + 1];
	
	std::ifstream fin(filename);
	if (!fin) {
		std::cout << "File not found. :(\n";
		return 1;
	}
	int i = 0;
	while (fin.getline(buf, l_buf)) {
		if (i > maxn_record) {
			std::cout << "The file is too long! \n";
			break;
		}
		man[i].SetName(buf);
		man[i].SetBirthYear(buf);
		man[i].SetPay(buf);
		i++;
	}
	int n_record = i, n_man = 0;
	float mean_pay = 0;

	while (true) {
		std::cout << "Enter a surname or \"end\" without quotes: ";
		std::cin >> name;
		if (0 == strcmp(name, "end"))
			break;
		bool not_found = true;
		for (int j = 0; j < n_record; j++) {
			if (man[j].CompareName(name)) {
				not_found = false;
				man[j].Print();
				n_man++;
				mean_pay += man[j].GetPay();
				break;
			}
		}
		if (not_found)
			std::cout << "The person is not found.\n";
	}

	std::cout << "You asked for " << n_man << " people.\n";
	if(n_man) std::cout << "Mean payment is " << mean_pay / n_man << ".\n";
			
    return 0;
}

