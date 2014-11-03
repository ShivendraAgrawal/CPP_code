#include "iostream"
#define maxx 10
using namespace std;
int number=0,flag=1;;

void find_path(int maze[maxx][maxx], int previous[maxx][maxx], int x, int y,int n)
{
	if(maze[x][y]==0||x==n||y==n)
		return;
	if(maze[x][y]==1)
		previous[x][y]=1;
	if(x==n-1&&y==n-1)
	{
		flag=0;
		previous[x][y]=1;
		for (int i = 0; i <= x; ++i)
			{
				for (int j = 0; j <= y; ++j)
				{
					cout<<previous[i][j]<<" ";
				}
			cout<<"\n";
		}
	}
	find_path(maze,previous,x+1,y,n);
	find_path(maze,previous,x,y+1,n);
}

int main(int argc, char const *argv[])
{
	int maze[maxx][maxx]={ {1, 0, 0, 0},{1, 1, 0, 1},{0, 1, 0, 0},{1, 1, 1, 1}};
	int previous[maxx][maxx],n=4;
	find_path(maze,previous,0,0,n);
	if(flag==1)
		cout<<"No path exists"<<endl;
	return 0;
}