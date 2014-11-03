#include<stdio.h>
 
// Returns the count of ways we can sum  S[0...m-1] coins to get sum n
int count( int S[], int m, int n )
{
    printf("%d ",n );
    // If n is 0 then there is 1 solution (do not include any coin)
    if (n == 0)
        return 1;
     
    // If n is less than 0 then no solution exists
    if (n < 0)
        return 0;
 
    // If there are no coins and n is greater than 0, then no solution exist
    if (m <=0 && n >= 1)
        return 0;
 
    // count is sum of solutions (i) including S[m-1] (ii) excluding S[m-1]
    return count( S, m - 1, n ) + count( S, m, n-S[m-1] );
}

int count1(int S[], int n,int m)
{
    printf("%d ",n );
    int i,sum=0;
    if(n==0)
        return 1;
    if(n<0)
        return 0;
    for ( i = 0; i < m; ++i)
    {
        sum=sum+count1(S,n-S[i],m);
    }
    return sum;
}
 
// Driver program to test above function
int main()
{
    int i, j;
    int arr[] = {1, 2, 3};
    int m = sizeof(arr)/sizeof(arr[0]);
    printf("%d \n", count(arr, m, 4));
    printf("\n");
    printf("%d ", count1(arr, 4, m));

    getchar();
    return 0;
}