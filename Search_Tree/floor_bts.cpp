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

//return the lowest node with key>=val

TreeNode* floor(int key , TreeNode* root)
{
    TreeNode* node=root,*prev=root;
    while(node)
    {
        if(key==node->data)
            return node;
        else if(key>node->data)
        {
            prev=node;
            node=node->right;
        }
        else
            node=node->left;
    }
    return node;
}



int main()
{
    
}