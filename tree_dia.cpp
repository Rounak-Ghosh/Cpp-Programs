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

int findDiameter(Node* root)
{
    if(root == NULL)
        return 0;

    int leftHT = findHeight(root->left);
    int rightHT = findHeight(root->right);
    int currDia = leftHT + rightHT + 1;

    int leftDia = findDiameter(root->left);
    int rightDia = findDiameter(root->right);

    return max(currDia, max(leftDia, rightDia));
}

int findDia(Node* root, int* height)
{
    if(root == NULL)
        return 0;

    int leftHT = 0, rightHT = 0;
    int leftDia = findDia(root->left, &leftHT);
    int rightDia = findDia(root->right, &rightHT);

    int currDia = leftHT + rightHT + 1;
    *height = max(leftHT, rightHT) + 1;

    return max(currDia, max(leftDia, rightDia));
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->left->right->right = new Node(5);
    root->left->left->left = new Node(6);
    root->left->left->left->left = new Node(7);

    cout << findDiameter(root) << "\n";     // Brute Force - O(N^2)
    int height = 0;
    cout << findDia(root, &height);      // Optimised Approach - O(N)

    return 0;
}