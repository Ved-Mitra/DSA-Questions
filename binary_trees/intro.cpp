#include<bits/stdc++.h>
using namespace std;

//when in heirchary of trees you can have at max 2 branches

//main node -- root
//branches -- children
//last node -- leaf node
//branch of a node -- subtree
//the node above the node -- ancestor


//Full binary tree -- each node has either 0 or 2 children
//complete binary tree -- (a) all levels are completely filled except the last level, (b) the last level has all node m left as possible
//perfect binary tree -- all leaf nodex are at same level
//balanced binary tree -- height of tree at max log n (n--nodes)
//degenerate binary tree -- one sided tree (like LL)

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    Node(int val)
    {
        data=val;
        left=nullptr;
        right=nullptr;
    }
};


int main()
{
    struct Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->right=new Node(5);

}