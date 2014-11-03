#include"iostream"
#include<algorithm>
using namespace std;
int size1,size2;

void print(string &a,string &b,int i, int j)
{
	if(i<size1)
	{
	cout<<a[i];
	i++;
	print(a,b,i,j);
	i--;
    }
    if(j<size2)
    {
	cout<<b[j];
	j++;
	print(a,b,i,j);
    }
    cout<<" ";
	return;
}

int main(int argc, char const *argv[])
{
	string a="AB",b="CD";
	size1=a.size();
	size2=b.size();
	cout<<"size = "<<size1<<" "<<size2<<endl;
	print(a,b,0,0);

	return 0;
}