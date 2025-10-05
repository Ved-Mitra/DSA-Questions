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

//COMPLETE BINARY TREE
//number of nodes in the complete subtree is 2^h-1

int countNodes(TreeNode* root)
{
    if(root==NULL)
        return 0;
    
    int lh=findHeightLeft(root);
    int rh=findHeightRight(root);

    if(lh==rh)
        return (1<<lh)-1;
    
    return 1+countNodes(root->left) + countNodes(root->right);
}
int findHeightLeft(TreeNode* node)
{
    int hght=0;
    while(node)
    {
        hght++;
        node=node->left;
    }
    return hght;
}
int findHeightRight(TreeNode* node)
{
    int hght=0;
    while(node)
    {
        hght++;
        node=node->right;
    }
    return hght;
}


//ME
bool isLeaf(TreeNode* node)
{
    if(node->left || node->right)
        return false;
    return true;
}
int countNodes_ME(TreeNode* root)
{
    if(root==NULL)
        return 0;
    queue<TreeNode*> q;
    q.push(root);
    int cnt=1;
    while(!q.empty())
    {
        TreeNode* temp=q.front();
        q.pop();
        if(temp->left)
        {
            cnt++;
            if(!isLeaf(temp->left))
                q.push(temp->left);
        }
        if(temp->right)
        {
            cnt++;
            if(!isLeaf(temp->right))
                q.push(temp->right);
        }
    }
    return cnt;
}





int main()
{

}