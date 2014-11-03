// http://www.codechef.com/AUG13/problems/LELEMON
// Shivendra
// easy

#include "stdio.h"
int main(int argc, char const *argv[])
{
	int lemonade[100][100];
	int m_array[10000],t_array[10];
	int n,m,i,j,k,t,room;
	int total=0,max=-2,delete;
	scanf("%d",&t);
	for(k=0;k<t;k++)
	{
	//printf("Enter n and m\n");
	scanf("%d %d",&n,&m);

	//printf("Enter %d number of visited rooms in order\n",m );

	for ( i = 0; i < m; i++)
		scanf("%d",&m_array[i]);

	//printf("Enter the number of bottles and their volumes\n");

	for (i = 0; i < n; i++)
	{
		scanf("%d",&lemonade[i][0]);
		for (j = 1; j <=lemonade[i][0]; j++)
		{
			scanf("%d",&lemonade[i][j]);
		}
	}

	for ( i = 0; i < m; i++)
	{
		room=m_array[i];
		//printf("The room visited = %d\n",room );
		for ( j = 1; j <= lemonade[room][0]; j++)
		{
			//printf("j=%d\n",j );
			//printf("lemonade=%d\n",lemonade[room][j]);
			if (lemonade[room][j]>max)
			{
				max=lemonade[room][j];
				delete=j;
			}
		}
		//printf("Maximum volume = %d\n",max );
		//printf("\n");
		lemonade[room][delete]=-1;
		if(max>0)
		   total=total+max;
		max=-2;
	}

	t_array[k]=total;
	total=0;
}
for ( i = 0; i < t; i++)
{
	printf("%d\n",t_array[i] );
}

	return 0;
}