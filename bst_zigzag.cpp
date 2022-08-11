#include<iostream>
#include<stack>
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

void zigzag(Node* root)
{
    if(root == NULL)
        return;

    stack<struct Node*> currentLevel;
    stack<struct Node*> nextLevel;

    bool LeftToRight = true;

    currentLevel.push(root);
    
    while(!currentLevel.empty())
    {
        Node* temp = currentLevel.top();
        currentLevel.pop();
           
        if(temp)
        {
            cout << temp->data << " ";
        
            if(LeftToRight)
            {
                if(temp->left)
                    nextLevel.push(temp->left);
                if(temp->right)
                    nextLevel.push(temp->right);
            }
            else
            {
                if(temp->right)
                    nextLevel.push(temp->right);
                if(temp->left)
                    nextLevel.push(temp->left);
            }
        }

        if(currentLevel.empty())
        {
            LeftToRight = !LeftToRight;
            swap(currentLevel, nextLevel);
        }
    }
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->right = new Node(4);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);
    root->right = new Node(3);
    root->right->right = new Node(5);
    zigzag(root);
    return 0;
}