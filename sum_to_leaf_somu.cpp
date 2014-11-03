#include"iostream"
using namespace std;
struct node
{
	int data;
	struct node *left;
	struct node *right;
};
struct node* newNode(int val)
{
	struct node* node=(struct node*)malloc(sizeof(struct node));
	node->data=val;
	node->left=NULL;
	node->right=NULL;
}
int max(int a, int b)
{
	if(a>b)
		return a;
	else
		return b;
}
int sum;
int sum_to_leaf(struct node* root,int path[20],int* count,int* max_sum)
{
	if(root==NULL)
		return 0;

    else if(root->left==NULL && root->right==NULL)
    {
    	 return (root->data);
    }

 else
     {

      sum= root->data+max(sum_to_leaf(root->left,path,count,max_sum),
                 sum_to_leaf(root->right,path,count,max_sum)) ;
       if(sum >= *max_sum)
       { 
       	*max_sum=sum;
       	 path[*count]=root->data;
        (*count)++;

       }
     return sum; 
     } 
}
main()
 {
	struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->right->left = newNode(5);
    root->right->right = newNode(6);
    root->right->left->right = newNode(7);
    root->right->right->right = newNode(8);
    root->right->left->right->left = newNode(9);
    root->right->right->right->right = newNode(10);
    root->right->right->right->right->left = newNode(11);

	// struct node *root = NULL;
 
 //    /* Constructing tree given in the above figure */
 //    root = newNode(10);
 //    root->left = newNode(-2);
 //    root->right = newNode(7);
 //    root->left->left = newNode(8);
 //    root->left->right = newNode(-4);
    int path[20],count=0,max_sum=0;
    sum_to_leaf(root,path,&count,&max_sum);
    for (int i = 0; i < count; ++i)
    {
    	printf("%d ",path[i]);
    }
    printf("\n");
    printf("%d\n",max_sum);
}
