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

int kthSmallest(TreeNode* root,int k)
{
    int cnt=0;
    return helper(root,k,&cnt)->data;
}

TreeNode* helper(TreeNode* root,int k,int*cnt)
{
    if(root==NULL)
        return NULL;
    TreeNode* nodeL=helper(root->left,k,cnt);
    *cnt=*cnt+1;
    if(*cnt==k)
        return root;
    TreeNode* nodeR=helper(root->right,k,cnt);
    return nodeL?nodeL:nodeR;
}

int numberOfNodes(TreeNode* root)
{
    if(root==NULL)
        return 0;
    int lh=numberOfNodes(root->left);
    int rh=numberOfNodes(root->right);
    return 1+lh+rh;
}
int kthLargest(TreeNode* root,int k)
{
    //kth largest=n-kth smallest
    int cnt=0;
    int n=numberOfNodes(root);
    return helper(root,n-k,&cnt)->data;
}

int main()
{
    
}