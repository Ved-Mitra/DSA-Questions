#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int val)
    {
        data=val;
        left=nullptr;
        right=nullptr;
    }
};

//find the lowest value in tree with val>=key

TreeNode* ceil(int key,TreeNode* root)
{
    TreeNode* node=root,*prev=root;
    while(node && key>node->data)
    {
        prev=node;
        if(key<node->data)
            node=node->left;
        else if(key>node->data)
            node=node->right;
        else
        {
            return node;
        }
    }
    return prev;
}

int main()
{
    
}