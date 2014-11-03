#include "iostream"
#include "time.h"
using namespace std;

int main(int argc, char const *argv[])
{
	int input[50];
	int dp[50][50]={0};
	int n,m,last_i=0,last_j=0;

	srand ( time(NULL) );
	printf("Enter the number of terms in the array to generate them randomly\n");
	scanf("%d",&n);
	printf("Enter the upper bound for the numbers\n");
	scanf("%d",&m);
	printf("The randomly generated array is : ");
	for (int i = 0; i < n; ++i)
	{
		input[i]=rand()%m;
		cout<<input[i]<<" ";
		dp[i][i]=1;
	}
	
	printf("\n");
	for (int i = n-1; i >0; --i)
	{
		for (int j= 0; j <i ; ++j)
		{
			if((dp[j][j+n-i-1]==1)&&(input[j+n-i]>=input[j+n-i-1]))
			{
				dp[j][j+n-i]=1;
				last_i=j;
				last_j=j+n-i;
			}
				
		}
	}
	// for (int i = 0; i < n; ++i)
	// {
	// 	for (int j = 0; j < n; ++j)
	// 	{
	// 		printf("%d  ",dp[i][j] );
	// 	}
	// 	printf("\n");
	// }
	printf("\nLongest increasing subsequence is : ");
	for (int i = last_i; i <=last_j; ++i)
	{
		cout<<input[i]<<" ";
	}
	printf("\n");

	return 0;
}