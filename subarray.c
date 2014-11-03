#include<stdio.h>
#define m 20
main()
{
	int i,k,t,n,array[m],left[m],right[m],start,stop,j,max=0,sum=0,l,r;
	printf("Enter the number of terms in the array\n");
	scanf("%d",&n);
	printf("Enter the array\n");
	for(i=0;i<n;i++)
		scanf("%d",&array[i]);
	
	for(i=0;i<n-1;i++)
	{
		l=i;r=i+1;
		left[l]=array[l];
		right[r]=array[r];
		while(l>0)
		{
			l--;
			left[l]=left[l+1]+array[l];
		}
		while(r<n-1)
		{
			r++;
			right[r]=right[r-1]+array[r];
		}
		for(k=0;k<=i;k++)
		{
			for(t=n-1;t>i;t--)
			{
				if(left[k]==right[t])
				{
					if((t-k)>=max)
					{
						start=k;
						stop=t;
						j=i;
						max=t-k;
					}
						printf("\n**************************************************\n");
						printf("left_sum=%d, right_sum=%d, start=%d, stop=%d, j=%d",left[k],right[t],k+1,t+1,i+1);
						printf("\n**************************************************\n");
				}
			}
		}
	}
	if(max!=0)
	{
	printf("\nArray is :  ");
	for(i=0;i<n;i++)
	{
		printf("%d,",array[i]);
	}
	printf("\nSubarray is :  ");
	for(i=start;i<=stop;i++)
	{
		printf("%d,",array[i]);
	}
	printf("\n\nand the two portions are: ");
	for(i=start;i<=j;i++)
	{
		printf("%d",array[i]);
		if(i!=j)
		   printf("+");
		sum=sum+array[i];
	}
	printf("=%d",sum);
	printf(" and ");
	sum=0;
	for(i=j+1;i<=stop;i++)
	{
		printf("%d",array[i]);
		if(i!=stop)
		   printf("+");
		sum=sum+array[i];
	}
	printf("=%d\n\n",sum);
	}
}
