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

int check(TreeNode* root)
{
    if(root==NULL)
        return 0;
    int lh=check(root->left);
    if(lh==-1)
        return -1;
    int rh=check(root->right);
    if(rh==-1)
        return -1;
    
    if(abs(lh-rh)>1)
        return -1;
    return max(lh,rh)+1;
}

bool isBalanced(TreeNode* root)
{
    return check(root)!=-1;
}


int main()
{
    
}