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


bool isSameTree(TreeNode* p, TreeNode* q)
{
    if(p==NULL || q==NULL)
       return p==q;
    else if(p->data!=q->data)
        return false;
    bool res=(isSameTree(p->left,q->left) && isSameTree(p->right,q->right));
    return res;
}



int main()
{
    
}