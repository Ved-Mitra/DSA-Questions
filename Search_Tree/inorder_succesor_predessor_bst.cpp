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


TreeNode* inorderSuccessor(TreeNode* root,TreeNode* node)
{
    if(root==NULL)
        return NULL;
    TreeNode* successor=NULL;
    while(root!=NULL)
    {
        if(node->data>root->data)
            root=root->right;
        else
        {
            successor=root;
            root=root->left;
        }
    }
    return successor;
}
TreeNode* inorderpredecessor(TreeNode* root,TreeNode* node)
{
    TreeNode* predecessor=NULL;
    while(root!=NULL)
    {
        if(root->data>node->data)
            root=root->left;
        else
        {
            predecessor=root;
            root=root->right;
        }
    }
    return predecessor;
}
vector<TreeNode*> inorderSuccessorPredecessor(TreeNode* root,int val)
{
    //M-1
    //store inorder then binary search

}

int main()
{

}