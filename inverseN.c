#include <stdio.h>
#include <math.h>
#define M 20
#define Pi 3.14159265

void product(double a[M][M],double b[M][M],double c[M][M],int n)
{
  int i,j,k;
  for(i=0;i<n;i++)
    {
      for(j=0;j<n;j++)
	{
	for(k=0;k<n;k++)
	  {
	    c[i][j]=c[i][j]+a[i][k]*b[k][j];
	  }
	}
    }
}

void pro(double a[M][M],double b[M],double c[M],int n)
{
  int i,j,k;
  for(i=0;i<n;i++)
    {
      for(j=0;j<n;j++)
	{
	  c[i]=c[i]+a[i][j]*b[j];
	}
    }
}

void last(double b[M],double c[M][M],int k,int n)
{
  int i,j;  double p=b[k];
  for(j=0;j<n;j++){b[j]=(b[j]/p)*-1;}
  b[k]=-1*b[k]/p;
  for(i=0;i<n;i++)
      c[i][k]=b[i];
}

int main()
{
  int i,j,k,n;
  double Bc[M][M],I[M][M],B[M][M]={0,0},Bi_next[M][M];
  double Bi[M][M],C[M],E[M],Z[M][M],Qo,Q1,Q,DQ;
  double R,check,rhs[M],result[M];

  printf("\nPROFRAM TO FIND THE INVERSE OF A GIVEN MATRIX\n");
  printf("Input the value of n : ");
  scanf("%d",&n);
  printf("\nInput starting Q (theta) : ");
  scanf("%lf",&Qo);
  printf("\nInput End Q (theta) : ");
  scanf("%lf",&Q1);
  DQ=(Q1-Qo)/n;
  printf("\nDQ=%lf",DQ);

   for(i=0;i<n;i++)
     {
     	Q=Qo+i*DQ;
     	Q=Q*Pi/180;
     	printf("\nQ=%f",Q);
        R=1.1/(cos(Q));
        printf("\nR=%f",R);
        Bc[i][0]=log(R);
        rhs[i]=(R*R-1)/4;
        for(k=1;k<n;k++)
        {
        	Bc[i][k]=((pow(R,4*k))-(pow(R,-4*k)))*cos(4*k*Q);
        	check=(pow(R,4*k));
        	printf("\npow=%f",check);
        }
     }

for(j=0;j<n;j++)
	{
	for(k=0;k<n;k++)
	  {
	    if(j==k){I[j][k]=1;Bi[j][k]=1;Z[j][k]=1;}
	    else {I[j][k]=0;Bi[j][k]=0;Z[j][k]=0;}
	    Bi_next[j][k]=0;
	  }
	C[j]=0;
	E[j]=0;
	}

   for(i=0;i<n;i++)
     {
       for(j=0;j<n;j++)
	 C[j]=Bc[j][i];

       pro(Bi,C,E,n);


       last(E,Z,i,n);

       product(Z,Bi,Bi_next,n);


       for(j=0;j<n;j++)
	{
	for(k=0;k<n;k++)
	  {
	    Bi[j][k]=Bi_next[j][k];
	      Bi_next[j][k]=0;
	    Z[k][j]=I[k][j];
	  }
	}
       for(j=0;j<n;j++)
	 {
	   C[j]=0;
	   E[j]=0;
	 }
     }
   printf("\nINVERSE\n");

   for(i=0;i<n;i++)
     {
       for(j=0;j<n;j++)
	 {
	   printf("%lf ",Bi[i][j]);
	 }
       printf("\n");
     }
     pro(Bi,rhs,result,n);
          for(j=0;j<n;j++)
	 {
	   printf("\n%lf ",result[j]);
	 }
}
