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

//node=left+right     (value)
//if node doesn't follows children sum you can add 1 any number of times
//convert the binary tree into a children sum property following binary tree

void childrenSumProperty(TreeNode* root)
{
    //TC-O(n)
    //SC-O(max{H,W})
    if(root==NULL)
        return;
    int child=0;
    if(root->left)
        child+=root->left->data;
    if(root->right)
        child+=root->right->data;
    if(child< root->data)
    {
        if(root->left)
            root->left->data=root->data;
        if(root->right)
            root->right->data=root->data;
    }
    else
        root->data=child;
    
    childrenSumProperty(root->left);
    childrenSumProperty(root->right);

    int total=0;
    if(root->left)
        total+=root->left->data;
    if(root->right)
        total+=root->right->data;
    if(root->left or root->right)
        root->data=total;    
}


int main()
{

}