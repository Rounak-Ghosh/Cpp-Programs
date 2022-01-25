#include<iostream>
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

Node* sortedArraytoBST(int arr[], int start, int end)
{
    if(start > end)
        return NULL;
    
    int mid = (start + end) / 2;
    Node* root = new Node(arr[mid]);

    root->left = sortedArraytoBST(arr, start, mid-1);
    root->right = sortedArraytoBST(arr, mid+1, end);

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
    int arr[] = {10,20,30,40,50};
    Node* root = sortedArraytoBST(arr,0,4);
    inorder(root);
    return 0;
}