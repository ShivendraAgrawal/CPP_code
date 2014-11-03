#include <iostream>
#include <algorithm>
using namespace std;

int *arr;

int main(int argc, char const *argv[])
{
	int n,i=0,j=1,k,count=0;
	cout<<"Input k: ";
	cin>>k;
	cout<<"Input size: ";
	cin>>n;
	arr= new int[n];
	cout<<"Input array: ";
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	sort(arr,arr+n);
	while(j<n)
	{
		if(arr[j]-arr[i]<k)
		{
			j++;
		}
		if(arr[j]-arr[i]>k)
		{
			i++;
		}
		if (arr[j]-arr[i]==k)
		{
			i++; j++; count++;
		}
	}
	cout<<"\nNo. of pairs with difference as k = "<<count<<endl;
	return 0;
}