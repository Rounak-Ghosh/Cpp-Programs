#include<iostream>
using namespace std;

struct Node 
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

int search(int inorder[], int start, int end, int val)
{
    for(int i=start; i<=end; i++)
        if(inorder[i] == val)
            return i;
    return -1;
}

Node* buildTree(int preorder[], int inorder[], int start, int end)
{
    static int idx = 0;
    
    if(start > end)
        return NULL;

    int val = preorder[idx];
    idx++;
    Node* curr = new Node(val);
    
    if(start == end)
        return curr;
    
    int pos = search(inorder, start, end, val);
    curr->left = buildTree(preorder, inorder, start, pos-1);
    curr->right = buildTree(preorder, inorder, pos+1, end);

    return curr;
}

void inorderPrint(Node* root)
{
    if(root == NULL)
        return;
    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}

int main()
{
    int preorder[] = {1,2,4,3,5};
    int inorder[] = {4,2,1,5,3};

    //build tree from preorder and inorder sequence
    Node* root = buildTree(preorder, inorder, 0, 4);
    inorderPrint(root);
    return 0;
}