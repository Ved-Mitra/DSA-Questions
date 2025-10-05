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

bool valid(TreeNode* root,long minVal,long maxVal)
{
    if(root==NULL)
        return true;
    if(root->data <=minVal || root->data>=maxVal)
        return false;
    
    return valid(root->left,minVal,root->data) && valid(root->right,root->data,maxVal);
}
bool isValidBST(TreeNode* root)
{
    if(root==NULL)
        return true;
    return valid(root,LONG_MIN,LONG_MAX);
}

int main()
{

}