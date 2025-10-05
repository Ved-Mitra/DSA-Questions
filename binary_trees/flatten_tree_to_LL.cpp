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

//Recursive
TreeNode* back=NULL;
void flatten_recursive(TreeNode* root)
{
    //TC-O(N)
    //SC-O(N)
    if(root==NULL)
        return;
    flatten_recursive(root->right);
    flatten_recursive(root->left);
    root->right=back;
    root->left=NULL;
    back=root;
}

void flatten_iterative1(TreeNode* root)
{
    //TC-O(N)
    //SC-O(N)
    if(root==NULL)
        return;
    stack<TreeNode*>st;
    st.push(root);
    while(!st.empty())
    {
        TreeNode* curr=st.top();
        st.pop();
        if(curr->right)
            st.push(curr->right);
        if(curr->left)
            st.push(curr->left);
        if(!st.empty())
            curr->right=st.top();
        curr->left=NULL;
    }
}

void flatten_iterative2(TreeNode* root)
{
    //TC-O(n)
    //SC-O(1)
    //MORRIS TRANSVERSAL
    if(root==NULL)
        return;
    TreeNode* curr=root;
    while(curr!=NULL)
    {
        if(curr->left!=NULL)
        {
            TreeNode* prev=curr->left;
            while(prev->right)
                prev=prev->right;
            prev->right=curr->right;
            curr->right=curr->left;
            curr->left=NULL;
        }
        curr=curr->right;
    }
}



int main()
{
    
}