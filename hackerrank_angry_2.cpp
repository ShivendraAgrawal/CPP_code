#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
	long long int n,k,packet[100000],min=10e+18,start,stop,total,sum=0;
	scanf("%lld",&n);
	scanf("%lld",&k);

    for (int i = 0; i < n; ++i)
    {
	    scanf("%lld",&packet[i]);
    }
	sort(packet,packet+n);
    total=0;
	
    for (int i = 0; i < k; ++i)
        {
            total=total+(i*packet[i]) - ((k-i-1)*packet[i]);
            if(i!=0)
            {
                sum=sum+packet[i];
            }

        }	
                    //cout<<total<<"  Sum= "<<sum<<endl;
        if(total<min)
        {
            min=total;
        }

	for (int l=1; l<n-k; l++)
	{
        total=total + 1LL*(k-1)*(packet[k-1+l]) - 1LL*(2*sum) + 1LL*(k-1)*packet[l-1] ;
        //cout<<"sum = "<<sum<<endl;
        //cout<<"total = "<<total<<endl;
        sum=sum - packet[l] + packet[k-1+l];
        if(total<min)
        {
            min=total;
        }
	}

	printf("%lld",min);
    return 0;
}
