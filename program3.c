#include <stdio.h>

int digitalroot(int x)
{   
	int y=0;
	if(x<10)
    return x;

    while(x>0)
    {
    	y=y+x%10;
        x=x/10;
    }
return digitalroot(y);
}

int main()
{
	int x;
	printf("Enter the integer\n");
    scanf("%d",&x);
    printf("Digital root  = %d\n",digitalroot(x));
    return 0;
}