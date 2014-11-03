#include <stdio.h>
#define max 100

int main()
{
    int n,i,j,maximum_sum;
    int a[max][max], row[max], column[max], diagonal1=0, diagonal2=0;
    printf("Enter the size of the square matrix\n");
    scanf("%d",&n);
    printf("Enter the matrix row wise\n");
    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            scanf("%d",&a[i][j]);
        }
        row[i]=0; column[i]=0;
    }

    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < n; ++j)
        {
        	row[i]=row[i]+a[i][j];
        	column[i]=column[i]+a[j][i];
        }
         diagonal1=diagonal1+a[i][i];
         diagonal2=diagonal2+a[n-i-1][i];
    }
    maximum_sum=row[0];
    for ( i = 0; i < n; ++i)
    {
    	if(row[i]>maximum_sum)
    	{
    		maximum_sum=row[i];
    	}
    	if(column[i]>maximum_sum)
    	{
    		maximum_sum=column[i];
    	}
    }
    if(diagonal1>maximum_sum) maximum_sum=diagonal1;

    if(diagonal2>maximum_sum) maximum_sum=diagonal2;

    printf("\nMaximum sum = %d\n",maximum_sum );

    return 0;
}



