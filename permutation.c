#include<stdio.h>
#define m 10

int total=0; //We could avoid this global variable by passing in the updated value everytime
void main()
{
	int i,k=0,j,n,t=0;
	char string[m],so_far[m]="";
	printf("Enter the lenght of string\n");
	scanf("%d",&n);
	printf("Enter the string\n");
    scanf("%s",string);
 	printf("\nAll the permutations are:\n\n");   
	permutate(string,n,so_far,t);
	printf("\nTotal no. of permutations = %d\n",total);
	return;
}

void permutate(char string[],int n,char so_far[],int t)
{
	int i,j,k,l;
	char remaining[m];
	if (n==1)
	{
            so_far[t]=string[0];
            for(l=0;l<=t;l++)
               {printf("%c",so_far[l]);}
            total++;
		    printf("\n");
		    	return;
	}
	t++;

	for(j=0;j<n;j++)
	{
		k=0;
		for(i=0;i<n;i++)
	        {	
                if(i!=j)
                   {
				      remaining[k]=string[i];
				      k++;
                   }
		    }
            so_far[t-1]=string[j];

           // printf("\n%d\n\n",t);//Just for studying how the recursion was going
		    permutate(remaining,n-1,so_far,t);
	}
	return;
}
