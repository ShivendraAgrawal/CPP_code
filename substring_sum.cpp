#include <iostream>
#include <map>
#define maxx 100
using namespace std;

int main(int argc, char const *argv[])
{
	int n,arr[maxx],target,sum;
	cout<<"Enter the size of the array\n";
	cin>>n;
	cout<<"Enter the numbers\n";
	for (int i = 1; i <= n; ++i)
	{
		cin>>arr[i];
	}
	cout<<"Enter the target sum\n";
	cin>>target;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n-i+1; ++j)
		{
			sum=0;
			for (int k = j; k <j+i ; ++k)
			{
				sum=sum+arr[k];
			}
			//cout<<sum<<" ";
			if(sum==target)
			{
				cout<<"( "<<j<<" - "<<j+i-1<<" )\n";
			}
		}
		//cout<<"\n";
	}
	return 0;
}