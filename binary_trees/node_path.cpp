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

//output the path from root to node
vector<int> rootToNodePath(TreeNode* root,int node)
{
    vector<int> ans;
    if(root==NULL)
        return ans;
    getPath(root,ans,node);
    return ans;
}
bool getPath(TreeNode* root,vector<int> &ans,int x)
{
    if(!root)
        return false;
    ans.push_back(root->data);

    if(root->data==x)
        return true;
    if(getPath(root->left,ans,x) || getPath(root->right,ans,x))
        return true;
    
    ans.pop_back();
    return false;
}

vector<int> RootToLeafPath(TreeNode* root,int x)
{

}



int main()
{
    
}