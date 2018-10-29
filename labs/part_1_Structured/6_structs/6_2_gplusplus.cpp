// Программа упорядочивает файл из 6_1 по году рождения сотрудников
#include <fstream>
#include <iostream>
#include <limits>

//#include <windows.h>
using namespace std;

int main(int argc, char *argv[])
{
	if (argc != 2) { cout << "Usage: enter the file with HR data.\n"; return 1; }
	const int l_name = 30, l_year = 5, l_pay = 10, l_buf = l_name + l_year + l_pay;

	struct Man {
		char name[l_name + 1];
		int birth_year;
		float pay;
	};
	const int l_dbase = 100;
	Man dbase[l_dbase];

	char buf[l_buf + 1];

	ifstream input(argv[1]);
	if (!input) { cout << "Cannot open the file.\n"; return 1; }


	// Reading from a file
	int i = 0;
	while (input.getline(buf, l_buf)) {
		if(strlen(buf) == 0) {cout << "Empty line\n"; continue;}
		int beg = 0;
		for (; beg < l_name; beg++) {
			if (isalpha(buf[beg])) break;
		}
		strncpy(dbase[i].name, buf + beg, l_name - beg);
		if (strlen(dbase[i].name) == 1 || strlen(dbase[i].name) == 0) { cout << "found empty name. skipping.\n"; continue; }

		dbase[i].name[l_name] = '\0';
		dbase[i].birth_year = atoi(&buf[l_name]);
		dbase[i].pay = atof(&buf[l_name + l_year]);
		i++;
		if (i >= l_dbase) { cout << "The file is too long. Stopping.\n"; return 1; }
	}
	int n_record = i;
	input.close();
	ofstream fout("dbase_6_2.txt");
	if (!fout) { cout << "Cannot open the output file.\n"; return 1; }

	// Control output
	for (int c = 0; c < n_record; c++) {
		cout << dbase[c].name << dbase[c].birth_year << ' ' << dbase[c].pay << endl;
	}
	cout << "N_rec: " << n_record << endl;

	// Sort by birth year

	for (i = 0; i < n_record - 1; i++) {
		int imin = i;
		//cout << "Cycle " << i << ", min is " << dbase[imin].birth_year << endl;
		for (int j = i + 1; j < n_record; j++)
			if (dbase[j].birth_year < dbase[imin].birth_year) imin = j;
		//cout << "Current is " << dbase[i].birth_year << ", changing with " << dbase[imin].birth_year << endl;
		Man a = dbase[i];
		dbase[i] = dbase[imin];
		dbase[imin] = a;

	}
	for (i = 0; i < n_record; i++) {
		fout << dbase[i].name << dbase[i].birth_year << ' ' << dbase[i].pay << endl;
	}
	fout.close();
	cout << "Done.\n";


	return 0;
}
