#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void hello(){
        cout<<"Hell";
    }

struct row{
    long time;
    long freq;
};
typedef struct row row;


bool sortFunc( row i, row j)
{
        return ((i.time)<(j.time));
}

int main()
{
    int n,k,i,j;
    row inputs[1000];
    scanf("%d",&n);

    for (int i = 0; i < n; ++i)
    {
        scanf("%ld %ld",&inputs[i].time, &inputs[i].freq);
    }

    
   sort(inputs,inputs+n,sortFunc);

    for (int i = 0; i < n; ++i)
    {
        printf("%ld %ld\n",inputs[i].time,inputs[i].freq);
    }


    return 0;
}
