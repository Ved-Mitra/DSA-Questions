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

int diameter(TreeNode* root,int *dia)
{
    if(root==NULL)
        return 0;
    int lh=diameter(root->left,dia);
    int rh=diameter(root->right,dia);
    *dia=max(*dia,lh+rh);
    return 1+max(lh,rh);
}
int diameterOfBinaryTree(TreeNode* root) {
    int dia=0;
    diameter(root,&dia);
    return dia;
}




int main()
{
    
}