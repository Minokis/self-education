/* Задание: в текстовом файле хранится база отдела кадров,
всего 100 сотрудников. Каждая строка файла содержит запись об одном сотруднике:
фамилия и инициалы (30 позиций), год рождения (5 позиций), оклад (10 позиций).
Написать программу, которая по заданной фамилии выводит на экран сведения
о сотруднике, подсчитывая средний оклад всех запрошенных сотрудников.
  Использовать функции из stdio!
 */

// Исходные данные
// Текстовый файл; так как поиск осуществляется неоднократно, удобно весь
// его перенести в оперативную память в виде массива структур
// Результаты
// Выведена информация о сотруднике на экран. По завершении - средний оклад
// Промежуточные
// массив структур, вещественная для суммарного оклада, счетчик сотрудников

// Алгоритм
// 1. Ввести из файла в массив сведения
// 2. Организовать цикл (до ввода слова end):
// - ввод фамилии с клавиатуры
// - поиск в массиве
// - увеличение счетчика и суммарного оклада
// - вывод информации о сотруднике / сбщ об ошибке
// 3. Вывести средний оклад

#include <limits>
#include <string>
#include <stdio.h>

//#include <windows.h>
using namespace std;

int main(int argc, char *argv[])
{
  if(argc != 2) { puts("Usage: enter the file with HR data.\n"); return 1; }
  const int l_name = 30, l_year = 5, l_pay = 10, l_buf = l_name+l_year+l_pay;

  struct Man {
    char name[l_name + 1];
    int birth_year;
    float pay;
  };
  const int l_dbase = 100;
  Man dbase[l_dbase];


  char name[l_name + 1];
  char buf[l_buf + 1];

  FILE *input;
  if( (input = fopen(argv[1], "r")) == NULL ) { puts("Cannot open the file.\n"); return 1; }

  // Reading from a file
  int i = 0;
  while( !feof(input) ) {
    int beg = 0;
    for (; beg < l_name; beg++) {
      if ( isalpha(fgetc(input)) ) {
        beg++;
        fseek(input, -beg, SEEK_CUR);
        break; }
    }
    fgets(dbase[i].name, l_name-beg, input);
    fscanf(input, "%i%f\n", &dbase[i].birth_year, &dbase[i].pay);
    i++;
    if (i >= l_dbase) { puts("The file is too long. Stopping.\n"); return 1; }
  } // end of file-reading

  int n_record = i, n_man = 0;
  float mean_pay = 0;

  //Control output
  for (int c = 0; c < n_record; c++) {
    printf("%s\t%i\t%f\n", dbase[c].name, dbase[c].birth_year, dbase[c].pay);
  }


  //
  // while(true) {
  //   cout << "Enter a name or a word \"end\": ";
  //   // OemToChar(name, name);
  //   cin.get(name, l_name+1);
  //   cin.clear();
  //   cin.ignore( numeric_limits<streamsize>::max(), '\n');
  //
  //   if ( strcmp(name, "end") == 0 ) break;
  //
  //   bool not_found = true;
  //   char low_dbase_name[l_name];
  //   char low_name[l_name];
  //
  //   for( i = 0; i < n_record; i++) {
  //     for (int ch = 0; ch < l_name; ch++) {
  //       low_dbase_name[ch] = tolower( dbase[i].name[ch] );
  //       low_name[ch] = tolower( name[ch] );
  //     }
  //
  //     if ( strstr( low_dbase_name, low_name ) )
  //       if ( dbase[i].name[strlen(name)] == ' ') { // check if it is a part of name
  //         // strcpy(name, dbase[i].name); // ? is it necessary ?
  //         // CharToOem(name, name);
  //         cout << dbase[i].name << dbase[i].birth_year << ' ' << dbase[i].pay << endl;
  //         n_man++; mean_pay += dbase[i].pay;
  //         not_found = false;
  //       } // end of if if ( dbase[i].name[strlen(name)] == ' ') and strstr(lows)
  //   } // end of search through records (  for( i = 0; i < n_record; i++)  )
  //   if(not_found) cout << "No person with this name." << endl;
  // }
  //   if(n_man>0) cout << "Average pay: " << mean_pay / n_man << endl;
    return 0;
}


// адаптировать для русского языка и кодировок ASCII и ANSI (раскомментировать,
// дописать функции и попробовать)
// функции для регистров русского языка tolower/toupper