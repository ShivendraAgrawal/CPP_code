#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n,k,packet[100000],min=0,start,stop;
	scanf("%d",&n);
	scanf("%d",&k);

    for (int i = 0; i < n; ++i)
    {
	    scanf("%d",&packet[i]);
    }
	sort(packet,packet+n);

	min=packet[n-1]-packet[0];
	for (int i=0; i<n-k+1; i++)
	{
		if(packet[i+k-1]-packet[i]<min)
		{
			min=packet[i+k-1]-packet[i];
			start=i;
			stop=i+k-1;
		}
	}
	printf("%d",packet[stop]- packet[start] );

    return 0;
}
