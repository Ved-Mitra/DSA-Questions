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

//ME
TreeNode* insertIntoBST(TreeNode* root, int val)
{
    TreeNode* insertNode=new TreeNode(val);
    if(root==NULL)
        return insertNode;
    TreeNode* node=root,*prev=root;
    while(node)
    {
        prev=node;
        if(val>node->data)
            node=node->right;
        else
            node=node->left;
    }
    if(val>prev->data)
        prev->right=insertNode;
    else
        prev->left=insertNode;
    return root;


    //STRIVER
    if(root==NULL)
        return new TreeNode(val);
    TreeNode* curr=root;
    while(true)
    {
        if(curr->data<=val)
        {
            if(curr->right!=NULL)
                curr=curr->right;
            else
            {
                curr->right=new TreeNode(val);
                break;
            }
        }
        else
        {
            if(curr->left!=NULL)
                curr=curr->left;
            else
            {
                curr->left= new TreeNode(val);
                break;
            }
        }
    }
    return root;
}



int main()
{
    
}