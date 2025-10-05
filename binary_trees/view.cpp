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

vector<int> TopView(TreeNode* root)
{
    vector<int> ans;
    if(root==NULL)
        return ans;
    map<int,TreeNode*> mpp;
    queue<pair<TreeNode*,int>> q;
    q.push({root,0});
    while(!q.empty())
    {
        auto p=q.front();
        q.pop();
        int x=p.second;
        if(mpp.find(x)==mpp.end())
        {
            mpp[x]=p.first;
        }
        if(p.first->left)
            q.push({p.first->left,x-1});
        if(p.first->right)
            q.push({p.first->right,x+1});
    }
    for(auto p:mpp)
    {
        ans.push_back(p.second->data);
    }
    return ans;
}
vector<int> BottomView(TreeNode* root)
{
    vector<int> ans;
    if(root==NULL)
        return ans;
    map<int,TreeNode*> mpp;
    queue<pair<TreeNode*,int>> q;
    q.push({root,0});
    while(!q.empty())
    {
        auto p=q.front();
        q.pop();
        int x=p.second;
        mpp[x]=p.first;
        if(p.first->left)
            q.push({p.first->left,x-1});
        if(p.first->right)
            q.push({p.first->right,x+1});
    }
    for(auto p:mpp)
    {
        ans.push_back(p.second->data);
    }
    return ans;
}
vector<int> RightView(TreeNode* root)
{
    //TC-O(n)
    //SC-O(n)
    vector<int> ans;
    if(root==NULL)
        return ans;
    map<int,TreeNode*> mpp;
    queue<pair<TreeNode*,int>> q;
    q.push({root,0});
    while(!q.empty())
    {
        auto p=q.front();
        q.pop();
        int y=p.second;
        if(mpp.find(y)==mpp.end())
            mpp[y]=p.first;
        if(p.first->right)
            q.push({p.first->right,y+1});
        if(p.first->left)
            q.push({p.first->left,y+1});
    }
    for(auto p:mpp)
    {
        ans.push_back(p.second->data);
    }
    return ans;
}
vector<int> RightViewRecursive(TreeNode* root)
{
    vector<int> ans;
    if(root==NULL)
        return ans;
    helperRight(root,0,ans);
    return ans;
}
void helperRight(TreeNode* node,int level,vector<int> &ans)
{
    if(node==NULL)
        return;
    if(level==ans.size())
        ans.push_back(node->data);
    helperRight(node->right,level+1,ans);
    helperRight(node->left,level+1,ans);
}
vector<int> LeftView(TreeNode* root)
{
    vector<int> ans;
    if(root==NULL)
        return ans;
    helperLeft(root,0,ans);
    return ans;
}
void helperLeft(TreeNode* node,int level,vector<int> &ans)
{
    if(node==NULL)
        return;
    if(level==ans.size())
        ans.push_back(node->data);
    helperLeft(node->left,level+1,ans);
    helperLeft(node->right,level+1,ans);
}




int main()
{
    
}