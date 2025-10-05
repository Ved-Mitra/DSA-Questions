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


class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans="";
        if(root==NULL)
            return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode* node=q.front();
                q.pop();

                if(node==NULL)
                    ans+='*';
                else
                {
                    ans+=(to_string(node->data));
                    q.push(node->left);
                    q.push(node->right);
                }
                ans+=',';
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        //TC-O(N)
        //SC-O(N)
        int n=data.size();
        if(n==0)
            return NULL;
        stringstream s(data);//makes string as object
        string str;
        getline(s,str,',');//iterate string with elimiter as ','
        TreeNode* root=new TreeNode(stoi(str));//stoi-converts string to integer
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* node=q.front();
            q.pop();

            getline(s,str,',');
            if(str=="*")
                node->left=NULL;
            else
            {
                TreeNode* leftNode=new TreeNode(stoi(str));
                node->left=leftNode;
                q.push(leftNode);
            }

            getline(s,str,',');
            if(str=="*")
                node->right=NULL;
            else
            {
                TreeNode* rightNode=new TreeNode(stoi(str));
                node->right=rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
};


int main()
{
    
}