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

int height(TreeNode* root,int *maxSum)
{
    if(root==NULL)
        return 0;
    int sum=root->data;
    int ls=height(root->left,maxSum);
    int rs=height(root->right,maxSum);
    *maxSum=max(*maxSum,max(ls+rs+sum,max(sum,sum+max(ls,rs))));
    return max(sum,sum+max(ls,rs));
}
int maxPathSum(TreeNode* root) {
    int maxSum=INT_MIN;
    height(root,&maxSum);
    return maxSum;
}




int main()
{
    
}