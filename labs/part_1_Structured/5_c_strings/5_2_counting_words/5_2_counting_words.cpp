// Подсчет количества вхождений слова в текст
// Длина строки в текстовом файле не превышает 80 символов
// Текст не содержит переносов слов

// Исходные данные:
// Текстовый файл.txt, Длина строки в текстовом файле не превышает 80 символов
// Текст не содержит переносов слов
// Слово, вводимое с клавиатуры, тоже 81 символ в строке.
// Результат: выведено на экран количество повторов или сообщение об отсутствии
// слова в тексте
// Промежуточные: для хранения длины строки - именованная константа,
// для хранения фактического количества символов в слове - переменную целого типа
// Для счетчика - переменную целого типа
//
// Алгоритм:
// построчно читать файл, одна переменная длиной 81 на все строки
// поиск слова в строке
//   - Слово отделено от любого другого несколькими символами: знаком пунктуации,
//   пробелом. Может начинаться с начала строки и заканчивать строку. Поэтому при
//   обнаружении совпадения искомых символов требуется проверить - а слово ли это.
//   - Слово может встречаться в одной строке несколько раз - нужен цикл поиска
//   по каждой строке
// увеличение счетчика
// после цикла - вывести счетчик на экран
#include <iostream>
#include <string.h>
#include <fstream>

int main(int argc, char *argv[])
{
  if(argc != 2){std::cout<<"Usage: enter the file with strings.\n";return 1;}
  std::ifstream input(argv[1]);
  if(!input){std::cout<<"Cannot open the file.\n";return 1;}

  const int len = 81;
  char line[len], word[len];
  char delims[] = " ,.!?/<>|)(*:;\"";

  std::cout << "Enter the word: "; std::cin >> word;

  char *token;
  int count = 0;
  while(input.getline(line, len)) {
    // strtok creates address of the first "word" in the line
    token = strtok( line, delims );
    //std::cout << "Token: " << token << std::endl;
    // deliminator after token is transformed into NULL
    while( token != NULL ) {
      if( strcmp (token, word) == 0 ) count++;
      token = strtok( NULL, delims ); // if first arg is NULL, strtok is searching fot the next word in the same line
    }
  }
  std::cout << "Number of matches: " << count << std::endl;
  return 0;
}
