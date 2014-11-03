#include <stdio.h>


#define x 5+2
//using namespace std;

int rec(int i)
{
	static int d=1;
	if(i >= 5)
		return i;
	printf("%d  ",d );
	d=d+i;
	printf("%d\n",d );
	i=i+i;
	 rec(d);
}

main()
{
int j=2;
printf("%d %d",++j, ++j);
 unsigned int i = -1;
 printf("%d %u", i, i);
 //unsigned int k=4294967295;
 //printf("\n%u\n",k );
 //printf("\n%d\n",sizeof(long long int)/sizeof(int) );
 printf("%d\n",rec(1) );

   int a[2][3]= { (1,2,3),(4,5,6)};
    int (*ptr)[3] = &a[0];
    printf("%d %d\n", (*ptr)[1],(*ptr)[2]);
    ptr+=1;
    printf("%d %d\n", (*ptr)[1],(*ptr)[2]);

}


