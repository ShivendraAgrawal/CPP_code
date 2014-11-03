//http://www.geeksforgeeks.org/lexicographic-rank-of-a-string/
//Shivendra
#include "iostream"
using namespace std;

int factorial(int n)
{
  return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

int rank(const char* s,int k,int n)
{
	if(k==n-2)
		return 1;
	int min=0;
	for (int i = k+1; i < n; ++i)
	{
		if(*(s+k)>*(s+i))
		   min++;
	}
	return(min*factorial(n-k-1)+rank(s,k+1,n));
}

int main(int argc, char const *argv[])
{
	const char* s="string"; //Constant needed since we are pointing to a read-only memory
	int n=strlen(s); //Size of the string
	cout<<"Answer = "<<rank(s,0,n)+1<<endl; //Plus 1 since the rank(s,0,n) gives the number of strings lesser that this.
	return 0;
}