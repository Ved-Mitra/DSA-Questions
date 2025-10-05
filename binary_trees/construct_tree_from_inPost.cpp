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

TreeNode* build(vector<int> &inorder,int inStart,int inEnd,vector<int> &postorder,int postStart,int postEnd,unordered_map<int,int> &hash)
{
    if(inStart>inEnd || postStart>postEnd)
        return NULL;
    
    TreeNode* root=new TreeNode(postorder[postEnd]);
    int inRoot=hash[root->data];
    int numsLeft=inRoot-inStart;

    root->left=build(inorder,inStart,inRoot-1,postorder,postStart,postStart+numsLeft-1,hash);
    root->right=build(inorder,inRoot+1,inEnd,postorder,postStart+numsLeft,postEnd-1,hash);

    return root;
}
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
{
    int n=inorder.size();
    unordered_map<int,int> hash;
    for(int i=0;i<n;i++)
        hash[inorder[i]]=i;
    
    TreeNode* root=build(inorder,0,n-1,postorder,0,n-1,hash);

    return root;
}



int main()
{
    
}