#include <iostream>
#include <math.h>
using namespace std ;

void f(char * x)
{
  x++;
  *x = 'a';
}

int main ()
{
	char * stri = "hello";
  f(stri);
  cout << stri;
  return 0;
}