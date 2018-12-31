#include "stdafx.h"
#include <iostream>
#include <map>
#include <string>

using namespace std;

void PrintMap(const map<string, string>& m) {
	for (auto item : m) {
		cout << item.first << ": " << item.second << endl;
	}
}

int main()
{
	int q;
	cin >> q;
	
	map <string, string> capitals;
	for (int i = 0; i < q; ++i) {
		string op;
		cin >> op;
		if (op == "CHANGE_CAPITAL") {
			string country, new_capital;
			cin >> country >> new_capital;

			if (capitals.count(country) == 0) { // такой страны нет
				cout << "Introduce new country " << country << " with capital " << new_capital << endl;
			}
			else { // страна уже присутствует
				if (capitals[country] == new_capital) // название не изменилось у столицы
					cout << "Country " << country << " hasn't changed its capital" << endl;
				else {// название изменилось 
					string old_capital = capitals[country];
					cout << "Country " << country << " has changed its capital from " << old_capital << " to " << new_capital << endl;
				}
			}
			capitals[country] = new_capital;
		}
		else if (op == "RENAME") {
			/*string old_country_name, new_country_name;
			cin >> old_country_name >> new_country_name;

			if (capitals.count[old_country_name] == 1) {
				string capital = capitals[old_country_name];
				capitals.erase(old_country_name);
				capitals[new_country_name] = capital;
				cout << "Country " << old_country_name << " with capital " << capital << " has been renamed to " << new_country_name << endl;
			}
			else {

			}*/
			
		}
		else if (op == "ABOUT") {
			string country;
			cin >> country;

		}
		else if (op == "DUMP") {
			
		}
		PrintMap(capitals);
	}
    return 0;
}

