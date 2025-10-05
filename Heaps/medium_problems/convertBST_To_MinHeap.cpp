#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
   int data;
   TreeNode *left;
   TreeNode *right;

   TreeNode(int val, TreeNode *left = nullptr, TreeNode *right = nullptr)
   {
       data = val;
       this->left = left;
       this->right = right;
   }
};


vector<int> BST_To_MinHeap(TreeNode* root)
{
    vector<int> ans;
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
            ans.push_back(curr->data);
            curr=curr->right;
        }
    }
    return ans;
}






int main()
{

}