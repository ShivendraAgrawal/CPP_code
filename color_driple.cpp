#include <iostream>
#define maxx 100
using namespace std;

int main(int argc, char const *argv[])
{
	char A[maxx][maxx];
	int m,n,row,column,lx,ly,rx,ry,ux,uy,dx,dy,count=1,start,flagl=0,flagr=0;
	cout<<"enter m\n";
	cin>>m;
	cout<<"enter n\n";
	cin>>n;
	cout<<"Enter matrix\n";
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin>>A[i][j];
		}
	}

	cout<<"enter position: \n";
	cin>>row; cin>>column;
	start=row;
	ly=column-1; lx=row;
	rx=lx; ry=ly+2;
	ux=row-1; uy=column;
	dx=ux+2; dy=uy;
{
	if(lx>-1&&ly>-1){
	if(A[lx][ly]==A[row][column])
	{
		A[lx][ly]='0';
		flagl++;
	}}
	if(rx>-1&&ry>-1){
	if(A[rx][ry]==A[row][column])
	{
		A[rx][ry]='0';
		flagr++;
	}}
	if(ux>-1&&uy>-1){
	if(A[ux][uy]==A[row][column])
	{
		A[ux][uy]='0';
		count++;
	}}
	if(dx>-1&&dy>-1){
	if(A[dx][dy]==A[row][column])
	{
		A[dx][dy]='0';
		count++;
		start=dx;
	}}
}
	A[row][column]='0';
	if(lx>-1&&ly>-1){
		for (int i = lx; i >0; --i)
		{
			A[i][ly]=A[i-1][ly];
		}
		if(flagl){A[0][ly]='0';}}
	

		if(rx>-1&&ry>-1){
		for (int i = rx; i >0; --i)
		{
			A[i][ry]=A[i-1][ry];
		}
			if(flagr){A[0][ry]='0';}}

		if(dx>-1&&dy>-1)
		{
			for (int i = start; i >count-1; --i)
			{
				A[i][column]=A[i-count][column];
			}
		}

	for (int i = 0; i < count; ++i)
	{
		A[i][column]='0';
	}

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout<<A[i][j]<<" ";
		}
		cout<<"\n";
	}



	return 0;
}