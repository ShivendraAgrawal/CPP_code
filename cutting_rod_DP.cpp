#include "iostream"
#include "math.h"
#include "utility"
using namespace std;
#define maxx 20

void print_cutting(pair<int,int> previous[maxx],int i)
{
	if(previous[i].second==0)
	{
		cout<<previous[i].first<<"  ";
		return;
	}
	print_cutting(previous,previous[i].first);
	print_cutting(previous,previous[i].second);
}

int main(int argc, char const *argv[])
{
	int n,maximum,x,y;
	int cost[n+1],rod[n+1];
	pair<int,int> previous[maxx];
	cout<<"Enter the length of the rod"<<endl;
	cin>>n;
	cout<<"Enter the costs"<<endl;
	for (int i = 1; i <= n; ++i)
		cin>>cost[i];

	rod[1]=cost[1];
	previous[1].first=1;
	previous[1].second=0;
	for (int i = 2; i <= n; ++i)
	{
		maximum=cost[i];
		for (int j = 1; j <i ; ++j)
		{
			if (rod[j]+rod[i-j]>maximum)
			{
				maximum=rod[j]+rod[i-j];
				x=j;y=i-j;
			}
		}
		rod[i]=maximum;
		if(maximum!=cost[i])
		{
			previous[i].first=x;
			previous[i].second=y;
		}
		else{
			previous[i].first=i;
			previous[i].second=0;
		}
	}
	cout<<"Answer = "<<rod[n]<<endl;
	cout<<"And the cuts are : ";
	print_cutting(previous,n);


	return 0;
}