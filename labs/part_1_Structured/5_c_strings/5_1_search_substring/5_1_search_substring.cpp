// 5_1_search_substring.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
// Программа определяет, не встречается ли в текстовом файле со строками заданная последовательность символов.
// Длина строки не превышает 80 символов
// Текст не содержит переносов слов, последовательность не содержит пробелов

#include "pch.h"
#include <iostream>
#include <string.h>


int main(int argc, char *argv[] )
{
	const int str_len = 81;
	char current_str[str_len];
	char substr[str_len];

	while (std::cin.getline(current_str, str_len)) {

	};

	

	std::cin.getline(substr, str_len);
	if (strstr(str, substr))
		std::cout << "Yes, it's here\n";
	else
		std::cout << "No, it is not here\n";

	return 0;

}

