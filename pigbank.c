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

int main(int argc, char const *argv[])
{
	int i,j,s,t,p_empty,p_full,answer[MAX],coins_weight,total=0;
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
    	for (i = 0; i < n; ++i)
    	{
    		scanf("%d %d",&v[i],&w[i]);
    		total=total+w[i];

    	}
    	weight=p_full-p_empty;
    	piggy(0,0);
    	answer[s-t-1]=value;
    }
    for (i = 0; i < s; ++i)
    {
    	if(answer[i]!=total_value)
    	   printf("The minimum amount of money in the piggy-bank is %d.\n",answer[i]);
    	else
    		printf("This is impossible.\n");
    }
	return 0;
}