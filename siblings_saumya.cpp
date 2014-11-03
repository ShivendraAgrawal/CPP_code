#include <iostream>
#include <queue>
using namespace std;
 
 
// A utility function to get maximum of two integers
int max(int l, int r) { return (l > r ? l : r); }
 
// A Binary Tree Node
struct Node
{
    int data,level;
    struct Node *left, *right,*sib_right;
};
 
  queue<struct Node*> q;

// A utility function to create a new Binary Tree node with given data
struct Node* newNode(int data)
{
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->level=0;
    node->left = node->right =  node->sib_right=NULL;
    return node;
}
struct Node *root = newNode(1); 
void connect_sibling()
{
  if(!q.empty())
    {
     struct Node* node = q.front();
      q.pop();
      cout<<"\n"<<node->data<<" "<<node->level<<"";
    if(node->left)
      {
        (node->left)->level=(node->level)+1;
        q.push(node->left);
      }
      cout<<" hi ";
    if(node->right)
    {
       (node->right)->level=(node->level)+1;
        q.push(node->right);
     }
     cout<<"bye ";
     if(!q.empty())
     {
       if(node->level==(q.front())->level)
       {
        node->sib_right=q.front(); 
        }
        cout<<"dead  ";
      }
    
   connect_sibling();
   }
   return;
}


void print(struct Node* root)
{
    while(root!=NULL)
    {
        printf("%d->",root->data);
        root=root->sib_right;
    }
    cout<<"\n";
   return;
}

int main()
{
    int k = 45;
    
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
 
    // printf("Tree before truncation\n");
    // print(root);
   
   // root = prune(root, k); // k is 45
    q.push(root);
   root->level=0;
       print(root);
    connect_sibling();
    printf("\n\nTree after truncation\n");
    print(root);
 
    return 0;
}
