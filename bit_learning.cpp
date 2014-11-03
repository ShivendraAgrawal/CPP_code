#include"iostream"
using namespace std;

int main(int argc, char const *argv[])
{
	int A=19,b;
	A|=1<<3;
	cout<<A<<endl;
	A=19;
	A|=1<<4;
	cout<<A<<endl;
	b=1<<3;
	cout<<b<<" ";
	b=1<<4;
	cout<<b<<" ";
	return 0;
}