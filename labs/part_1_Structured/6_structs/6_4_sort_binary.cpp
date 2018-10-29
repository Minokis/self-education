// Написать программу, которая выводит на экран содержимое бинарного файла, выводя
// записи, сформированные по алфавиту.
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
int compare_names(const void *man1, const void *man2);
int compare_birth(const void *man1, const void *man2);
int compare_pay(const void *man1, const void *man2);

int main(int argc, char *argv[])
{
  if(argc != 2) { puts("Usage: enter the file with HR data.\n"); return 1; }

  FILE *fin;
  if( (fin = fopen(argv[1], "rb")) == NULL ) {
    puts("Cannot open the file.\n"); return 1;
  }

  fseek(fin, 0, SEEK_END);
  int n_record = ftell(fin)/sizeof(Man);
  printf("N_rec = %i\n", n_record);

  Man *man = new Man[n_record];
  fseek(fin, 0, SEEK_SET);
  fread(man, sizeof(Man), n_record, fin);
  fclose(fin);

  qsort(man, n_record, sizeof(Man), compare_pay);

  for (int i = 0; i < n_record; i++) {
    printf("%s %5i %10.2f\n", man[i].name, man[i].birth_year, \
    man[i].pay);
  }

  return 0;
}

int compare_names(const void *man1, const void *man2) {
  return strcmp ( (reinterpret_cast <const Man*>(man1))->name, (reinterpret_cast <const Man*>(man2))->name  );
}

int compare_birth(const void *man1, const void *man2) {
  return ((Man*)man1)->birth_year > ((Man*)man2)->birth_year ? 1 : \
  ((Man*)man1)->birth_year == ((Man*)man2)->birth_year ? 0 : -1;
}

int compare_pay(const void *man1, const void *man2) {
  return ((Man*)man1)->pay > ((Man*)man2)->pay ? -1 : \
  ((Man*)man1)->pay == ((Man*)man2)->pay ? 0 : 1;
}

/* Bugs:
1) If compare_names, mayer is in the end, because it starts with lowercase letter.
2) Steel and Downey have wrong names and years (symbols shifted)

Solution: binary file mast be "cleaned": no extra whitespace, names are fixed: everything lowercase,
but first letter and initials

*/
