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

//in binary serach tree L<N<R (not equal)
//N--node
//L--left
//R--right

//IDEALLY NO DUPLICATES BUT IF I WANT THEM WE CAN USE L<=N<R

TreeNode* searchBST(TreeNode* root,int val)
{
    if(root==NULL)
        return NULL;
    TreeNode* node=root;
    while(node)
    {
        if(val>node->data)
            node=node->right;
        else if(val<node->data)
            node=node->left;
        else
            break;
    }
    return node;
}



int main()
{
    
}