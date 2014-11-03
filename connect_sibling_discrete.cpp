#include <iostream>
#include <queue>
using namespace std;
 
// A utility function to get maximum of two integers
int max(int l, int r) { return (l > r ? l : r); }

queue <pair <struct Node*, int> > q;
int maximum_level=0;
 
// A Binary Tree Node
struct Node
{
    int data;
    int visited;
    struct Node *left, *right, *sibright;
};
 
// A utility function to create a new Binary Tree node with given data
struct Node* newNode(int data)
{
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->visited=0;
    node->left = node->right = node->sibright = NULL;
    return node;
}
struct Node *root = newNode(1);
pair<struct Node* , int> p;

void connect()
{
    if(!q.empty())
    {
    pair<struct Node*,int> current= q.front();
    q.pop();
    pair <struct Node*, int> p;
    if(current.second>maximum_level)
    {
        maximum_level=current.second;
    }
    //cout<<current.first->data<<" "<<current.second<<"     ";

    if((current.first)->left)
    {
        p.first=current.first->left;
        p.second=(current.second)+1;
        q.push(p);
    }
    if((current.first)->right)
    {
        p.first=current.first->right;
        p.second=(current.second)+1;
        q.push(p);
    }
    if(!q.empty())
    {
      if(current.second==(q.front()).second)
      {
         current.first->sibright = (q.front()).first;
      }
      else
      {
        //cout<<"\n";
      }
    }
    connect();
    }
    return;
}

void print(struct Node* node)
{
    if(node!=NULL)
    {
        cout<<node->data<<" ->";
        node->visited=1;
        print(node->sibright);
    }
    return;
}
void dfs_print(struct Node* node)
{
    if(node->visited==0)
    {
        print(node);
        cout<<"\n";
    }
    if(node->left)
    {
        dfs_print(node->left);
    }
    if(node->right)
    {
        dfs_print(node->right);
    }
    return;
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

    p.first=root;
    p.second=0;
    q.push(p);
    connect();
    dfs_print(root);

    return 0;
}
