#include <iostream>
#include <map>
using namespace std;

int main(int argc, char const *argv[])
{
	long long int n,copy_n;
	int a[20],arr[20],k=0,size=0,product;
	map<int, int> mymap;
	map<int, int>::iterator it;
	cout<<"Enter the number to check for its colorfulness\n";
	cin>>n;
	copy_n=n;
	while(n>0)
	{
		a[k]=n%10;
		size++;
		k++;
		n=n/10;
	}
	n=copy_n;
	for (int i = 0; i < size; ++i)
	{
		arr[i]=a[size-1-i];
	}
	//cout<<"n = "<<copy_n<<", size = "<<size<<"\n";
	// for (int i = 0; i < size; ++i)
	// {
	// 	cout<<arr[i]<<" ";
	// }
	// cout<<"\n";
	for (int i = 1; i <= size; ++i)
	{
		for (int j = 0; j <=size-i ; ++j)
		{
			product=1;
			for (int k = j; k < j+i; ++k)
			{
				product=product*arr[k];
			}
			cout<<product<<", ";
			it=mymap.find(product);
			if(it==mymap.end())
			{
				mymap[product]=1;
			}
			else
			{
				cout<<"\nNot colorful\n";
				return 0;
			}
		}
	}
	cout<<"\nColorful\n";
	return 0;
}