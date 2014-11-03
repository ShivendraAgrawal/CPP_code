# include <iostream>
# include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
	int arr[]={-8,-6,0,-4,2,4,1,-10},n,j=1;
	n=sizeof(arr)/sizeof(arr[0]);
	//cout<<n;
	sort(arr,arr+n);
	for (int i = 0; i < n; ++i)
	{
		if(arr[i]>0)
		{
			if(arr[i]==j)
			{
				j++;
			}
			else
			{
				cout<<j;
				break;
			}
		}
	}
	

	return 0;
}