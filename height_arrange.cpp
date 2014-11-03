#include <iostream>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int,int> b)
{
	return a.first<b.first;
}

int main(int argc, char const *argv[])
{
	int n;
	cout<<"Enter the numver of persons\n";
	cin>>n;
	pair <int, int> p[n];
	cout<<"Enter heights and persons infront\n";
	for (int i = 0; i < n; ++i)
	{
		cin>>p[i].first;
	}
	for (int i = 0; i < n; ++i)
	{
		cin>>p[i].second;
	}
	cout<<"done\n";
	sort(p,p+n,compare);
	for (int i = 0; i < n; ++i)
	{
		cout<<p[i].first<<"  "<<p[i].second<<endl;
	}



	return 0;
}