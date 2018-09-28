/*
выполнить в двух вариантах: локальные и динамические массивы
более сложные задания на странице 142 учебника
Здесь выполняется номер 18 на странице 142

Задача:
Дана целочисленная прямоугольная матрица. Определить:
1) количество строк, содаржащих хотя бы один нулевой элемент
2) номер столбца, в котором находится самая длинная серия одинаковых элементов

1) Постановка задачи
a. Описание исходных данных и результатов, их свойств
    Исходные данные: текстовый файл. Первые два значения - количество строк
    и столбцов, затем значения через пробел
    результат: вывод числа строк на экран, вывод столбца или сообщения о том,
    что не найден
    b. Описание задачи, алгоритм
    1) пройтись по строкам, при нахождении нуля увеличить счетчик строк и перейти к следующей,
    вывести счетчик на экран
    2) пройтись по столбцам. Так как это серия, элементы идут подряд.
    Серий может быть и несколько. требуется составить список элементов
     и посчитать их количество. Можно занести количество в одну переменную для
     столбца и обновлять только если серия в этом столбце превысила предыдущую
     серию. Таким образом получишь самую длинную серию для столбца. Её нужно
     занести в массив.
     После обработки всей матрицы найти максимальный элемент в массиве. Его индекс
     и будет номером столбца.
     Если несколько одинаковых, то самой длинной серии нет. вариант попроще -
     выбрать самый первый столбец.
     вариант сложнее - отследить повтор и вывести сообщение, что самой длинной
     серии нет. например, при нахождении такого же значения сделать is_found = 0
     и искать дальше. А если не найдешь - то и не найдено.
     если везде серий нет, то массив будет из единиц
*/

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {
  // counters
  int i, j;
  // static array
  const int nrow = 10;
	const int ncol = 3;
	int arr[nrow][ncol] ={ {0, 1, 1}, \
                         {2, 1, 2}, \
                         {3, 1, 3}, \
                         {4, 1, 0}, \
                         {4, 1, 5}, \
                         {4, 2, 5}, \
                         {4, 3, 5}, \
                         {5, 4, 6}, \
                         {6, 5, 7}, \
                         {0, 6, 8} };

  // dynamic array
  // if(argc != 2) { cout << "Usage: enter a filename.txt.\n"; return 1; }
  // ifstream input(argv[1]);
  // if(!input) { cout << "Cannot open the file.\n"; return 1; }
  //
  // int nrow, ncol;
  // input >> nrow >> ncol;
  // int ** arr = new int*[nrow];
  // for (i = 0; i < nrow; i++) arr[i] = new int[ncol];
  //
  // for (i = 0; i < nrow; i++)
  //   for(j = 0; j < ncol; j++)
  //     input >> arr[i][j];

  // control output
  for (i = 0; i < nrow; i++) {
    for(j = 0; j < ncol; j++)
      cout << arr[i][j] << '\t';
    cout << '\n';
  }

  // part 1: number of rows with at least 1 zero element
  int rows_with_0 = 0;
  for (i = 0; i < nrow; i++) {
    for (j = 0; j< ncol; j++) {
      // cout << "check i = " << i << ", j = " << j << endl;
      if (0 == arr[i][j]) {
        rows_with_0 += 1;
        break;
      }
    }
  }
  cout << "Number of rows with zero is " << rows_with_0 << endl;

  // part 2: the longest sequence in the columns
  // iteration 1: only one sequence in the column,
  // out of several maximums take the one on the left
  // bool seq_found;
	int seq_in_col;
	int seqs[ncol];

	for(j = 0; j < ncol; j++) {
		// seq_found = false;
		seq_in_col = 1;
		for (i = 1; i < nrow; i++) {
			if (arr[i - 1][j] == arr[i][j]) {
				// seq_found=true;
				seq_in_col +=1;
			}
		}
		if(1 != seq_in_col) seqs[j] = seq_in_col;
	}
  // control output of sequences
  cout << "Sequences: \n";
	for(j = 0; j < ncol; j++)
		cout << seqs[j] << ' ';
  cout << endl;

	int max_seq_index = 0;
	for(j = 0; j < ncol; j++)
		if (seqs[j] > seqs[max_seq_index]) max_seq_index = j;

	cout << "The longest sequence is " << seqs[max_seq_index] << ", column " \
        << max_seq_index + 1 << endl;

  return 0;
}
