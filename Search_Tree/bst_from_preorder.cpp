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

TreeNode* BSTFromPreorder_iterative(vector<int> &preorder)
{
    if(preorder.size()==0)
        return NULL;
    int index=0;
    TreeNode* root=new TreeNode(preorder[index]);
    index++;
    stack<TreeNode*> st;
    st.push(root);
    int n=preorder.size();
    while(index<n)
    {
        if(st.empty() || st.top()->data>preorder[index])
        {
            TreeNode* temp=new TreeNode(preorder[index]);
            st.top()->left=temp;
            st.push(temp);
            index++;
        }
        else
        {
            TreeNode* node=st.top();
            while(!st.empty() && index<n && st.top()->data<preorder[index])
            {
                node=st.top();
                st.pop();
            }
            node->right=new TreeNode(preorder[index]);
            index++;
            st.push(node->right);
        }
    }
    return root;
}

TreeNode* BSTFromPreorder_Recursive(vector<int> &preorder)
{
    int i=0;
    return build(preorder,i,INT_MAX);
}
TreeNode* build(vector<int> &preorder,int &i,int bound)
{
    if(i==preorder.size() || preorder[i]>bound)
        return NULL;
    TreeNode* root=new TreeNode(preorder[i++]);
    root->left=build(preorder,i,root->data);
    root->right=build(preorder,i,bound);
    return root;
}

int main()
{
    
}