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

//ME
//TC-O(2n)
//SC-O(n)
bool findTarget_ME(TreeNode* root, int k)
{
    if(root==NULL)
        return false;
    if(root->left==NULL && root->right==NULL)
        return false;
    vector<int> inorder;
    stack<TreeNode*> st;
    TreeNode* curr=root;
    while(true)
    {
        if(curr)
        {
            st.push(curr);
            curr=curr->left;
        }
        else
        {
            if(st.empty())
                break;
            TreeNode* temp=st.top();
            st.pop();
            inorder.push_back(temp->data);
            curr=temp->right;

        }
    }
    int n=inorder.size();
    int i=0,j=n-1;
    while(i<j)
    {
        int val=inorder[i]+inorder[j];
        if(val==k)
            return true;
        else if(val<k)
            i++;
        else
            j--;
    }
    return false;
}

//STRIVER
//TC-O(n)
//SC-O(1)
bool findTarget(TreeNode* root,int k)
{
    if(root==NULL)
        return false;
    if(root->left==NULL && root->right==NULL)
        return false;
    BSTIterator l(root,false);
    BSTIterator r(root,true);
    int i=l.next();//next
    int j=r.next();//before
    while(i<j)
    {
        if(i+j==k)
            return true;
        else if(i+j<k)
            i=l.next();
        else
            j=r.next();
    }
    return false;
}
class BSTIterator {
    stack<TreeNode*> st;
    //reverse->true -> before
    //reverse->false -> next
    bool reverse=true;
public:
    BSTIterator(TreeNode* root,bool isReverse) {
        pushAll(root);
        reverse=isReverse;
    }
    
    int next() {
        TreeNode* temp=st.top();
        st.pop();
        if(!reverse)
            pushAll(temp->right);
        else
            pushAll(temp->left);
        return temp->data;
    }
    
    bool hasNext() {
        if(st.empty())
            return false;
        return true;
    }

private:
    void pushAll(TreeNode* root)
    {
        for(;root;)
        {
            st.push(root);
            if(reverse==true)
                root=root->right;
            else
                root=root->left;
        }
    }
};



int main()
{
    
}