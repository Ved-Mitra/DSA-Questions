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

int maxHeightOfTree_Iterative(TreeNode* root)
{
    //TC-O(n)
    if(root==NULL)
        return 0;
    int maxHeight=0;
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty())
    {
        int n=q.size();
        for(int i=0;i<n;i++)
        {
            TreeNode* temp=q.front();
            q.pop();
            if(temp->right)
                q.push(temp->right);
            if(temp->left)
                q.push(temp->left);
        }
        maxHeight++;
    }
    return maxHeight;
}
int maxHeightOfTree_Recursive(TreeNode* root)
{
    if(root==NULL)
        return 0;
    int lh=maxHeightOfTree_Recursive(root->left);
    int rh=maxHeightOfTree_Recursive(root->right);
    return 1+max(lh,rh);    
}


int main()
{
    
}
