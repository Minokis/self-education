// 5_hw_var3.cpp: >?@545;O5B B>G:C 2E>40 4;O :>=A>;L=>3> ?@8;>65=8O.
// =0?8A0BL ?@>3@0<<C , :>B>@0O AG8BK205B B5:AB 87 D09;0 8 2K2>48B B>;L:> AB@>:8,
// A>45@60I85 42C7=0G=K5 G8A;0.
//  07 745AL ?@> AB@>:8, B> 2>7L<5< B5 65 CA;>28O, GB> 8 87 ?5@2KE 7040G - D09;
// A> AB@>:0<8 =0 1>;55 80 A8<2>;>2.
//
// AE>4=K5 40==K5:
// "5:AB>2K9 D09;.txt, ;8=0 AB@>:8 2 B5:AB>2>< D09;5 =5 ?@52KH05B 80 A8<2>;>2
// "5:AB =5 A>45@68B ?5@5=>A>2 A;>2
//
//  57C;LB0B: =0 M:@0= 2K2545=K AB@>:8 A 42C7=0G=K<8 G8A;0<8
// @><56CB>G=K5: 4;O E@0=5=8O 4;8=K AB@>:8 - 8<5=>20==0O :>=AB0=B0,
// ;O E@0=5=8O B5:CI59 AB@>:8 - AB@>:0 =0 81 A8<2>;
//
// ;3>@8B<:
// ?>AB@>G=> G8B0BL D09;, >4=0 ?5@5<5==0O 4;8=>9 81 =0 2A5 AB@>:8
// ?>8A: 42C7=0G=>3> G8A;0 2 AB@>:5:
// A=0G0;0 ?>8A: A8<2>;0-=><5@0, 70B5< B>, GB> A;54>< 70 =8< B>65 B0:>9,
// 70B5< B>3>, GB> MB> >B45;L=> AB>OI55 "A;>2>"
// <>6=> ?>4@CG=K<8 A@54AB20<8, 0 <>6=> A ?><>ILN ;5:A5<
// ?@8 =0E>645=88 2K25AB8 AB@>:C =0 M:@0=

#include <iostream>
#include <string.h>
#include <fstream>
#include <ctype.h>

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "Russian");
	if (argc != 2) { std::cout << "Usage: enter the file with strings.\n"; return 1; }
	std::ifstream input(argv[1]);
	if (!input) { std::cout << "Cannot open the file.\n"; return 1; }

	const int len = 81;
	char line[len], linecopy[len];
	int i;
  char delims[] = " ,.!?/<>|)(*:;\"";
  char *token;

	while (input.getline(line, len)) {
    strcpy(linecopy, line);
    // strtok creates address of the first "word" in the line
    token = strtok( line, delims );
    // deliminator after token is transformed into NULL
    while( token != NULL ) {
      if ( isdigit(*token) )  // search for digit
		     if( isdigit( *(token+1) ) )  std::cout << linecopy << std::endl;
         token = strtok( NULL, delims ); // if first arg is NULL, strtok is searching fot the next word in the same line
       }
  }


		return 0;
}
