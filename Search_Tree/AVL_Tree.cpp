#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key, height, size;
    Node *left, *right;
    Node(int k) : key(k), height(1), size(1), left(nullptr), right(nullptr) {}
};

int height(Node *n) { return n ? n->height : 0; }
int size(Node *n) { return n ? n->size : 0; }

void update(Node *n)
{
    if (n)
    {
        n->height = 1 + max(height(n->left), height(n->right));
        n->size = 1 + size(n->left) + size(n->right);
    }
}

int balance(Node *n) { return n ? height(n->left) - height(n->right) : 0; }

Node *rotateRight(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;
    x->right = y;
    y->left = T2;
    update(y);
    update(x);
    return x;
}

Node *rotateLeft(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;
    y->left = x;
    x->right = T2;
    update(x);
    update(y);
    return y;
}

Node *balanceNode(Node *n)
{
    update(n);
    int bf = balance(n);
    if (bf > 1)
    {
        if (balance(n->left) < 0)
            n->left = rotateLeft(n->left);
        return rotateRight(n);
    }
    if (bf < -1)
    {
        if (balance(n->right) > 0)
            n->right = rotateRight(n->right);
        return rotateLeft(n);
    }
    return n;
}

Node *insert(Node *root, int key)
{
    if (!root)
        return new Node(key);
    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    else
        return root; // ignore duplicates
    return balanceNode(root);
}

Node *minValueNode(Node *node)
{
    Node *current = node;
    while (current->left)
        current = current->left;
    return current;
}

Node *remove(Node *root, int key)
{
    if (!root)
        return root;
    if (key < root->key)
        root->left = remove(root->left, key);
    else if (key > root->key)
        root->right = remove(root->right, key);
    else
    {
        if (!root->left || !root->right)
        {
            Node *temp = root->left ? root->left : root->right;
            if (!temp)
            {
                temp = root;
                root = nullptr;
            }
            else
                *root = *temp;
            delete temp;
        }
        else
        {
            Node *temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = remove(root->right, temp->key);
        }
    }
    if (!root)
        return root;
    return balanceNode(root);
}

// Find rank of key
int getRank(Node *root, int key)
{
    if (!root)
        return -1;
    if (key == root->key)
    {
        return size(root->left) + 1;
    }
    else if (key < root->key)
    {
        return getRank(root->left, key);
    }
    else
    {
        int r = getRank(root->right, key);
        if (r == -1)
            return -1;
        return size(root->left) + 1 + r;
    }
}

// Find kth smallest
int getKth(Node *root, int k)
{
    if (!root || k <= 0 || k > size(root))
        return -1;
    int leftSize = size(root->left);
    if (k == leftSize + 1)
        return root->key;
    if (k <= leftSize)
        return getKth(root->left, k);
    return getKth(root->right, k - leftSize - 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int Q;
    cin >> Q;
    Node *root = nullptr;

    while (Q--)
    {
        char op;
        cin >> op;
        if (op == 'I')
        {
            int x;
            cin >> x;
            root = insert(root, x);
        }
        else if (op == 'D')
        {
            int x;
            cin >> x;
            root = remove(root, x);
        }
        else if (op == 'R')
        {
            int x;
            cin >> x;
            cout << getRank(root, x) << "\n";
        }
        else if (op == 'K')
        {
            int k;
            cin >> k;
            cout << getKth(root, k) << "\n";
        }
    }
}
