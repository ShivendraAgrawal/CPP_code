# include <iostream>
# include <algorithm>
# include <math.h>
using namespace std;

int arr[1000000],sum=0,num=0;

int digit(int n)
{
	if(n==0)return 0;
	if(n==1)return 1;
	return(10*digit(n-1)+pow(10,n-1));
}

void main_digit(int size)
{
	if(size==0){
		return;
	}
	if(arr[size-1]==0)
	{
		main_digit(size-1);
	}
	else
	{
		if(arr[size-1]==1)
		{
			sum=sum+digit(size-1);
			for (int i = size-2; i >=0 ; --i)
			{
				num=num*10+arr[i];
			}
			sum=sum+num+1;
			num=0;
		}
	     else
	    {sum=sum+(arr[size-1]*digit(size-1))+pow(10,size-1);}
		main_digit(size-1);
	}
}
int countones(int k) {
    int size=0;
while(k>0)
	{
		arr[size]=k%10;
		k=k/10;
		size++;
	}
	main_digit(size);
    return sum;
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	cout<<countones(n);
	return 0;
}
