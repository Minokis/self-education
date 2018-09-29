#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>
#include <ctime>

int main()
{
	int ncol, nrow, val;
  std::cout << "Welcome! Let's create a matrix.\n";
	std::cout << "Values will be written to the file, separated by a whitespace (one row).\n";
  std::cout << "Enter nrow (number of rows): \n";
  std::cin >> nrow;
	std::cout << "Enter ncol (number of columns): \n";
	std::cin >> ncol;
	std::string name;
	std::cout << "Enter filename (for output file): \n";
  std::cin >> name;

  // Seed
  std::srand(static_cast<unsigned int>(std::time(0)));

	// writing into file
	std::ofstream fileF;
	fileF.open(name);
	fileF << nrow << " " << ncol << std::endl;
	for (int i = 0; i < nrow*ncol; i++) {
		std::rand() % 2 ? fileF << std::rand() << " " : fileF << (-1) * std::rand() << " ";
	}
	fileF.close();
	return 0;
}
