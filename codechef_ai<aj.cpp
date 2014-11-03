#include <iostream>
#include <algorithm>

int main(int argc, char const *argv[])
{
	int t,n; int arr[100000],ans;
	cin>>t;
	while(t)
	{
		cin>>n;
		for (int i = 0; i < n; ++i)
		{
			cin>>arr[i];
		}
		sort(arr,arr+n);

		ans[0]=0;
		for (int i = 1; i <n ; ++i)
		{
			if (arr[i]>arr[i-1])
			{
				ans=ans+1;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}