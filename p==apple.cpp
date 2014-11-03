#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	char p[]="apple";
	if(p=="apple")
		cout<<"if";
	else
		cout<<"else\n";
	int a=3; float b=.1234; float c=234.1234;

	printf("%3d\n",a );
	printf("%2.5f\n",c);
	int i=0||0;
	cout<<i<<" ";


	return 0;
}