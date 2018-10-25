/* Задание: написать программу, которая считывает данные из файла из задачи 6_1
и записывает в бинарный файл.
 */


#include <string>
#include <stdio.h>

//#include <windows.h>
using namespace std;

int main(int argc, char *argv[])
{
  if(argc != 2) { puts("Usage: enter the file with HR data.\n"); return 1; }
  const int l_name = 30;

  struct {
    char name[l_name + 1];
    int birth_year;
    float pay;
  } man;

  FILE *fout;
  if( (fout = fopen(argv[1], "r+b")) == NULL ) {
    puts("Cannot open the file.\n"); return 1;
  }

  fseek(fout, 0, SEEK_END);
  int n_record = ftell(fout)/sizeof(man);
  int num;

  while(true) {
    puts("Enter number of record or -1: ");
    scanf("%i", &num);
    if (num < 0 || num >= n_record) break;
    fseek(fout, num*sizeof(man), SEEK_SET);
    fread(&man, sizeof(man), 1, fout);
    printf("%s%5i%10.2f\n", man.name, man.birth_year, man.pay);
    puts("Enter the new payment: "); scanf("%f", &man.pay);
    fseek(fout, num*sizeof(man), SEEK_SET);
    fwrite(&man, sizeof(man), 1, fout);
    printf("%s%5i%10.2f\n", man.name, man.birth_year, man.pay);
  }


  fclose(fout);
  puts("Correction finished.\n");

  return 0;
}
