// DP solution
// Shivendra

#include "stdio.h"
#define MAX 1000
#define total_value 25000000

int w[500],v[500],value,weight,n;

piggy(int value_so_far, int weight_so_far)
{
	//printf("value_so_far = %d  weight_so_far = %d\n",value_so_far,weight_so_far );
	int i;
	if((weight_so_far>weight)||(value_so_far>value))
	{
       return;
	}
	else if((weight_so_far==weight)&&(value_so_far<value))
    {
    	value=value_so_far;
    	return;
    }
		for ( i = 0; i <n ; ++i)
		{
		     piggy(value_so_far+v[i],weight_so_far+w[i]);
		}
}

int min(int a,int b)
{
    if(a==0)
        return b;
    if(b==0)
        return a;
    return a<b?a:b;
}

int main(int argc, char const *argv[])
{
	int i,j,s,t,p_empty,p_full,answer[MAX],coins_weight,total=0,DP[MAX][MAX]={0},duplicates,k;
	//printf("Enter number of test cases t\n");
	scanf("%d",&t);
	s=t;
    while(t>0)
    {
    	t--;
    	value=total_value; total=0;
    	//printf("Enter the empty piggybank and full piggybank's weight\n");
    	scanf("%d %d",&p_empty,&p_full);
    	//printf("Enter the number of types of coins available\n");
    	scanf("%d",&n);
    	//printf("Enter the value and weight of the coins \n");
    	for (i = 1; i <= n; ++i)
    	{
    		scanf("%d %d",&v[i],&w[i]);
    		total=total+w[i];

    	}
    	weight=p_full-p_empty;
    	//piggy(0,0);  // Used for backtracing solution, redundant here.
        for (i = 0; i <=n ; ++i)
        {
            for (j = 0; j <=weight ; ++j)
            {
                DP[i][j]=total_value;
            }
        }
        for (j=0; j <=weight ; ++j)
        {
            if(j%w[1]==0)
            {
                k=j/w[1];
                DP[1][j]= k*v[1];
            }
        }
        for (i = 2; i <=n ; ++i)
        {
            for (j = 1; j <=weight ; ++j)
            {

                if(j>=w[i])
                {
                    duplicates=j/w[i];
                    DP[i][j]=min(DP[i-1][j],v[i]+DP[i][j-w[i]]);
                    // for (k = 2; k <= duplicates; ++k)
                    // {
                    //     if(j>=(k*w[i]))
                    //        DP[i][j]=min(DP[i][j],(k*v[i])+DP[i-1][j-(k*w[i])]);
                        
                    // }

                }
                else
                {
                    DP[i][j]=DP[i-1][j];
                }
            }
        }
        // printf("   ");
        // for (i = 0; i <=weight ; ++i)
        // {
        //     printf("%d ",i);
        // }
        // printf("\n");
        // for (i = 0; i <=n ; ++i)
        // {
        //     printf("%d  ",v[i] );
        //     for (j = 0; j <=weight ; ++j)
        //     {
        //         printf("%d ",DP[i][j]);
        //     } 
        //     printf("\n");
        // }
        //printf("answer = %d\n",DP[n][weight] );

    	//answer[s-t-1]=DP[n][weight];
        if(DP[n][weight]!=total_value)
           printf("The minimum amount of money in the piggy-bank is %d.\n",DP[n][weight]);
        else
            printf("This is impossible.\n");
    }
    // for (i = 0; i < s; ++i)
    // {
    // 	if(answer[i]!=total_value)
    // 	   printf("The minimum amount of money in the piggy-bank is %d.\n",answer[i]);
    // 	else
    // 		printf("This is impossible.\n");
    // }
	return 0;
}