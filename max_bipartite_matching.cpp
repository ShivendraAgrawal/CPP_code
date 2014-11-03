//Shivendra
//Solutionm works for directed graph
//For undirected graphs only fill ones and zeros for the upper triangle
//leave the lower triangle entirely zeros and not symmetrically same (for the directed graph to work on undirected too)
//Sample example "graph1" is given here (undirected) - http://www.wikihow.com/Use-a-Bipartite-Graph-to-Find-the-Maximal-Matching
//Sample example "graph" is given here (directed) - http://www.geeksforgeeks.org/maximum-bipartite-matching/

#include "iostream"
#include "queue"
#include "utility"
#define maxxx 20
using namespace std;

int max(int a, int b)
{
	return (a>b)?a:b;
}

queue< pair<int,int> > q;
pair<int,int> p;
pair<int,int> previous[maxxx][maxxx];

int max_bipartite(int g[maxxx][maxxx], int count, int n, queue< pair<int,int> > q1)
{
	int not_include[maxxx][maxxx],include[maxxx][maxxx],flag=1,count_include=count;
	int x,y;

	if (count<1)
		{return 0;}
	//Not including the edge
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			not_include[i][j]=g[i][j];
			include[i][j]=g[i][j];
			if((g[i][j]==1)&&(flag==1))
			{
				not_include[i][j]=0;
				include[i][j]=0;
				flag--;
				x=i;y=j;
			}
		}
	}
	//Including the edge x---y
    for (int k = 0; k <n ; ++k)
    	{
    		if(k!=y && include[x][k]==1)
    			{
    				include[x][k]=0;
    				count_include--;
    			}
    	}
    for (int k = 0; k <n ; ++k)
    	{
    		if(k!=x && include[k][y]==1)
    			{
    				include[k][y]=0;
    				count_include--;
    			}
    	}
    	if(max_bipartite(not_include,count-1,n,q1)> 1+max_bipartite(include,count_include-1,n,q1))
    	{
           return max_bipartite(not_include,count-1,n,q1);
    	}
    	else
    	{
    		p=make_pair(x,y);
    		q1.push(p);
    		q=q1; //The solution
    		return 1+max_bipartite(include,count_include-1,n,q1);
    	}

}

int main(int argc, char const *argv[])
{
	int graph[maxxx][maxxx]={  {0, 1, 1, 0, 0, 0},
                        {1, 0, 0, 1, 0, 0},
                        {0, 0, 1, 0, 0, 0},
                        {0, 0, 1, 1, 0, 0},
                        {0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 1}
                         };
    int graph1[maxxx][maxxx]={{0,0,0,0,0,1,1,0,1,0},
                              {0,0,0,0,0,1,0,0,0,0},
                              {0,0,0,0,0,0,1,1,0,0},
                              {0,0,0,0,0,0,0,0,1,1},
                              {0,0,0,0,0,0,0,1,0,0},
                              {0,0,0,0,0,0,0,0,0,0},
                              {0,0,0,0,0,0,0,0,0,0},
                              {0,0,0,0,0,0,0,0,0,0},
                              {0,0,0,0,0,0,0,0,0,0},
                              {0,0,0,0,0,0,0,0,0,0}};
    int g[maxxx][maxxx]={0},count=0,ans;
    int n=10;        // Change the size here (No.of vertices)
    queue< pair<int,int> > q1;

    for (int i = 0; i < n; ++i)
    {
    	for (int j = 0; j < n; ++j)
    	{
    		g[i][j]=0;
    		if(graph1[i][j]==1) // Change graph to be input here. It is graph1 by default.
    		{
    			g[i][j]=1;
    			count++;
    		}
    		//cout<<g[i][j]<<" ";
    	}
    	//cout<<"\n";
    }

    ans=max_bipartite(g,count,n,q1); 
    cout<<"Maximum bipartite matching is : "<<ans<<endl;
    cout<<"And the edges are : "<<endl;
    while(!q.empty())
    {
    	p=q.front();
    	printf("%c *------------* %d\n",65+p.first, p.second-4);
    	q.pop();
    }

	return 0;
}