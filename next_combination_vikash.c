#include "stdio.h"
#include "string.h"
int main(int argc, char const *argv[])
{
	int n,i,j,k,l,m,mc,pos,out=0;
	printf("Enter no. of digits:\n");
	scanf("%d",&n);
	printf("Enter the %d digit number:\n",n);
	scanf("%d",&m);
	mc=m;pos=n-1;
	int a[n];
	for (i = n-1; i >= 0; i--)
	{
		a[i]=mc%10;
		mc=mc/10;
	}
	for (i = pos-1; i >= 0; i--)
	{
		for (l = n-1; l > i; l--)
		{
			if (a[l]>a[i])
			{
				mc=a[i];
				a[i]=a[l];
				a[l]=mc;
				for (j = i+1; j <= n-1; ++j)
				{
					for (k = i+1; k <=n-2 ; ++k)
					{
						if (a[k]>a[k+1])
						{
							mc=a[k];
							a[k]=a[k+1];
							a[k+1]=mc;
						}
					}
				}
				for (j = 0; j < n; ++j)
				{
					out=out*10+a[j];
				}
				break;
			}
		}
		if(out>m) break;
		}
	if (out!=0)
	{
		printf("%d\n",out);
	}
	else
		printf("Not Possible.\n");
	return 0;
}