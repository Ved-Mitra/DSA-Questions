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

TreeNode* deleteNode(TreeNode* root,int key)
{
    if(root==NULL)
        return NULL;
    if(root->data==key)
        return helper(root);
    TreeNode* dummy=root;
    while(root!=NULL)
    {
        if(root->data > key)
        {
            if(root->left!=NULL && root->left->data==key)
            {
                root->left=helper(root->left);
                break;
            }
            else
                root=root->left;
        }
        else
        {
            if(root->right!=NULL && root->right->data==key)
            {
                root->right=helper(root->right);
                break;
            }
            else
                root=root->right;
        }
    }
    return dummy;
}
TreeNode* helper(TreeNode* root)
{
    if(root->left==NULL)
        return root->right;
    else if(root->right==NULL)
        return root->left;
    TreeNode* rightChild=root->right;
    TreeNode* lastRight=findLastRight(root->left);
    lastRight->right=rightChild;
    return root->left;
}
TreeNode* findLastRight(TreeNode* root)
{
    if(root->right==NULL)
        return root;
    return findLastRight(root->right);
}



int main()
{
    
}