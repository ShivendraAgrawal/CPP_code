#include<stdio.h>
#define m 100

void main()
{
    int i,t,k,j,n,total,W[m];
    printf("Enter the number of test cases\n");
	scanf("%d",&t);
	if(t>100) return;
	for(k=0;k<t;k++)
	{
		total=0;
    printf("Enter the number of workers\n");
	scanf("%d",&n);
	if(n<10000)
	{
	printf("Enter their salaries\n");
	for(i=1;i<=n;i++)
	{
		scanf("%d",&W[i]);
	}
	j=find_max(W,n);
	while(W[j]!=W[find_min(W,n)])
	{
		total++;
		for(i=1;i<=n;i++)
	     {
		     if(i!=j)
		     {
		     	W[i]++;
		     }
      	 }
		j=find_max(W,n);
	}
	printf("%d\n",total);
	}
	}
	return;
}

int find_max(int W[],int n)
{
	int max=W[1],i,j=1;
	for(i=1;i<=n;i++)
	{
		if(W[i]>max)
		{
			max=W[i];
			j=i;
		}
	}	
	return j;
}
int find_min(int W[],int n)
{
	int min=W[1],i,j=1;
	for(i=1;i<=n;i++)
	{
		if(W[i]<min)
		{
			min=W[i];
			j=i;
		}
	}	
	return j;
}
