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

int findHeight(Node* root) 
{
    if(root == NULL)
        return 0;
    int leftHT = findHeight(root->left);
    int rightHT = findHeight(root->right);
    return max(leftHT, rightHT) + 1;
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->left->right->right = new Node(5);
    root->left->left->right = new Node(6);
    root->left->left->left = new Node(7);
    root->left->left->left->left = new Node(8);

    cout << findHeight(root);

    return 0;
}