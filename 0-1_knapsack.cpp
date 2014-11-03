#include"iostream"
#include<algorithm>
using namespace std;

int* weight,* value, W; int ** dp, ** sol;

int main(int argc, char const *argv[])
{
	  int n; 
	cout<<"Enter n: ";
	cin>>n;
	weight= new int[n+1];
	value= new int[n+1];
	cout<<"Enter Max weight: ";
	cin>>W;
	dp=new int *[n+1];
	sol=new int *[n+1];
	for (int i = 0; i <= n; ++i)
	{
		dp[i]=new int[W+1];
		sol[i]=new int[W+1];
	}

	cout<<"Enter weights and values: ";
	for (int i = 1; i <= n; ++i)
	{
		cin>>weight[i];
	}
	for (int i = 1; i <= n; ++i)
	{
		cin>>value[i];
	}
	for (int i = 0; i <=W; ++i)
	{
		dp[0][i]=0;
		sol[0][i]=0;
	}

	for (int i = 1; i <=n; ++i)
	{
		for (int j = 0; j <=W ; ++j)
		{
			if(j>weight[i]){
			   dp[i][j]=max(dp[i-1][j], value[i]+dp[i-1][j-weight[i]]);
			    //convert i to i-1 in dp[i][j-weight[i]] if you don't want to consider the object more than once
			   if(dp[i-1][j] > value[i]+dp[i-1][j-weight[i]])
			   {
			   	sol[i][j]=0;
			   }
			   else
			   	sol[i][j]=1;
			}
			else
			{
				dp[i][j]=dp[i-1][j];
				sol[i][j]=0;
			}
		}
	}
	cout<<"Answer = "<<dp[n][W]<<endl;

    int i=n,j=W;
	while(i>0 && j>0)
	{
		if(sol[i][j]==0)
		{
			i--;
		}
		else
		{
			cout<<"Value = "<<value[i]<<", Weight = "<<weight[i]<<endl;
			//cout<<"before j = "<<j<<endl;
			j=j-weight[i];
			//cout<<"after j = "<<j<<endl;
			i--;
		}
	}

	return 0;
}