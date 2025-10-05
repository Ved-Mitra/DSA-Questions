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

//STRIVER
TreeNode* lowestCommonAncestor(TreeNode* root,TreeNode* p,TreeNode* q)
{
    if(root==NULL)
        return NULL;
    if(root==p)
        return root;
    if(root==q)
        return root;
    TreeNode* lt=lowestCommonAncestor(root->left,p,q);
    TreeNode* rt=lowestCommonAncestor(root->right,p,q);
    if(lt && rt)
        return root;
    return lt?lt:rt;
}


//ME
bool helper(TreeNode* root,TreeNode* goal,vector<TreeNode*> &st)
{
    if(root==NULL)
        return false;
    st.push_back(root);
    if(root==goal)
        return true;
    if(helper(root->left,goal,st) || helper(root->right,goal,st))
        return true;
    st.pop_back();
    return false;
}
TreeNode* lowestCommonAncestor_ME(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root==NULL)
        return NULL;
    vector<TreeNode*> v1,v2;
    helper(root,p,v1);
    helper(root,q,v2);
    int n=min(v1.size(),v2.size());
    TreeNode* ans=root;
    for(int i=0;i<n;i++)
    {
        if(v1[i]==v2[i])
            ans=v1[i];
        else
            break;
    }
    return ans;
}


int main()
{
    
}