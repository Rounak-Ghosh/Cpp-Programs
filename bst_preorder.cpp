#include<iostream>
#include<climits>
using namespace std;

struct Node 
{
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* constructBST(int preorder[], int* preorderIdx, int key, int min, int max, int n)
{
    if(*preorderIdx >= n)
        return NULL;

    Node* root = NULL;
    if(key > min && key < max)
    {
        root = new Node(key);
        *preorderIdx += 1;

        if(*preorderIdx < n)
        {
            root->left = constructBST(preorder, preorderIdx, preorder[*preorderIdx], min, key, n);
        }
        if(*preorderIdx < n)
        {
            root->right = constructBST(preorder, preorderIdx, preorder[*preorderIdx], key, max, n);
        }
    }
    return root;
}

void inorder(Node* root)
{
    if(root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    int preorder[] = {7,5,4,6,8,9};
    int n = 6;
    int preorderIdx = 0;
    Node* root = constructBST(preorder, &preorderIdx, preorder[0], INT_MIN, INT_MAX, n);
    inorder(root);
    return 0;
}