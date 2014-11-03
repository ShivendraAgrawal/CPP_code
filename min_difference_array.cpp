#include "iostream"
#include <algorithm>
using namespace std;

int *arr,*flag,mini=1000; int* sol; //Flag array is used to see which all elements are selected in that call of the function

void find_difference(int* arr,int* flag,int n,int current,int *sol)
{
	if(current==n)return;

	int sum0=0, sum1=0,entered=0;
    flag[current]=1;              //Selecting the current indexed number
    for (int i = 0; i < n; ++i)
    {
    	if(flag[i]==0)
    	{
    		sum0=sum0+arr[i];
    	}
    	else
    	{
    		sum1=sum1+arr[i];
    	}
    }
    	if(abs(sum0-sum1)<mini)
    	{
    		mini=abs(sum0-sum1);
    		for (int j = 0; j < n; ++j)
    		{
    			sol[j]=flag[j];    //Remembering the optimal solution
    		}
    	}
    find_difference(arr,flag,n,current+1,sol);  //Moving to the next index to perform the same operation (selecting or not selecting it)
    flag[current]=0;                 // Not selecting it
    for (int i = 0; i < n; ++i)
    {
    	if(flag[i]==0)
    	{
    		sum0=sum0+arr[i];
    	}
    	else
    	{
    		sum1=sum1+arr[i];
    	}
    }
    	if(abs(sum0-sum1) < mini)
    	{
    		mini=abs(sum0-sum1);
    		for (int j = 0; j < n; ++j)
    		{
    			sol[j]=flag[j];
    		}
    	}
    find_difference(arr,flag,n,current+1,sol);
}

int main(int argc, char const *argv[])
{
	int n;
	cout<<"Enter size: ";
	cin>>n;
	cout<<"Enter the numbers: "
	arr= new int[n];
	flag= new int[n];
	sol= new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
		flag[i]=0;
		sol[i]=0;
	}

	find_difference(arr,flag,n,0,sol);

	cout<<"Min = "<<mini<<endl;
	cout<<"One set is: ";
	for (int i = 0; i < n; ++i)
	{
		if (sol[i]==1)
		{
			cout<<arr[i]<<" ";
		}
	}
	cout<<"\nOther set is: ";
	for (int i = 0; i < n; ++i)
	{
		if (sol[i]==0)
		{
			cout<<arr[i]<<" ";
		}
	}
	cout<<"\n";
	return 0;
}