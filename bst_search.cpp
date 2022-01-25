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

Node* searchInBST(Node* root, int key) 
{
    if(root== NULL)
        return NULL;

    else if(root->data == key)
        return root;
    
    else if(root->data > key)
        return searchInBST(root->left, key);
    
    else
        return searchInBST(root->right, key);
}

Node* inorderSucc(Node* root) 
{
    Node* curr = root;
    while(curr && curr->left != NULL)
        curr = curr->left;
    return curr;
}

Node* deleteInBST(Node* root, int key)
{
    // Finding the node = key
    if(key < root->data)    // key is in left
        root->left = deleteInBST(root->left, key);
    else if(key > root->data)   // key is in right
        root->right = deleteInBST(root->right, key);
    
    else
    {   // Node is either leaf or has one child - Case 1 & 3
        if(root->left == NULL) 
        {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            Node* temp = root->left;
            free(root);
            return temp; 
        } 
        // Node has two children
        Node* temp = inorderSucc(root->right);
        root->data = temp->data;
        root->right = deleteInBST(root->right, temp->data);  
    }
}

int main()
{
    Node* root = new Node(5);
    root->left = new Node(1);
    root->right = new Node(7);
    root->left->right = new Node(3);
    root->left->right->left = new Node(2);
    root->left->right->right = new Node(4);
    /*
            5
           / \
          1   7
           \     
            3
           / \
          2   4
    */

    if(searchInBST(root, 5) == NULL)
        cout << "\nKey doesn't exist";
    else
        cout << "\nKey exists";

    deleteInBST(root, 5);

    if(searchInBST(root, 5) == NULL)
        cout << "\nKey doesn't exist";
    else
        cout << "\nKey exists";

    return 0;
}