#include <iostream>
//#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
	int t,n; 
	long long int arr;
	int ans,previous;
	cin>>t;
	while(t>0)
	{
		cin>>n;
		for (int i = 0; i < n; ++i)
		{
			cin>>arr;
		}
		//sort(arr,arr+n);
		ans=(n*(n-1))/2;
		cout<<ans<<endl;
		t--;
	}
	return 0;
}