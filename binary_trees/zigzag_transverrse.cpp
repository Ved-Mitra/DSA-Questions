#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int data)
    {
        data=data;
        left=nullptr;
        right=nullptr;
    }
};

vector<vector<int>> zigzagLevelOrder(TreeNode* root)//ME
{
    vector<vector<int>> ans;
    if(root==NULL)
        return ans;
    stack<TreeNode*> st1,st2;
    st1.push(root);
    while(!st1.empty() || !st2.empty())
    {
        vector<int> level;
        if(st2.empty())
        {
            int n=st1.size();
            for(int i=0;i<n;i++)
            {
                TreeNode* temp=st1.top();
                st1.pop();
                level.push_back(temp->data);
                cout << temp->data << " ";
                if(temp->left)
                    st2.push(temp->left);
                if(temp->right)
                    st2.push(temp->right);
            }
        }
        else if(st1.empty())
        {
            int n=st2.size();
            for(int i=0;i<n;i++)
            {
                TreeNode* temp=st2.top();
                st2.pop();
                level.push_back(temp->data);
                cout << temp->data << " ";
                if(temp->right)
                    st1.push(temp->right);
                if(temp->left)
                    st1.push(temp->left);
            }
        }
        cout << endl;
        ans.push_back(level);
    }
    return ans;
}
vector<vector<int>> zigzagOrder(TreeNode* root)//STRIVER
{
    vector<vector<int>> ans;
    if(root==NULL)
        return ans;
    queue<TreeNode*> q;
    q.push(root);
    int flag=1;
    while(!q.empty())
    {
        int n=q.size();
        vector<int> level(n);
        //flag = 0   R->L
        //flag = 1   L->R

        for(int i=0;i<n;i++)
        {
            TreeNode* temp=q.front();
            q.pop();
            int index = flag?i:n-i-1;
            level[index]=temp->data;
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
        ans.push_back(level);
        flag=1-flag;
    }
    return ans;
}



int main()
{
    
}