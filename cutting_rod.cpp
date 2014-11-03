#include "iostream"
#include "math.h"
#include "queue"
using namespace std;

queue<int> q1;

int max_partition(int cost[],int start,int end,queue<int> q)
{
	int maximum=cost[end-start];
	int max2=maximum;
	if(start==end)
	{
		q.push(1);
		q1=q;
	   return cost[0];
	}
	for (int i = start; i < end; ++i)
	{
		if(max_partition(cost,start,i,q)+max_partition(cost,i+1,end,q)>maximum)
		{
			maximum=max_partition(cost,start,i,q)+max_partition(cost,i+1,end,q);
		}
	}
	if(max2==maximum)
		{q.push(end-start+1);}
	q1=q;
	return maximum;
}

int main(int argc, char const *argv[])
{
	int n;
	int cost[n];
	queue<int> q;
	cout<<"Enter the length of the rod"<<endl;
	cin>>n;
	cout<<"Enter the costs"<<endl;
	for (int i = 0; i < n; ++i)
		cin>>cost[i];
	cout<<"Answer = "<<max_partition(cost,0,n-1,q)<<endl;
	cout<<"q1 size = "<<q1.size()<<endl;
	while(!q1.empty())
	{
		cout<<q1.front()<<" ";
		q1.pop();
	}
	return 0;
}