/* SHIVENDRA AGRAWAL
   09MA2019   */

#include<stdio.h>
#define n 5

typedef struct nodes
{
  int key;
  int status;
} node;

node vertex[n+1];

int graph[n+1][n+1],i,j,k=1,r,source,min1=999,min2=999,index1,index2;


main()
{
    r=n;
    printf("\nThe number of nodes in the directed graph is %d\n",r);
    printf("\nEnter 999 for no edge between 2 nodes\n");
    printf("\nEnter 0  for same nodes ex- (2,2) weight=0\n");
    printf("\nEnter the weight between\n");
      

    for(i=1;i<=r;i++)
        {
       for(j=1;j<=r;j++)
         {
           printf("\n(%d, %d) ",i,j);
           scanf("%d",&graph[i][j]);
	     }
	      vertex[i].status=i;
	    }

    printf("\nEnter the source vertex from 1 to %d\n",r);
    scanf("%d",&source);
      
    vertex[source].key=0;
    vertex[source].status=-1;
    
    while(k<=r)
    {
    	if(k!=source)
    	{
    		vertex[k].key=graph[source][k];
    		if (vertex[k].key<min1)
    		{
			  min1=vertex[k].key;
			  index1=k;
    		}	
    	}
    	k++;
    }
    vertex[index1].status=-1;
   
   for(k=1;k<=r;k++)
  	{
    
      for(i=1;i<=r;i++)
      {
    	  for(j=1;j<=r;j++)
    	  {
    		  if((vertex[j].status==-1)&&(vertex[i].status!=-1))
    		  {
    		  	  if(vertex[i].key>=(vertex[j].key+graph[j][i]))
    		      {
				     vertex[i].key=vertex[j].key+graph[j][i];
				      if(vertex[i].key<min2)
				     {
				       min2=vertex[i].key;
				       index2=i;
				     }
    		      }
    		  }
    	  }
      }
      vertex[index2].status=-1;
      min2=999;
  	}
  	 
    printf("\nShortest distance from source %d to\n",source);
   	for(i=1;i<=r;i++)
   	{
   		printf("%d = %d\n",i,vertex[i].key);
   	}
    
}


/* TEST CASE

********************************************************************

The number of nodes in the directed graph is 5

Enter 999 for no edge between 2 nodes

Enter 0  for same nodes ex- (2,2) weight=0

Enter the weight between

(1, 1) 0

(1, 2) 10

(1, 3) 999

(1, 4) 999

(1, 5) 5

(2, 1) 999

(2, 2) 0

(2, 3) 1

(2, 4) 999

(2, 5) 2

(3, 1) 999

(3, 2) 999

(3, 3) 0

(3, 4) 4

(3, 5) 999

(4, 1) 7

(4, 2) 999

(4, 3) 6

(4, 4) 0

(4, 5) 999

(5, 1) 999

(5, 2) 3

(5, 3) 9

(5, 4) 2

(5, 5) 0

Enter the source vertex from 1 to 5
1

Shortest distance from source 1 to
1 = 0
2 = 8
3 = 9
4 = 7
5 = 5

*/
