//Этот пример взят из учебника на стр 90
// пример файлика:
//BL2700HT            12350 15000 New
//BL2500HT            9000  11004 Old-fashioned
//осторожно с пробелами, в этой программке нет распознавания

#include <iostream>
#include <stdio.h>  // ничоси
#include <stdlib.h>
#include <string.h>

using namespace std;

int main() {
  FILE *fi, *fo;
  if ((fi = fopen("file.txt", "r")) == 0) {
    cout << "Ошибка открытия входного файла"; return 1;
  }
  if ((fo = fopen("file2.out", "w+b")) == 0) {
    cout << "Ошибка открытия выходного файла"; return 1;
  }
  // длина буфера
  const int dl = 80;
  // выделение буфера для строк
  char s[dl];
  struct {
    char type[20];
    int opt, rozn;
    char comm[40];
  }mon;
  // количество записей в файле
  int kol = 0;
  // fgets осуществляет чтение строки из потока
  while(fgets(s, dl, fi)) {
    // преобразование строки в структуру:
    strncpy(mon.type, s, 19);
    mon.type[19]='\0';
    cout << mon.type << endl;
    mon.opt = atoi(&s[20]);
    cout << mon.opt << endl;
    mon.rozn = atoi(&s[25]);
    cout << mon.rozn << endl;
    strncpy(mon.comm, &s[32], 40);
    cout << mon.comm << endl;
    fwrite(&mon, sizeof mon, 1, fo); //ptr, size, count, stream
    kol++;
  }
  fclose(fi);

  // поиск по номеру записи
  int i; cin >> i;
  if (i >= kol) {cout << "Запись не существует"; return 1;}
  // установка указателя текущей позиции файла на запись i:
  fseek(fo, (sizeof mon)*i, SEEK_SET);
  fread(&mon, sizeof mon, 1, fo);
  cout << "mon.type " << mon.type << ", opt " << mon.opt << ", rozn " << mon.rozn << \
  ", comment: " << mon.comm << endl;
  fclose(fo);
  return 0;
}
