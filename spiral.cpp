#include <iostream>
#include <map>
#define maxx 100
using namespace std;

int main(int argc, char const *argv[])
{
	int n,mat[maxx][maxx],d=1,limit,go,i,flag=0,t,size;
	cout<<"Enter size n for a nxn matrix\n";
	cin>>n;
	go=n;
	size=n;
	limit=n*n;
	while(limit>0)
	{
		if(size==1){mat[(n/2)+1][(n/2)+1]=limit;limit--;}
		if(d==1)
		{
			i=size;
			t=1;
			if(flag!=1){
			while(i>1)
			{
				mat[n-go+1][n-go+t]=limit;
				i--;
				t++;
				cout<<limit<<" ";
				limit--;
				if(limit<=0){flag=1; break;}
			}
			d=2;}
		}
		if(d==2)
		{
			i=size;
			t=1;
			if(flag!=1){
			while(i>1)
			{
				mat[n-go+t][go]=limit;
				i--;
				t++;
				cout<<limit<<" ";
				limit--;
				if(limit<=0){flag=1; break;}
			}
			d=3;}
		}
		if(d==3)
		{
			i=size;
			t=go;
			if(flag!=1){
			while(i>1)
			{
				mat[go][t]=limit;
				i--;
				t--;
				cout<<limit<<" ";
				limit--;
				if(limit<=0){flag=1; break;}
			}
			d=4;}
		}
		if(d==4)
		{
			i=size;
			t=go;
			if(flag!=1){
			while(i>1)
			{
				mat[t][n-go+1]=limit;
				i--;
				t--;
				cout<<limit<<" ";
				limit--;
				if(limit<=0){flag=1; break;}
			}
			d=1;}
			go--;
			size=size-2;
		}
	}

cout<<"\n\n";
	for (int i = 1; i <=n ; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cout<<mat[i][j]<<"  ";
		}
		cout<<"\n";
	}


	return 0;
}