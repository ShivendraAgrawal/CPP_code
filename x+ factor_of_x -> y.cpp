#include "iostream"
#include <algorithm>
# include <stack>
# include <math.h>
using namespace std;

stack <int> sol;
int mini=1000;

void check(int x,int y,stack<int> q)
{

	if(x>y)return;
	if(y==x)
	{
        if(q.size()<mini)
        {
        	mini=q.size();
        	sol=q;
        	cout<<"Possible\n";
        }
		
		return;
	}
	for (int i = 2; i < x; ++i)
	{
		cout<<"i = "<<i<<" ";	cout<<"x = "<<x<<" ";
		if(x%i==0)
		{
			q.push(x+i);
			check(x+i,y,q);
			q.pop();
		}
	}
}

int main(int argc, char const *argv[])
{
	int x,y;
	stack<int> q;
	cin>>x; cin>>y;
	q.push(x);
	check(x,y,q);

	while(!sol.empty())
	{
		cout<<sol.top()<<"-> ";
		sol.pop();
	}

	return 0;
}