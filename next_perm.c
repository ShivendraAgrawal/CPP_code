#include<stdio.h>
#define m 20
void main()
{
	int i,n;
	int arr[m];
	printf("Enter the number of digits\n");
	scanf("%d",&n);
	printf("Enter the array of digits\n");
    for(i=0;i<n;i++)
       scanf("%d",&arr[i]);
 	printf("\nNext permutation is:\n\n");   
	next_perm(arr,n);
    for(i=0;i<n;i++)
       printf("%d ",arr[i]);
	return;
}

void next_perm(int arr[],int n)
{
	int index=-1,swap,temp;
	int i,j,k;
    for(i=n-1;i>0;i--)
    {
    	for(j=i-1;j>=0;j--)
    	{
    		if(arr[j]<arr[i])
    		{
    			if(j>index)
    			{
    				index=j;
					swap=i;
    			}
    		}
    	}
    }
    temp=arr[index];
    arr[index]=arr[swap];
    arr[swap]=temp;
	return;
}
