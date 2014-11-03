#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define max_n 100
#define max_bound 10000
int main(int argc, char const *argv[])
{
	int n,i,j;
	int profit[max_n],M,T=0;
	int A[max_n][max_bound];
	int min=10000,j_found;
	bool selected_house[max_n];
	printf("\nEnter number of houses (n) : ");
	scanf("%d",&n);
	printf("Enter profit bound (M)     : ");
	scanf("%d",&M);
	printf("Profits are ");
	for (i = 0; i < n; ++i)
	{
		profit[i]=(rand()%M)+1;
		T=T+profit[i];
		printf("%d  ",profit[i] );
		A[i][0]=0;
		A[0][i]=0;
	}
	A[0][0]=1;
	A[n][0]=0;
	for ( i = 1; i <= n; ++i)
	{
		for (j = 1; j <= T; ++j)
		{
			if(A[i-1][j]!=0)
			{
				A[i][j]=1;
			}
			if(j>=profit[i-1])
			{
				if(A[i-1][j-profit[i-1]]!=0)
			       {
				       A[i][j]=2;
			       }
			}
			// printf("%d ",A[i-1][j-profit[i-1]] );
		}
	}
	for (j = 0; j < T/2; ++j)
	{
		if(A[n][j]!=0)
		{
			if(abs(3*j-T)<min)
			{
				j_found=j;
				min=abs(3*j-T);
				//printf("min = %d\n", min);
			}
		}
		
	}
	//printf("\nj_found = %d and T = %d\n",j_found,T );

	i=n;
	j=j_found;
	while(i>0)
	{
		if(A[i][j]==2)
		{
			selected_house[i]=true;
		    j=j-profit[i-1];
			i=i-1;
		}
		if(A[i][j]==1)
		{
			selected_house[i]=false;
			i=i-1;
		}
	}
	printf("\nProfit for first son  : %d\n",T-j_found);
	printf("Profit for second son  : %d\n",j_found);
	printf("Imbalance abs(S1 - 2*S2) : %d\n", abs((T-j_found)-(2*j_found)));
	printf("First son gets houses  ");
	for ( i = 1; i <= n; ++i)
	{
		if(selected_house[i]==false)
			printf("%d ",i);
	}
	printf("\nSecond son gets houses  ");
	for ( i = 1; i <= n; ++i)
	{
		if(selected_house[i]==true)
			printf("%d ",i);
	}

	// for ( i = 0; i <= n; ++i)
	// {
	// 	printf("\n%d  ",i );
	// 	for (j = 0; j <= T; ++j)
	// 	{
	// 		printf("%d ",A[i][j]);
	// 	}
	// }
	printf("\n");
	return 0;
}