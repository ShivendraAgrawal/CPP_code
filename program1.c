#include <stdio.h>
int main(int argc, char const *argv[])
{
	int num, sum=0;
	printf("Enter the numbers\n");
	scanf("%d",&num);
	while(num!=-1)
	{
		sum=sum+num;
		if(num>100 || num<0)
		{
			printf("Input out of range\n");
			return 0;
		}

		scanf("%d",&num);
	}
	printf("sum=%d\n",sum);

	return 0;
}