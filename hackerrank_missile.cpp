#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int minimum=100000,n,missile[100000][2],solution[100000][2];

void need( int missile_number, int total)
{
    if (total>minimum)
    {
        return;
    }
    int flag=0,undo1,undo2;
    if(missile_number==n)
    {
        if(total<minimum)
        {
            minimum=total;
        }
        return;
    }
    for (int i = 0; i < total; ++i)
    {   //cout<<"\n"<<i;
        //flag=0;
        if((missile[missile_number][0]-solution[i][0])>=abs(missile[missile_number][1]-solution[i][1]))
        {
            flag=1;
            undo1=solution[i][0];
            undo2=solution[i][1];
            solution[i][0]=missile[missile_number][0];
            solution[i][1]=missile[missile_number][1];
            need(missile_number+1,total);
            solution[i][0]=undo1;
            solution[i][1]=undo2;
        }
    }
    if(flag==0)
        {
            //cout<<missile[missile_number][0]<<" - "<<missile[missile_number][1]<<"\n";
            solution[total][0]=missile[missile_number][0];
            solution[total][1]=missile[missile_number][1];
            need(missile_number+1,total+1);
        }
    return;
}


int main()
{
    int k,i,j,mini,min_index,swap,number=0;
    scanf("%d",&n);

 for (int i = 0; i < n; ++i)
    {
        scanf("%d %d",&missile[i][0], &missile[i][1]);
    //cout<<""
    }

    // for (int i = 0; i < n; ++i)
    // {

    //     mini=missile[i][0];
    //     min_index=i;
    //     for (int j = i; j < n; ++j)
    //     {
    //         if(missile[j][0]<mini)
    //         {
    //             mini=missile[j][0];
    //             min_index=j;
    //             cout<<"  "<<mini<<" - "<<min_index<<endl;
    //         }
    //     }
    //     swap= missile[min_index][0];
    //     missile[min_index][0]=missile[i][0];
    //     missile[i][0]=swap;

    //     swap= missile[min_index][1];
    //     missile[min_index][1]=missile[i][1];
    //     missile[i][1]=swap;
    // }

    // for (int i = 0; i < n; ++i)
    // {
    //     printf("%d %d\n",missile[i][0],missile[i][1]);
    // }
    solution[0][0]=missile[0][0]; solution[0][1]=missile[0][1];
    // cout<<"befre first need\n";
    need(1,1);

    // cout<<"\nAnswer = "<<minimum<<endl;
    cout<<minimum;

    return 0;
}