// Написать программу, которая считывает текст из файла и выводит только
// вопросительные предложения из этого текста.
// 1. Исходные данные:
// Текстовый файл.txt, размер неизвестен, предложение может быть разбито
// на несколько строк.
// Результат: все вопросительные предложения выведены на экран
// Промежуточные: для хранения выделим буфер, в который поместится весь файл.
// Для длины файла используем long int. Для вывода предложений понадобятся переменные,
// указывающие на начало и конец предложения.
// 2. Алгоритм
// Двигаясь по буферу, запоминать позиции начала и конца предложения с помощью
// поиска знаков пунктуации. Как только найден вопросительный знак, вывести пред-
// ложение.
// 1) Открыть файл.
// 2) Определить его длину в байтах
// 3) Выделить в динамической памяти буфер подходящего размера
// 4) Считать файл с диска в буфер
// 5) Анализируя буфер посимвольно, выделять предложения. (.?!) Как только найден
// вопросительный знак, вывести предложение.

#include "stdafx.h"
#include <stdio.h>

using namespace std;

int main(int argc, char *argv[])
{
	errno_t err;
	if(argc != 2){ puts("Usage: enter the file with strings.\n"); return 1; }
	FILE *input;
	err = fopen_s(&input, argv[1], "r");
	if( !input ) { puts("Cannot open the file.\n"); return 1; }
	
	// Let's measure file size
	// Go to the end of file:
	fseek(input, 0, SEEK_END);
	
	// Return a position - it is the length
	long len = ftell(input);
	// printf("Length is %ld\n", len);
	
	// create a buffer
	char *buf = new char[len+1];
	const int l_block = 1024;
	int num_block = len / l_block + 1;
  
	fseek(input, 0, SEEK_SET);
	fread(buf, l_block, num_block, input);
	buf[len] = '\0';
    // printf("Last character = %c", buf[len-2]);
  
	long n = 0, i = 0, j = 0;
	while(buf[i]) {
		if(buf[i] == '?') {
		   for (j = n; j <= i; j++) putchar(buf[j]);
		   n = i + 1;
		   printf("\n");
		 }
		 if(buf[i] == '.' || buf[i] == '!')  n = i + 1;
		 i++;
	 }
	 fclose(input);
	 printf("\n");
	   return 0;
}
