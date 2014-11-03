/* A program to check whether given three points fall on one straight line or not */


#include<stdio.h>

int main()

{
    int x1, x2, x3, y1, y2, y3,flag=-1;

printf("\nEnter the Co-ordinates of first point(x1,y1)");
scanf("%d %d",&x1, &y1);

printf("\nEnter the Co-ordinates of 2nd point(x2,y2)");
scanf("%d %d",&x2, &y2);

printf("\nEnter the Co-ordinates of 3rd point(x3,y3)");
scanf("%d %d",&x3, &y3);

if(x1<=1000&&x2<=1000&&x3<=1000&&y1<=1000&&y2<=1000&&y3<=1000)
{
  if((x1==x2)&&(x2==x3)){flag=1;}
  if((x1==x2)&&(x2!=x3)){flag=0;}
  if((x1!=x2)&&(x2==x3)){flag=0;}
  if(flag==-1)
  {
  	if ((y2-y1)/(x2-x1)==(y3-y2)/(x3-x2)){flag=1;}
  }

  if(flag==1)
  printf("The three points lie on straight line");
  else
  printf("The three points do not lie on straight line");
}
else
{
	printf("Input out of constraints\n");
}

return 0;

}
