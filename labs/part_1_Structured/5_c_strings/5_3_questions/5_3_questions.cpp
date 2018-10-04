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

#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
  if(argc != 2){ cout<<"Usage: enter the file with strings.\n"; return 1; }
  ifstream input(argv[1]);
  if( !input.is_open() ) { cout<<"Cannot open the file.\n"; return 1; }
  // Let's measure file size
  // Go to the end of file:
  input.seekg(0, input.end);
  // Return a position - it is the length
  long len = input.tellg();
  // cout << "Length is " << len << endl;
  // Create a buffer
  char *buf = new char[len+1];
  input.seekg(0, input.beg);
  input.read(buf, len);
  buf[len] = '\0';
  //cout << "Last character = " << buf[len-2];
  long n = 0, i = 0, j = 0;
  while(buf[i]) {
    if(buf[i] == '?') {
      for (j = n; j <= i; j++) cout << buf[j];
      n = i + 1;
      cout << endl;
    }
    if(buf[i] == '.' || buf[i] == '!')  n = i + 1;
    i++;

  }
  input.close();
  cout << endl;
  cout << "Questions: " << n << endl;
  return 0;
}
