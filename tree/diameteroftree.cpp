#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node*left;
    struct node*right;
};

struct node*newNode(int data)
{
    struct node*Node = new node;
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;

    return (Node);
}

int height(struct node*node)
{
    if(node == nullptr)
    {
        return 0;
    }
    return 1+ max(height(node->left),height(node->right));
}

int diameter(struct node*node)
{
    if(node == NULL)
    {
        return 0;
    }

    int lheight = height(node->left);
    int rheight = height(node->right);

    int ldiameter = diameter(node->left);
    int rdiameter = diameter(node->right);

    return max((lheight+rheight+1),max(ldiameter,rdiameter));

}

int main()
{
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
 
    // Function Call
    cout << "Diameter of the given binary tree is " <<
        diameter(root);
 
    return 0;
}