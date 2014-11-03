#include<stdio.h>
main()
{    int t=0,n,e,f,i,j;
    int p[50002],w[10002];
    scanf("%d",&t);
    while(t--)
    {    scanf("%d %d",&e,&f);
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {    scanf("%d %d",&p[i],&w[i]);
        }
        int min[f-e+2];
        for(i=e;i<=f+2;i++)
        {    min[i-e]=50001;
        }
        min[0]=0;
        for(i=e+1;i<=f;i++)
        {    for(j=0;j<n;j++)
            {    if(w[j]<=(i-e)&& min[i-e-w[j]]+p[j] < min[i-e])
                    min[i-e]=min[i-e-w[j]]+p[j];

            }
        }
        if(min[f-e]==50001||min[f-e]==0)
        printf("This is impossible.\n");
        else
        printf("The minimum amount of money in the piggy-bank is %d.\n",min[f-e]);
    }

    return 0;
}
