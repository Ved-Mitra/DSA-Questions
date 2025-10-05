#include<bits/stdc++.h>
using namespace std;

/*TREE

        1
       / \
      2   3
     /\   /\
    4  5 6  7

*/
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


/*BFS -- Breadth first search
goes level wise
1  2 3  4 5 6 7
*/
vector<vector<int>> levelwiseTransversal(TreeNode* root)
{
    //TC-O(n)
    //SC-O(n)
    queue<TreeNode*> q;
    vector<vector<int>> ans;
    if(root==NULL)
        return ans;
    q.push(root);
    while(!q.empty())
    {
        int n=q.size();
        vector<int>level;
        for(int i=0;i<n;i++)
        {
            TreeNode* temp=q.front();
            q.pop();
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
            level.push_back(temp->data);
        }
        ans.push_back(level);
    }
    return ans;
}


/*DFS -- DEPTH FIRST SEARCH

1. Inorder Transversal (left root right)   in--root between
                       4 2 5  1    6 3 7

2. Pre-order Transversal (root left right)  pre--root first
                           1  2 4 5  3 6 7

3. Post-order Transversal(left right root)  post--root last
                          4 5 2 6 7 3  1

*/
void inorderTransversal(TreeNode* root)
{
    //TC-O(n)
    //SC-O(n)
    if(root==NULL)
        return ;
    inorderTransversal(root->left);
    cout << root->data << " ";
    inorderTransversal(root->right);
}
void preoderTransversal(TreeNode* root) //ro ot left right
{
    //TC-O(n)
    //SC-O(n)
    TreeNode* temp=root;
    if(temp==nullptr)
        return ;
    cout << root->data << " ";
    preoderTransversal(root->left);
    preoderTransversal(root->right);
}
void postorderTransversal(TreeNode* root)
{
    //TC-O(n)
    //SC-O(n)
    if(root==NULL)
        return ;
    postorderTransversal(root->left);
    postorderTransversal(root->right);
    cout << root->data << " ";
}

void inorderTransversalIterative(TreeNode* root)
{
    if(root==NULL)
        return;
    stack<TreeNode*> st;
    TreeNode* TreeNode=root;
    while(true)
    {
        if(TreeNode)
        {
            st.push(TreeNode);
            TreeNode=TreeNode->left;
        }
        else
        {
            if(st.empty())
                break;
            TreeNode=st.top();
            st.pop();
            cout << TreeNode->data << " ";
            TreeNode=TreeNode->right;
        }
    }
}
void preorderTransversalIterative(TreeNode* root)
{
    stack<TreeNode*> st;
    if(root==NULL)
        return ;
    st.push(root);
    while(!st.empty())
    {
        TreeNode* temp=st.top();
        st.pop();
        cout << temp->data;
        if(temp->right)
            st.push(temp->right);
        if(temp->left)
            st.push(temp->left);
    }
}
void postorderTransversalIterative(TreeNode* root)
{
    if(root==NULL)
        return;

    //2 stacks
    stack<TreeNode*>st1,st2;
    st1.push(root);
    while(!st1.empty())
    {
        root=st1.top();
        st1.pop();
        st2.push(root);
        if(root->left)
            st1.push(root->left);
        if(root->right)
            st1.push(root->right);
    }
    while(!st2.empty())
    {
        cout << st2.top()->data << " ";
        st2.pop();
    }

    //1 stack
    stack<TreeNode*> st;
    TreeNode* cur=root;
    while(cur!=NULL || !st.empty())
    {
        if(cur!=NULL)
        {
            st.push(cur);
            cur=cur->left;
        }
        else
        {
            TreeNode* temp=st.top()->right;
            if(temp==NULL)
            {
                temp=st.top();
                st.pop();
                cout << temp->data << " ";
                while(!st.empty() && temp==st.top()->right)
                {
                    temp=st.top();
                    st.pop();
                    cout << temp->data << " ";
                }
            }
            else
                cur=temp;
        }
    }
}

void allTransverse(TreeNode* root)
{
    vector<int> preorder,inorder,postorder;
    stack<pair<TreeNode*,int>> st;
    st.push({root,1});
    if(root==NULL)
        return;
    while(!st.empty())
    {
        auto it=st.top();
        st.pop();
        
        if(it.second==1)//pre
        {
            preorder.push_back(it.first->data);
            it.second++;
            st.push(it);
            if(it.first->left)
                st.push({it.first->left,1});
        }
        else if(it.second==2)//in
        {
            inorder.push_back(it.first->data);
            it.second++;
            st.push(it);
            if(it.first->right)
                st.push({it.first->right,1});
        }
        else//post
        {
            postorder.push_back(it.first->data);
        }
    }
}

int main()
{
    
}