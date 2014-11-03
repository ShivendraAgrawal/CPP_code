#include <stdio.h>
#include <string.h>

int main ()
{
  char str[] = "almost every programmer should know memset!";
  char stri[]="";
  memset (stri,'-',6);
  puts (stri);
  printf("%d\n",sizeof(char));
  return 0;
}