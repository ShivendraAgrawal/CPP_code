#include <iostream>
using namespace std;

int main() {
	int t,n,c,m,total;
    scanf("%d",&t);
    for (int i = 0; i < t; ++i)
    {
    	total=0;
    	scanf("%d %d %d",&n,&c,&m);
    	while((n/c)>=m)
    	{
    		total=total+m;
    		n=n-(m*c)+c; // m wrappers give power to "buy" one more chocolate 
    	}
    	total=total+(n/c);
    	printf("%d\n",total);
    }
    return 0;
}
