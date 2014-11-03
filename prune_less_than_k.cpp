#include <iostream>
using namespace std;
 
// A utility function to get maximum of two integers
int max(int l, int r) { return (l > r ? l : r); }
 
// A Binary Tree Node
struct Node
{
    int data;
    struct Node *left, *right;
};
 
// A utility function to create a new Binary Tree node with given data
struct Node* newNode(int data)
{
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
 
// print the tree in LVR (Inorder traversal) way.
// void print(struct Node *root)
// {
//     if (root != NULL)
//     {
//         print(root->left);
//         printf("%d ",root->data);
//         print(root->right);
//     }
// }

// struct Node* prune(struct Node * root, int k)
// {
//     // if(root==NULL) return NULL;
//     // if(root->left==NULL && root->right==NULL && k-(root->data)>0)
//     // {
//     //     root=NULL;
//     //     return NULL;
//     // }
//     // else if(root->left==NULL && root->right==NULL)
//     // {
//     //     return root;
//     // }
//     // if(prune(root->left,k-(root->data))==NULL && prune(root->right,k-(root->data))==NULL)
//     //     return NULL;
//     // else return root;
//     if(root==NULL && k>0)
//     {
//         return NULL;
//     }
//     else if(root==NULL)
//     {
//         return root;
//     }
//     root->left=prune(root->left,(k-root->data));
//     root->right=prune(root->right,(k-root->data));
// };

int main()
{
    int k = 45;
    struct Node *root = newNode(1);
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
 
    printf("Tree before truncation\n");
    print(root);
 
    root = prune(root, k); // k is 45
 
    printf("\n\nTree after truncation\n");
    print(root);
 
    return 0;
}
