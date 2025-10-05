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



int widthOfBinaryTree(TreeNode* root)
{
    if(root==NULL)
        return 0;
    int ans=0;
    queue<pair<TreeNode*,long>> q;
    q.push({root,0});
    while(!q.empty())
    {
        int size=q.size();
        int minn=q.front().second;
        int first,last;
        for(int i=0;i<size;i++)
        {
            int curr_id=q.front().second-minn;
            TreeNode* node=q.front().first;
            q.pop();
            if(i==0)
                first=curr_id;
            if(i==size-1)
                last=curr_id;
            if(node->left)
                q.push({node->left,(long)curr_id*2+1});
            if(node->right)
                q.push({node->right,2*curr_id+2});
        }
        ans=max(ans,last-first+1);
    }
    return ans;
}


int main()
{
    
}