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

vector<vector<int>> verticalTransversal(TreeNode* root)
{
    map<int,map<int,multiset<int>>> nodes; //vertical level multiset
    queue<pair<TreeNode*,pair<int,int>>> todo; //node column level
    todo.push({root,{0,0}});
    while(!todo.empty())
    {
        auto p=todo.front();
        todo.pop();
        TreeNode* node=p.first;
        int x=p.second.first;
        int y=p.second.second;
        nodes[x][y].insert(node->data);
        if(node->left)
            todo.push({node->left,{x-1,y+1}});
        if(node->right)
            todo.push({node->right,{x+1,y+1}});
    }
    vector<vector<int>> ans;
    for(auto p:nodes)
    {
        vector<int> col;
        for(auto q:p.second)
        {
            col.insert(col.end(),q.second.begin(),q.second.end());
        }
        ans.push_back(col);
    }
    return ans;
}





int main()
{
    
}