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


bool check(TreeNode* p,TreeNode* q)
{
    if(p==NULL || q==NULL)
        return p==q;
    bool res=(p->data==q->data) && check(p->left,q->right) && check(p->right,q->left);
    return res;
}
bool isSymmetric(TreeNode* root) {
    if(root==NULL)
        return true;
    return check(root->left,root->right);
}



int main()
{
    
}