// Дополнить бинарный файл из задачи 6_3 сведениями о сотрудниках,
// с клавиатуры
// Функция один: ввод в структуру
// Функция два: запись в файл
// Функция для проверки: по введенному номеру выведет запись

#include <stdio.h>
#include <string>
#include <stdlib.h>

using namespace std;
const int l_name = 30;
struct Man {
  char name[l_name + 1];
  int birth_year;
  float pay;
};

// ввод данных в структуру с клавиатуры
 Man read_data();
 // добавление структуры в файл
//  int append2binfile(const Man &man, const char* filename);
// // вывод записи по номеру
// int print_from_bin (const char* filename);

int main(int argc, char *argv[]) {
  if(argc != 2) { puts("Usage: enter the binary file with HR data.\n"); return 1; }
  char filename[] = argv[1];


  FILE *output;
  if ( (output = fopen("dbase_out.bin", "wb")) == NULL ) {
    puts("Cannot open output file.\n"); return 1;
  }



}

Man read_data() {

}
