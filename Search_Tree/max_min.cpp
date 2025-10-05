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


vector<int> maxMin(TreeNode* root)
{
    if (root == NULL)
        return {};

    TreeNode* minNode = root;
    TreeNode* maxNode = root;

    // Go to the leftmost node for min
    while (minNode->left) {
        minNode = minNode->left;
    }

    // Go to the rightmost node for max
    while (maxNode->right) {
        maxNode = maxNode->right;
    }

    return {minNode->data, maxNode->data};
    
}



int main()
{
    
}