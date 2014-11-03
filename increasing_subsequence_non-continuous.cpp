// To fint the longest increasing sunsequence (Not necessarily continuous) in an array
// The order can be improved as here it is O(n^2)
// Shivendra

#include "iostream"
#include "time.h"
using namespace std;

int last[50],t=0;
int input[50];

// int longest(int k)
// {
// 	if (k==1)
// 	{
// 		return 1;
// 		last[t]=0;
// 		t++;
// 	}
// 	if(input[k]>last[t])
// 	{
// 		last[t]=input[k];
// 		t++;
// 		return longest(k-1)+1;
// 	}
// 	else return longest(k-1);
// }


int main(int argc, char const *argv[])
{
	int dp[50];
	int n,m,last_i=0,last_j=0,max=0,index,answer[n],max_fix,prev[n],k;

	srand ( time(NULL) );
	printf("Enter the number of terms in the array to generate them randomly\n");
	scanf("%d",&n);
	printf("Enter the upper bound for the value of numbers\n");
	scanf("%d",&m);
	printf("The randomly generated array is : ");
	for (int i = 0; i < n; ++i)
	{
		input[i]=rand()%m;
		cout<<input[i]<<" ";
			dp[i]=1;
		prev[i]=-1;
	}

	
	
	printf("\n");
    
    for (int i = 1; i < n; ++i)
    {
    	for (int j = i-1; j >= 0; --j)
    	{
    		if((dp[j]+1>dp[i])&&(input[i]>=input[j]))
    		{
    			dp[i]=dp[j]+1;
    			prev[i]=j;
    		}
    	}
    	if (dp[i]>max)
    		{max=dp[i];index=i;}
    }

    for (int i = 0; i < n; ++i)
    {
    	printf("longest subsequence ending with %d = %d and previous = %d\n",input[i],dp[i],input[prev[i]]);
    }
    printf("Prev: \n");
    for (int i = 0; i < n; ++i)
    {
    	printf("prev[%d] = %d  -> prev[%d] = %d\n",input[i],input[prev[i]],i,prev[i]);
    }
    printf("Maximum length = %d and ending at %d\n",max,input[index] );
    max_fix=max;
   

	 printf("\nLongest increasing subsequence is : ");
	 k=index;
	 for (int i = max_fix-1; i >=0; --i)
	 {
	 	printf("%d %d\n",input[k],k );
	 	max=prev[k];
	 	k=max;
	 }
	// for (int i = 0; i <=t; ++i)
	// {
	// 	cout<<input[last[i]]<<" ";
	// }
	printf("\n\n");

	return 0;
}