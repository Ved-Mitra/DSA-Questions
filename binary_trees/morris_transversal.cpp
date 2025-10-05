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

//MORRIS TRANSVERSAL -- Threaded Binary Tree
//TC-O(n)
//SC-O(1)

//INORDER
/*1st case
left!=NULL  
print()
->right
*/
/*2nd case
before going to left connect the rightmost guy on left subtree to curr, then curr=cuur->left
if thread already exits i.e. curr=rightmost node of left subtree, then remove the thread
*/
vector<int> inorder(TreeNode* root)
{
    vector<int> inorder;
    TreeNode* curr=root;
    while(curr!=NULL)
    {
        if(curr->left==NULL)
        {
            inorder.push_back(curr->data);
            curr=curr->right;
        }
        else
        {
            TreeNode* prev=curr->left;
            while(prev->right && prev->right!=curr)
            {
                prev=prev->right;
            }
            if(prev->right==NULL)
            {
                prev->right=curr;
                curr=curr->left;
            }
            else
            {
                prev->right=NULL;
                inorder.push_back(curr->data);
                curr=curr->right;
            }
        }
    }
    return inorder;
}
vector<int> preorder(TreeNode* root)
{
    vector<int> preorder;
    TreeNode* curr=root;
    while(curr!=NULL)
    {
        if(curr->left==NULL)
        {
            preorder.push_back(curr->data);
            curr=curr->right;
        }
        else
        {
            TreeNode* prev=curr->left;
            while(prev->right && prev->right!=curr)
            {
                prev=prev->right;
            }
            if(prev->right==NULL)
            {
                prev->right=curr;
                preorder.push_back(curr->data);
                curr=curr->left;
            }
            else
            {
                prev->right=NULL;
                curr=curr->right;
            }
        }
    }
    return preorder;
}


int main()
{
    
}