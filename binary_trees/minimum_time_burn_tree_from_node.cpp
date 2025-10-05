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

TreeNode* parent_track(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &mpp,int x)
{
    queue<TreeNode*>q;
    TreeNode* node;
    q.push(root);
    while(!q.empty())
    {
        TreeNode* temp=q.front();
        q.pop();
        if(temp->data==x)
            node=temp;
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
    return node;
}
int minimumTimeBurnTreeFromNode(TreeNode* root,int start)
{
    if(root==NULL)
        return 0;
    unordered_map<TreeNode*,TreeNode*> mpp;
    TreeNode* node=parent_track(root,mpp,start);
    unordered_map<TreeNode*,bool>visited;
    int time=0;
    queue<TreeNode*>q;
    q.push(node);
    visited[node]=true;
    while(!q.empty())
    {
        int n=q.size();
        int flag=0;
        for(int i=0;i<n;i++)
        {
            TreeNode* temp=q.front();
            q.pop();
            if(mpp.find(temp)!=mpp.end() && !visited[mpp[temp]])
            {
                q.push(mpp[temp]);
                visited[mpp[temp]]=true;
                flag=1;
            }
            if(temp->left && !visited[temp->left])
            {
                q.push(temp->left);
                visited[temp->left]=true;
                flag=1;
            }
            if(temp->right && !visited[temp->right])
            {
                q.push(temp->right);
                visited[temp->right]=true;
                flag=1;
            }
        }
        if(flag)
            time++;
    }
    return time;
}





int main()
{

}