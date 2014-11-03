#include <iostream>
#include <queue>
using namespace std;
 
// A utility function to get maximum of two integers
int max(int l, int r) { return (l > r ? l : r); }
queue <struct Node*> q;
 
// A Binary Tree Node
struct Node
{
    int data;
    struct Node *left, *right, *sibright;
};
 
// A utility function to create a new Binary Tree node with given data
struct Node* newNode(int data)
{
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = node->sibright = NULL;
    return node;
}
struct Node *root = newNode(1);

void connect()
{
    if(!q.empty())
    {
    struct Node * current= q.front();
    q.pop();

    if(current->left)
    {
        q.push(current->left);
    }
    if(current->right)
    {
        q.push(current->right);
    }
    current->sibright = q.front();
    connect();
    }
    return;
}

void print(struct Node* root)
{
    if(root!=NULL)
    {
       cout<<root->data<<" -> ";
       print(root->sibright);
    }
    else return;
    
}
 
int main()
{
    {
     
     root->left = newNode(2);
     root->right = newNode(3);
     root->left->left = newNode(4);
     root->left->right = newNode(5);
     root->right->left = newNode(6);
     root->right->right = newNode(7);
     root->left->left->left = newNode(8);
     root->left->left->right = newNode(9);
     root->left->right->left = newNode(12);
     root->right->right->left = newNode(10);
     root->right->right->left->right = newNode(11);
     root->left->left->right->left = newNode(13);
     root->left->left->right->right = newNode(14);
     root->left->left->right->right->left = newNode(15);
    }
    
    q.push(root);
    connect();
    print(root);

    return 0;
}
