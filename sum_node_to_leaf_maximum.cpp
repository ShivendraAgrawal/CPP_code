#include"iostream"
#include <algorithm>
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
    return node;
}
int path[20],final;

int sum_to_leaf(struct node* root,int sum,int count) {

    if(root==NULL) {
        return sum;    
    } else {
        count++;
        final=count;
        sum=sum+root->data;
        int left_sum = sum_to_leaf(root->left, sum,count);
        int right_sum = sum_to_leaf(root->right, sum,count);
        if(left_sum>right_sum)
        {
            if(root->left!=NULL)
              path[count]=root->left->data;
        }
        else
        {
            if(root->right!=NULL)
              path[count]=root->right->data;
        }
        return max(left_sum, right_sum); 
    }
}

void print(struct node* root)
{
    if(root==NULL)return;
    print(root->left);
    cout<<root->data<<" ";
    print(root->right);
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
    root->right->left->right->left->left = newNode(11);

	// root = NULL;
 
 //    /* Constructing tree given in the above figure */
 //    root = newNode(10);
 //    root->left = newNode(-2);
 //    root->right = newNode(7);
 //    root->left->left = newNode(8);
 //    root->left->right = newNode(-4);
    int count=0,max_sum=0;
    path[0]=root->data;

    max_sum=sum_to_leaf(root,0,count);
    print(root);
    cout<<"\nThe path is: ";
    for (int i = 0; i < final; ++i)
    {
    	printf("%d ",path[i]);
    }
    printf("\n");
    printf("Sum = %d\n",max_sum);
}
