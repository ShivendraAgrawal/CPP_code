#include <iostream>
#include <vector>
#define MAXX 1000
using namespace std;

int number[MAXX], digits=0;
int adjust(int i)
{
	int temp;
	if(number[i]<9)
		{
			number[i]=number[i]+1;
			return i;
		}

	number[i]=0;
	return adjust(i-1);
}

void makePalindrome(int head,int tail)
{
	int revert;
	if(head>tail)
		return;
	if(number[head]==number[tail])
	{
		makePalindrome(head+1,tail-1);
	}
	if(number[tail]<number[head])
	{
		number[tail]=number[head];
		makePalindrome(head+1,tail-1);
	}
	if (number[tail]>number[head])
	{
		number[tail]=number[head];
		revert=adjust(tail-1);
		if(revert<=head)
		{
		   makePalindrome(revert,digits-revert-1);
		}
		else
		{
			makePalindrome(head+1,tail-1);
		}
	}
}

int main(int argc, char const *argv[])
{
	long long int num,num_copy;
	int head,tail;
	int number_reverse[MAXX];
	cout<<"Enter the number whose next greater palindrome you want to find"<<endl;
	cin>>num;
	num_copy=num;
	num_copy++; //  Comment this line if you don't want the next palindrome even if the input is already palindrome

	while(num_copy>0)
	{
		number_reverse[digits]=num_copy%10;
		digits++;
		num_copy=num_copy/10;
	}

	for (int i = digits-1; i >=0; --i)
	{
		number[digits-i-1]=number_reverse[i];
	}
	head=0; tail=digits-1;
	makePalindrome(head,tail);
	cout<<"Answer : ";
	for (int i = 0; i < digits; ++i)
	{
		cout<<number[i];
	}
	cout<<"\n";
	return 0;
}