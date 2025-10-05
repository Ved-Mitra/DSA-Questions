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


bool isLeaf(TreeNode* root)
{
    if(root->left==NULL && root->right==NULL)
        return true;
    return false;
}

//BOUNDERY TRANSVERSAL--clockwise
//1. Left boundary excluding leaf nodes
void addLeftBoundary(TreeNode* root,vector<int> &ans)
{
    TreeNode* curr=root->left;
    while(curr)
    {
        if(!isLeaf(curr))
            ans.push_back(curr->data);
        if(curr->left)
            curr=curr->left;
        else
            curr=curr->right;
    }
}
//2. Leaf nodes
void addLeaf(TreeNode* root,vector<int> &ans)
{
    if(isLeaf(root))
    {
        ans.push_back(root->data);
        return;
    }
    if(root->left)
        addLeaf(root->left,ans);
    if(root->right)
        addLeaf(root->right,ans);
}
//3. Right boundary excluding leaf nodes
void addRightBoundary(TreeNode* root,vector<int> &ans)
{
    TreeNode* curr=root;
    vector<int> temp;
    while(curr)
    {
        if(!isLeaf(curr))
            ans.push_back(curr->data);
        if(curr->right)
            curr=curr->right;
        else
            curr=curr->left;
    }
    for(int i=temp.size();i>=0;i--)
        ans.push_back(temp[i]);
}

vector<int> boundaryTransversal (TreeNode* root)
{
    vector<int> ans;
    if(root==NULL)
        return ans;
    if(!isLeaf(root))
        ans.push_back(root->data);
    addLeftBoundary(root,ans);//O(H)
    addLeaf(root,ans);//O(n)
    addRightBoundary(root,ans);//O(H)
    //H-- height of tree
    //n-- nodes of tree
    return ans;
}




int main()
{
    
}