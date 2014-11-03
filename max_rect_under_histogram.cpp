#include "iostream"
int main(int argc, char const *argv[])
{
	int n;
	cout<<"Enter the number of terms : ";
	cin>>n;
	int arr[n];
	cout<<"Enter the array : ";
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}

	
	return 0;
}