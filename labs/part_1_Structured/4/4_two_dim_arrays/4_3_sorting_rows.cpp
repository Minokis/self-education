/*
Написать программу, которая упорядочивает строки прямоугольной целочисленной
матрицы по возрастанию сумм их элементов

1) Постановка задачи: ТЗ + спецификация
  a. Описание исходных данных и результатов, их свойств
      Исходные данные: текстовый файл. Первые два значения - количество строк
      и столбцов, затем значения через пробел
      результат: файл, в который записана новая матрица: снова строки и столбцы,
      затем упорядоченная матрица
  b. Описание реализуемой задачи
      программа читает матрицу из файла и записывает ее в двумерный массив;
      считает суммы по строкам, запоминая, какой сумме какая строка соответствует;
      записывает суммы в массив, /создает вспомогательный массив с номерами строк/;
      сортирует /пары суммы+строки/ по возрастанию сумм;
      записывает строки в файл исходя из вспомогательного массива.

      Алгоритм сортировки - метод выбора. Если мы используем его, то нам не нужен вспомогательный массив,
      так как мы можем сразу поставить "наименьшую" строку на первое место
      *****интересно, а какой вариант быстрее?*******
  c. Способ обращения к программе
      в качестве аргумента используется имя входного файла
  d. Описание аварийных ситуаций и ошибок пользователя
      не то количество аргументов;
      файл не читается;
      в файле не тот формат;
      не хватает/слишком много элементов;
      выход за пределы любого из используемых массивов;
      не создать файл для записи.
      так как цели учебные, обработаем только 1 и последнюю.
2) Разработка внутренних структур данных (статич, динамич)
      динамические массивы элементов целого типа int
        для чтения из файла, сортируется и пишется она же
        суммы строк (long) и /вспомогательный массив с номерами строк (int)/

      /пары бы как-нибудь получше использовать, но словари мы еще не проходили/
3) Проектирование (определение общей структуры и взаимодействия модулей) - сверху вниз + спецификации интерфейсов и самих модулей
  1. Чтение и запись в динамический массив - done
  2. подсчет сумм и запись в long[]
  3. упорядочивание
  4. запись в файл
4) Структурное программирование - сверху вниз
5) Нисходящее тестирование
*/

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {
  // Open the file
  if(argc != 2) { cout << "Usage: enter a filename.txt.\n"; return 1; }
  ifstream input(argv[1]);
  if(!input) { cout << "Cannot open the file.\n"; return 1; };

  ofstream output("sorted_matrix.txt");
  if(!output) { cout << "Cannot open the file for writing.\n"; return 1; };

  // Write the contents into the arr[][]
  int nrow, ncol;
  int i,j;
  input >> nrow >> ncol;

  int **arr = new int*[nrow];
  for (i = 0; i < nrow; i++)    arr[i] = new int[ncol];

  for (i = 0; i < nrow; i++)
    for (j = 0; j < ncol; j++)
      input >> arr[i][j];

  // Calculating the sums
  long *sums = new long[nrow];

  for (i = 0; i < nrow; i++) {
    sums[i] = 0; // i checked that the new array is created with zeros. but I will make sure of it just in case.
    for (j = 0; j < ncol; j++)
      sums[i] += arr[i][j];
  }

  // control output of sums[]
  for (i = 0; i < nrow; i++) cout << sums[i] << ' ';
  cout << endl;

  // Sorting the arr[][]
  int nmin, buf_arr;
  long buf_sum;
  for (int k = 0; k < nrow; k++) {
    nmin = k;
    for (i = k; i < nrow; i++) {
      if (sums[i] < sums[nmin]) nmin = i;
    }

    buf_sum = sums[k];
  //  cout << "nmin = " << nmin << ", k = " << k << ", buf_sum = " << sums[k] << endl;
    sums[k] = sums[nmin];
    sums[nmin] = buf_sum;

    for (j = 0; j < ncol; j++) {
      buf_arr = arr[k][j];
      arr[k][j] = arr[nmin][j];
      arr[nmin][j] = buf_arr;
    }
  }

  // control output of sums[]
  for (i = 0; i < nrow; i++) cout << sums[i] << ' ';
  cout << endl;

  // control output of the arr[][]
  for (i = 0; i < nrow; i++) {
    for (j = 0; j < ncol; j++)
      cout << arr[i][j] << "\t";
    cout << "\n";
  }

  output << nrow << ' ' << ncol << '\n';
  for (i = 0; i < nrow; i++) {
    for (j = 0; j < ncol; j++)
      output << arr[i][j] << "\t";
    output << "\n";
    }

  return 0;
}
