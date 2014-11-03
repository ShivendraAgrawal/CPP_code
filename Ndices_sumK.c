#include "stdio.h"
#define size 120

int main(int argc, char const *argv[])
{
 while(1)
{
	float dice[size][size]={0};
	int n,k,i,j,t,l;
	float sum=0;
	printf("Input the number of dices and the sum\n");
	scanf("%d",&n);
	scanf("%d",&k);
	printf("\n");

	dice[0][0]=1;
	for ( i = 1; i < size; ++i)
	{
		dice[0][i]=0;
		dice[i][0]=0;
	}

		printf("K  ");
				for ( j = 1; j <=n*6 ; ++j)
		{
			if(j<10){
			printf("%d      ",j );}
			else{
				printf("%d     ",j );
			}
		}

	for (i = 1; i <=n ; ++i)
	{
		printf("\n%d  ",i );


		for ( j = 1; j <=6*n ; ++j)
		{
			t=j-6;
			if (t<0)
			{
				t=0;
			}
			for ( l = t; l <j ; ++l)
			{
				sum=sum+dice[i-1][l];
			}
			dice[i][j]=sum/6;
			sum=0;
			printf("%0.3f  ", dice[i][j]);

		}
	}
	sum=0;
	for (i = k; i <= n*6; ++i)
	{
		sum=sum+dice[n][i];
	}
	printf("\n\nP(%d,%d) = %f\n\n",n,k,sum);

}
	return 0;
}