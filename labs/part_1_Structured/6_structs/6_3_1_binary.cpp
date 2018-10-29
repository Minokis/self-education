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

  FILE *input;
  if( (input = fopen(argv[1], "r")) == NULL ) {
    puts("Cannot open the file.\n"); return 1;
  }

  FILE *output;
  if ( (output = fopen("dbase_out.bin", "wb")) == NULL ) {
    puts("Cannot open output file.\n"); return 1;
  }

  // Reading from a file
  int i;
  while( !feof(input) ) {
    int beg = 0;
    for (; beg <= l_name; beg++) {
      if ( isalpha(fgetc(input)) ) {
        fseek(input, -1, SEEK_CUR);
        if (0 != beg) beg++;
        break; }
    }
    fgets(man.name, l_name-beg, input);
    //printf("Name is %s, beg is %i\n", man.name, beg);
    if ( strlen(man.name) == 0 || beg > l_name) {puts("Found empty name!");continue;}
    man.name[0] = toupper(man.name[0]);

    // A whitespace in format string (e.g. "%i%f ") indicates that fscanf must ignore
    // all whitespace characters, including newline and possible whitespace
    // on the next line! I have a check of non-alpha in the beginning of search
    // line, so I don't need this whitespace here, it'll ruin my character-reading.

    fscanf(input, "%i%f", &man.birth_year, &man.pay);
    // Control print
    printf("%s\t%i\t%f\n", man.name, man.birth_year, man.pay);
    fwrite(&man, sizeof(man), 1, output);
  } // end of file-reading
  //
   fclose(output);
   puts("Binary file is recorded.\n");

  return 0;
}
