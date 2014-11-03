#include <iostream>
#include <queue>
using namespace std;

int main(int argc, char const *argv[])
{
	int a=10, b, c;

     c = a++ + a++ ;

     b = a++ +  ++a ;

    printf("%d,%d,%d,%d,%d",c,b,a,a++,a);
	return 0;
}
