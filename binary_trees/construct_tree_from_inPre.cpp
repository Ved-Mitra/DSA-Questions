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

TreeNode* build(vector<int> &preorder,int preStart,int preEnd,vector<int> &inorder,int inStart,int inEnd,unordered_map<int,int> &hash)
{
    if(preStart>preEnd || inStart>inEnd)
        return NULL;
    
    TreeNode* root=new TreeNode(preorder[preStart]);

    int inRoot=hash[root->data];
    int numsLeft=inRoot-inStart;
    
    root->left=build(preorder,preStart+1,preStart+numsLeft,inorder,inStart,inRoot-1,hash);
    root->right=build(preorder,preStart+numsLeft+1,preEnd,inorder,inRoot+1,inEnd,hash);

    return root;
}

TreeNode* buildTree(vector<int> &preorder,vector<int> &inorder)
{
    unordered_map<int,int> hash;//value,index in inorder
    int n=inorder.size();
    for(int i=0;i<n;i++)
        hash.insert({inorder[i],i});
    TreeNode* root=build(preorder,0,n-1,inorder,0,n-1,hash);
    return root;
}

int main()
{
    
}