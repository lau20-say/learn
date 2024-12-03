#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

void duyet(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    duyet(root->left);
    cout << root->data << " ";
    duyet(root->right);
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    duyet(root);

    return 0;
}