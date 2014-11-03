#include"iostream"
using namespace std;

int main(int argc, char const *argv[])
{
	int n,M,T=0;
	scanf("%d %d",&n,&M);
	int P[n+1];               //Here you had put p[n] and then you were going from 1-n which requires p[n+1]
	//srand ( time(NULL) );
	for (int i = 1; i <= n; ++i)
	{
		P[i]=rand()%M +1 ;
		printf("P[%d] = %d\n",i,P[i] );  //added for ease
		T=T+P[i];
	}
	int A[n+1][T+1];
	//A[0][0]=1;
	for (int i = 1; i < n+1; ++i)
	{
		for (int j = 1; j < T+1; ++j)   // Here you had put i< T+1
		{
			A[i][j]=0;
		}
	}
	for (int i = 1; i < T+1; ++i)
	{
		A[0][i]=0;
	}
	for (int i = 0; i < n+1; ++i)
	{
		A[i][0]=1;
	}
	for (int i = 1; i < n+1; ++i)
	{
		for (int j = 1; j < T+1; ++j)  // Same error here
		{
			if(A[i-1][j]!=0)
				A[i][j]=1;

			if(j>=P[i])              // Here >= instead of only >
			{
			if(A[i-1][(j-P[i])]!=0)
				A[i][j]=2;
			}
		}
	}
	for (int i = 0; i < n+1; ++i)
	{
		for (int j = 0; j < T+1; ++j)  // Yup! same again
		{
			printf("%d ",A[i][j]);
		}
		printf("\n");
	}
	int s,s1,s2;
	int j=2*T/3;
	  while(j>0)
	  {
	  	if(A[n][j]!=0)
	  		{s1=j; j=0;}  //When if was True it was not able to go to the else to do j--. That's why it was not able to come out of the loop by going in if all the time
	  	else
	  	  j--;
	  }
	  while(j<T+1)  // But this will be redundant if you dont start the j near and after (near and before already covered above) 2/3rd of the total 
	  {
        if(A[n][j]!=0)
	  		{s=j; j=T+1;}  //Same as above
	  	else
	  	  j++;
	  }
	 if( abs(s-2*(T-s)) < abs(s1-2*(T-s1)) )
	 {
	 	s1=s;
	 }
	  s2=T-s1;
    printf("%d %d\n",s1,s2);
     bool sol[n+1];     // Size will be n+1 not n coz you are filling from index 1 later.
     int i=n;
     for (int i = 1; i <=n; ++i)
     {
     	sol[i]=false;
     }
      while(i>0 && s1>0)
      {
      	if (A[i][s1]==2) //[i][s1] instead of [i][j]
      	{
      		sol[i]=true;
      		s1=s1-P[i]; // This line would be befor i=i-1 because ith house was part of the profit and not the (i-1)th, I shifted i=i-1 to the next line
      		i=i-1;
      	}
      	else if (A[i][s1]==1)  //[i][s1] instead of [i][j]
      	{
      		i=i-1;
      	}
      	
      }
      printf("\nFirst son gets: \n");
      for (int i = 1; i < n+1; ++i)
      {
      	if (sol[i]==true)
      	{
      		printf("%d ",i);
      	}
      }
      printf("\nI love you\n");
	return 0;
}