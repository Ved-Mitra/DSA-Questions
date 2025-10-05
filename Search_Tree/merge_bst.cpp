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
//SC-O(n)
//TC-O(1)
class BSTIterator_ME {
    vector<int> vec;
    int index=0;
public:
    BSTIterator_ME(TreeNode* root) {
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
                curr=st.top();
                st.pop();
                vec.push_back(curr->data);
                curr=curr->right;
            }
        }
    }
    
    int next() {
        return vec[index++];
    }
    
    bool hasNext() {
        if(index==vec.size())
            return false;
        return true;
    }
};

//STRIVER
//SC-O(h)
//TC-O(1)
class BSTIterator {
    stack<TreeNode*> st;
public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode* temp=st.top();
        st.pop();
        pushAll(temp->right);
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
        for(;root!=NULL;st.push(root),root=root->left);
    }
};
int main()
{

}