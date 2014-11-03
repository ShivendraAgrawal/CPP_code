#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#define N 100

int isSafe(int x1, int y1, int x2, int y2, int n)
{
  int i,j,k,l,r,s,t;
  r=x1; s=y1;
  if ((x1==x2)||(y1==y2))
  return 1;
  for(i=1;i<=n;i++)
    {
      if ((r==x2)&&(s==y2))
      {
      	return 1;
      }
      r++; s++;
      if ((r>n)||(s>n)||(s<1)||(r<1))
      {
      	i=n+1;
      }
    }
      r=x1; s=y1;
  for(i=1;i<=n;i++)
    {
      if ((r==x2)&&(s==y2))
      {
      	return 1;
      }
      r++; s--;
      if ((r>n)||(s>n)||(s<1)||(r<1))
      {
      	i=n+1;
      }
    }
      r=x1; s=y1;
  for(i=1;i<=n;i++)
    {
      if ((r==x2)&&(s==y2))
      {
      	return 1;
      }
      r--; s++;
      if ((r>n)||(s>n)||(s<1)||(r<1))
      {
      	i=n+1;
      }
    }
      r=x1; s=y1;
  for(i=1;i<=n;i++)
    {
      if ((r==x2)&&(s==y2))
      {
      	return 1;
      }
      r--; s--;
      if ((r>n)||(s>n)||(s<1)||(r<1))
      {
      	i=n+1;
      }
    }
return 0;
}
int main()
{
	int i,j,k,l,n,r;
	scanf("%d%d%d%d%d",&i,&j,&k,&l,&n);
	printf("%d",isSafe(i,j,k,l,n));
}
