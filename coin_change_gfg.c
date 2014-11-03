#include<stdio.h>
 
// Returns the count of ways we can sum  S[0...m-1] coins to get sum n
int count( int S[], int m, int n )
{
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

int count2( int S[], int m, int n )
{
    // table[i] will be storing the number of solutions for
    // value i. We need n+1 rows as the table is consturcted
    // in bottom up manner using the base case (n = 0)
    int table[20]={0},i,j;
 
    // Initialize all table values as 0
    //memset(table, 0, sizeof(table));
 
    // Base case (If given value is 0)
    table[0] = 1;
 
    // Pick all coins one by one and update the table[] values
    // after the index greater than or equal to the value of the
    // picked coin
    for( i=0; i<m; i++)
        for( j=S[i]; j<=n; j++)
            table[j] += table[j-S[i]];
 
    return table[n];
}
 
// Driver program to test above function
int main()
{
    int i, j;
    int arr[] = {2,5,3,6};
    int m = sizeof(arr)/sizeof(arr[0]);
    printf("%d \n", count(arr, m, 10));
    printf("%d \n", count2(arr, m, 10));
    //getchar();
    return 0;
}
