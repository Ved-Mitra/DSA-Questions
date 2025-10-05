#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
    public:
        int data;
        int height;
        int size;
        TreeNode* left;
        TreeNode* right;

    TreeNode(int val)
    {
        data=val;
        size=1;
        height=1;
        left=nullptr;
        right=nullptr;
    }
};

int size(TreeNode* n)
{
    return n?n->size:0;
}
int height(TreeNode* n)
{
    return n?n->height:0;
}

void update(TreeNode* n)
{
    if(n)
    {
        n->size=1+size(n->left) + size(n->right);
        n->height=1+ max(height(n->left),height(n->right));
    }
}

TreeNode* rotateRight(TreeNode* x)
{
    TreeNode* y=x->left;
    TreeNode* T2=y->right;
    y->right=x;
    x->left=T2;
    update(x);
    update(y);
    return y;
}

TreeNode* rotateLeft(TreeNode* y)
{
    TreeNode* x=y->right;
    TreeNode* T2=x->left;
    x->left=y;
    y->right=T2;
    update(x);
    update(y);
    return x;
}

int balance (TreeNode* n)
{
    return n?(height(n->left)-height(n->right)):0;
}

TreeNode* loadBalancer(TreeNode* n)
{
    update(n);
    int balanceFactor=balance(n);
    if(balanceFactor>1)
    {
        if(balance(n->left)<0)
            rotateLeft(n->left);
        rotateRight(n);
    }
    else if(balanceFactor<-1)
    {
        if(balance(n->right)>0)
            rotateRight(n->right);
        rotateLeft(n);
    }
    return n;
}

TreeNode* insert(TreeNode* root,int key)
{
    if(root==NULL)
        return new TreeNode(key);
    if(key<=root->data)//considering duplicates
        root->left=insert(root->left,key);
    else if(key>root->data)
        root->right=insert(root->right,key);
    return loadBalancer(root);
}

TreeNode* minValueNode(TreeNode* n)
{
    TreeNode* temp=n;
    while(temp->left)
        temp=temp->left;
    return temp;
}

TreeNode* remove(TreeNode* root,int key)
{
    if(root==NULL)
        return NULL;
    if(key<root->data)
        root->left=remove(root->left,key);
    else if(key>root->data)
        root->right=remove(root->right,key);
    else
    {
        if(root->left!=NULL && root->right!=NULL)
        {
            //2 child case
            TreeNode* T1=root->right;
            TreeNode* successor=minValueNode(T1);
            root->data=successor->data;
            root->right=remove(root->right,successor->data);
        }
        else
        {
            TreeNode* temp = root->left ? root->left : root->right;
            if (temp == NULL)
            {
                // no child case
                delete root;
                return NULL;
            }
            else
            {
                // one child case
                TreeNode* toDelete = root;
                root = temp;      // promote child to root’s place
                delete toDelete;   // delete old root
            }
        }
    }
    return loadBalancer(root);
}

int getRank(TreeNode* root,int key)
{
    if(root==NULL)
        return -1;
    if(key<root->data)
        return getRank(root->left,key);
    else if(key>root->data)
    {
        return getRank(root->right,key) +1+ size(root->left);
    }
    else
        return 1+ size(root->left);
    return 0;
}

int getkth(TreeNode* root,int k)
{
    if(root==NULL || k<=0 || k>size(root))
        return -1;
    int leftRank=size(root->left);
    if(k==leftRank+1)
        return root->data;
    else if(k<=leftRank)
        return getkth(root->left,k);
    return getRank(root->right,k-leftRank +1);
}

void inorder(TreeNode* root,vector<int> &ans)
{
    if(root==NULL)
        return;
    inorder(root->left,ans);
    ans.push_back(root->data);
    inorder(root->right,ans);
}

int main()
{
    int n;
    cin >> n;
    TreeNode* root1=NULL;
    for(int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        root1=insert(root1,x);
    }

    int m;
    cin >> m;
    TreeNode* root2=NULL;
    for(int i=0;i<m;i++)
    {
        int x;
        cin >> x;
        root2=insert(root2,x);
    }

    vector<int> v2;
    inorder(root2,v2);

    for(int i=0;i<m;i++)//merging tree2 into tree 1
    {
        root1=insert(root1,v2[i]);
    }

    vector<int> ans;
    inorder(root1,ans);
    for(int &x:ans)
        cout << x << " ";
    
    return 0;
}