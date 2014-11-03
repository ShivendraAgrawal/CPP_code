#include "stdio.h"
#include "stdlib.h"
#include <time.h>

struct list
{
	int key;
	struct list * next;
};

struct list * last;
struct list * junction;

void make_next(struct list * node, int k)
{
	if(k>0)
	{
	    node->next=(struct list *)malloc(sizeof(struct list));
	    node->next->key=rand()%20;
	    node->next->next=NULL;
	    printf("%d ",node->next->key);
	    make_next(node->next,k-1);

	}
    else
    {
       last=node;
       return;
    }
}

void traverse(struct list * node, int k)
{
   if(k>0)
   {
   	traverse(node->next,k-1);
   	//printf("k = %d\n", k);
   }
   else junction=node;
   return;
}

int main(int argc, char const *argv[])
{
	int size,random1,length=0;
	struct list * root;
	struct list* skip1,*skip2,*marker,*start,*kstart,*previous;
	srand ( time(NULL) );
	size=rand()%30;
	printf("size = %d\n",size );
	root=(struct list *)malloc(sizeof(struct list));
	root->key=rand()%30;
	root->next=NULL;
	printf("%d ",root->key );
	make_next(root,size-1); // Making a linear linked list of random size with random key values and storing the last node's address in "last"
	printf("\nLast->key = %d\n", last->key);
	random1=rand()%size;
	traverse(root,random1); // Traverse to a random node and store the address in "junction"
	last->next=junction; // Making the last node point to that obtained random node to create a loop
	printf("random1 = %d , junction->key = %d\n",random1,junction->key );
	last=NULL; size=0; junction=NULL; // Forgetting all the information saved during forming the random looped linear linked list
    skip1=root;
    skip2=root->next;

	while(skip1!=skip2)  // Finding if the linked list contains a loop
	{
       skip1=skip1->next;
       skip2=skip2->next->next;
       printf("skip1 = %d skip2 = %d\n",skip1->key,skip2->key);
	}
	marker=skip1;
	skip1=skip1->next;
	length++;
	while(skip1!=marker)
		{
			length++;
			skip1=skip1->next;
		}
	printf("Lenght of the loop = %d\n",length);
	start=root; kstart=root;
    
    while(length>0)
    {
    	kstart=kstart->next;
    	length--;
    }
    while(kstart!=start)
    {
    	start=start->next;
    	previous=kstart;
    	kstart=kstart->next;
    }
    printf("Found junction = %d\n",kstart->key );
    previous->next=NULL;
    start=root;
    while(start->next!=NULL)
    {
    	printf("%d ",start->key );
    	start=start->next;
    }
    printf("%d\n",start->key );

	return 0;
}