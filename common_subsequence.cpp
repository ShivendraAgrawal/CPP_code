#include <iostream>
#include <string>
#define max 20
using namespace std;

int maximum(int a,int b)
{
	return (a>b)?a:b;
}

int main(int argc, char const *argv[])
{
	string a,b,d="";
	int n,m;
	int dp[max][max],x_prev[max][max]={0},y_prev[max][max]={0};
    cout<<"Enter String 1"<<endl;
    getline(cin,a);
    cout<<"Enter String 2"<<endl;
    getline(cin,b);
    n=a.length(); m=b.length();
    if(a[0]==b[0])
    	{dp[0][0]=1;}
    else
    	dp[0][0]=0;

    for (int i = 1; i < n; ++i)
    {
    	if(a[i]==b[0]||dp[i-1][0]==1)
    	{
    		dp[i][0]=1;
    	}
    	else
    		dp[i][0]=0;
    }
    for (int i = 1; i < m; ++i)
    {
    	if(b[i]==a[0]||dp[0][i-1]==1)
    	{
    		dp[0][i]=1;
    	}
    	else
    		dp[0][i]=0;
    }
    for (int i = 1; i < n; ++i)
    {
    	for (int j = 1; j < m; ++j)
    	{
    		if(b[j]==a[i])
    		{
    			dp[i][j]=1+dp[i-1][j-1];
    			x_prev[i][j]=i-1;
    			y_prev[i][j]=j-1;
    		}
    		else
    		{
    			dp[i][j]=maximum(dp[i-1][j],dp[i][j-1]);
    			if(dp[i-1][j]>dp[i][j-1])
    			{
    				x_prev[i][j]=i-1;
    			    y_prev[i][j]=j;
    			}
    			else
    			{
    				x_prev[i][j]=i;
    			    y_prev[i][j]=j-1;
    			}
    		}
    	}
    }
    // for (int i = 0; i < n; ++i)
    // {
    // 	for (int j = 0; j < m; ++j)
    // 	{
    // 		cout<<dp[i][j]<<" ";
    // 	}
    // 	cout<<"\n";
    // }
    // printf("\n");

    // for (int i = 0; i < n; ++i)
    // {
    // 	for (int j = 0; j < m; ++j)
    // 	{
    // 		cout<<x_prev[i][j]<<" ";
    // 	}
    // 	cout<<"\n";
    // }
    // printf("\n");
    // for (int i = 0; i < n; ++i)
    // {
    // 	for (int j = 0; j < m; ++j)
    // 	{
    // 		cout<<y_prev[i][j]<<" ";
    // 	}
    // 	cout<<"\n";
    // }

    int length= dp[n-1][m-1];
    cout<<"Length = "<<length<<endl;
    while (m>1&&n>1)
    {
    	if (x_prev[n-1][m-1]==n-2&&y_prev[n-1][m-1]==m-2)
    	{
    		d.append(a.substr(n-1,1));
    		m=m-1;n=n-1;
    	}
    	else 
    	{
    		m=m-(m-1-y_prev[n-1][m-1]);
    		n=n-(n-1-x_prev[n-1][m-1]);
    	}
    }
    cout<<"The common subsequence is : ";
    cout<<d<<endl;
    



	return 0;
}