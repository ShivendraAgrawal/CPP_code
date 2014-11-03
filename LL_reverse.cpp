#include <iostream>
using namespace std;

typedef struct node
{
	int data;
	node * next;
} node;

int main(int argc, char const *argv[])
{
	int size;
	srand ( time(NULL) );
	node * head = (node *)malloc(sizeof(node));
	node * iterate;
	node * saviour;
	node * head_copy =head;
	iterate =head;
	size=2+rand()%10;
	cout<<"Size = "<<size<<endl;
	for (int i = 0; i < size-1; ++i)
	{
		iterate->data=rand()%10;
		//cout<< iterate->data<<" \n";
		iterate->next=(node *)malloc(sizeof(node));
		iterate=iterate->next;
	}
	iterate->data=rand()%10;
	iterate->next=NULL;
    iterate=head;
	while(iterate!=NULL)
	{
		cout<<iterate->data<<"-> ";
		iterate=iterate->next;
	}

	iterate=head->next;
	saviour=iterate->next;

	while(saviour!=NULL)
	{
		iterate->next=head;
		head=iterate;
		iterate=saviour;
		saviour=saviour->next;
	}
	iterate->next=head;
	head_copy->next=NULL;
	cout<<"\nAfter reversal : \n";
    while(iterate!=NULL)
    {
    	cout<<iterate->data<<"-> ";
    	iterate=iterate->next;
    }

    cout<<"\n";

	return 0;
}