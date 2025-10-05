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

//1. swapped nodes are adjacent
//2. swapped nodes are not adjacent

//TC-O(N)
//SC-O(1)
TreeNode* first;
TreeNode* back;
TreeNode* middle;
TreeNode* last;

void inorder(TreeNode* root)
{
    if(root==NULL)
        return;
    
    inorder(root->left);
    if(back!=NULL && (root->data < back->data))
    {
        //if this is the first violation, mark these two nodes as 'first' and 'middle'
        if(first==NULL)
        {
            first=back;
            middle=root;
        }

        //if this is secodn violation , mark this node as last
        else
            last=root;
    }

    //mark this node as previous
    back=root;
    inorder(root->right);
}
void recoverTree(TreeNode* root)
{
    first=middle=last=NULL;
    back=new TreeNode(INT_MIN);
    inorder(root);
    if(first && last)
        swap(first->data,middle->data);
    else if(first && middle)
        swap(first->data,middle->data);
}

//BRUTE
//store inorder and then mark the violations

int main()
{
    
}