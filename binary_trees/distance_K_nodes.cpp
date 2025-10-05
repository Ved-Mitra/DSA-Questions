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

vector<int> distanceK(TreeNode* root, TreeNode* target, int k)
{
    vector<int> ans;
    if(root==NULL)
        return ans;
    unordered_map<TreeNode*,TreeNode*> mpp;//child,parent;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty())
    {
        TreeNode* temp=q.front();
        q.pop();
        if(temp->left)
        {
            mpp[temp->left]=temp;
            q.push(temp->left);
        }
        if(temp->right)
        {
            mpp[temp->right]=temp;
            q.push(temp->right);
        }
    }
    map<TreeNode*,bool>visited;
    q.push(target);
    visited[target]=true;
    while(k>0)
    {
        int n=q.size();
        for(int i=0;i<n;i++)
        {
            TreeNode* temp=q.front();
            q.pop();
            if(mpp.find(temp)!=mpp.end() && !visited[mpp[temp]])
            {
                q.push(mpp[temp]);
                visited[mpp[temp]]=true;
            }
            if(temp->left && !visited[temp->left])
            {
                q.push(temp->left);
                visited[temp->left]=true;
            }
            if(temp->right && !visited[temp->right])
            {
                q.push(temp->right);
                visited[temp->right]=true;
            }
        }
        k--;
    }
    while(!q.empty())
    {
        ans.push_back(q.front()->data);
        q.pop();
    }
    return ans;
}

int main()
{

}