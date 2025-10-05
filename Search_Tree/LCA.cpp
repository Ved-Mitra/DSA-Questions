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

//LCA-lowest common ancestor

//STRIVER
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    if(root==NULL)
        return NULL;
    
    if(p->data<root->data && q->data<root->data)
        return lowestCommonAncestor(root->left,p,q);
    else if(p->data>root->data && q->data>root->data)
        return lowestCommonAncestor(root->right,p,q);
    return root;
    /*if(root->data<=maxx && root->data>=minn)
        return root;*/
}

//ME
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    if(root==NULL)
        return NULL;
    int maxx=max(p->data,q->data);
    int minn=min(p->data,q->data);
    if(root->data<=maxx && root->data>=minn)
        return root;
    TreeNode* lt=NULL,*rt=NULL;
    if(p->data<root->data && q->data<root->data)
        lt=lowestCommonAncestor(root->left,p,q);
    else
        rt=lowestCommonAncestor(root->right,p,q);
    return lt?lt:rt;
}
int main()
{

}