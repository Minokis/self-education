#include <fstream>
#include <iostream>
#include <cstring>

int main(int argc, char *argv[])
 { 
 
  if(argc != 2) { std::cout << "Usage: enter the file with strings.\n"; return 1; }
  std::ifstream input(argv[1]);
  if(!input) { std::cout << "Cannot open the file.\n"; return 1; }

  const int str_len = 81;
   char current_str[str_len];
   char substr[str_len];
  std::cout << "Enter the substring: "; s t d : : c i n  >>  s u b s t r  ; 
    
  while(input.getline(current_str, str_len)) {
    i f   ( s t r s t r ( s t r ,   s u b s t r ) )  { 
      s t d : : c o u t   < <   " Y e s ,   i t ' s   h e r e \ n " ; 
      return 0;
    }
  } ; 
  std::cout << "Substring is not found.\n"; 
 
   r e t u r n   0 ; 
 
 
 } 
 
 
 
 
