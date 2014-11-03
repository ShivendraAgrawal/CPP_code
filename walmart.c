#include<stdio.h>
#define m 20
void main()
{
	int i,k,j,n,t;
	char string[m],so_far[m];
	printf("Enter the lenght of string\n");
	scanf("%d",&n);
	printf("Enter the string\n");
    scanf("%s",string);
	printf("Enter the lenght of the substring\n");
	scanf("%d",&k);
	t=k;
	print_next(k,0,n,string,so_far,t);
	return;
}

void print_next(int k, int i, int n, char string[], char so_far[],int t)
{
	int j,a;
	if (k==1)
	{
			for(j=i;j<n;j++)
	            {
                   so_far[t-k]=string[j];
                   for(a=0;a<t;a++)
                       printf("%c",so_far[a]);
                   printf(" ");
	            }

		return;
	}
	for(j=i;j<n;j++)
	{
        so_far[t-k]=string[j];
		print_next(k-1,j+1,n,string,so_far,t);
	}
}
