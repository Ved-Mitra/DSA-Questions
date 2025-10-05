#include <bits/stdc++.h>
using namespace std;

class Btree
{
    class BtreeNode
    {
    public:
        vector<int> keys;
        vector<BtreeNode*> children;
        bool isLeaf;
        int keysPresent; // to store the number of keys present in vector<int> keys
        int degree;      // minimum degree for 2/4 t=2, referes to minimum children at any node except root if it is leaf

        BtreeNode(int n, bool Leaf)
        {
            degree = n;
            keysPresent = 0;
            isLeaf = Leaf; // cannot be determined by children.size() as children is resized
            keys.resize(2 * degree - 1);
            children.resize(2 * degree, nullptr);
        }
    };

public:
    BtreeNode *root;
    int t;

public:
    Btree(int degree)
    {
        t = degree;
        root = nullptr;
    }

    int insert(int key)
    {
        if (root == nullptr)
        {
            // Tree is empty, create root
            root = new BtreeNode(t, true);
            root->keys[0] = key;
            root->keysPresent = 1;
            return 1;
        }

        // If root is full, need to split
        if (root->keysPresent == 2 * t - 1)
        {
            // Create new root
            BtreeNode *s = new BtreeNode(t, false);
            s->children[0] = root;
            // Split old root and move one key to new root
            splitChild(s, 0, root);
            // Decide which child to insert into
            int i = 0;
            if (s->keys[0] < key)
                i++;
            insertNonFull(s->children[i], key);
            root = s;
            return 1;
        }
        else
        {
            insertNonFull(root, key);
            return 1;
        }
    }

    int remove(int key)
    {
        if (!root)
            return 0;
        remove(root, key);
        // If root has 0 keys, make its first child the new root (if not leaf)
        if (root->keysPresent == 0)
        {
            BtreeNode *oldRoot = root;
            if (root->isLeaf)
            {
                delete root;
                root = nullptr;
            }
            else
            {
                root = root->children[0];
                delete oldRoot;
            }
        }
        return 1;
    }

    bool search(int key)
    {
        if (root == NULL)
            return false;
        BtreeNode *temp = root;

        while (temp)
        {
            int n = temp->keysPresent;
            int l = 0, r = n - 1;
            while (l <= r)
            {
                int mid = (l + r) / 2;
                if (key < temp->keys[mid])
                    r = mid - 1;
                else if (key > temp->keys[mid])
                    l = mid + 1;
                else
                    return true; // key found
            }
            temp = temp->children[l];
        }
        return false;
    }

    void inorder()
    {
    }

private:
    // Helper function to insert key into non-full node
    void insertNonFull(BtreeNode *node, int key)
    {
        int i = node->keysPresent - 1;
        if (node->isLeaf)
        {
            // Insert key into the correct position in the leaf node
            while (i >= 0 && node->keys[i] > key)
            {
                node->keys[i + 1] = node->keys[i];
                i--;
            }
            node->keys[i + 1] = key;
            node->keysPresent++;
        }
        else
        {
            // Find the child which is going to have the new key
            while (i >= 0 && node->keys[i] > key)
                i--;
            i++;
            // If the found child is full, split it
            if (node->children[i]->keysPresent == 2 * t - 1)
            {
                splitChild(node, i, node->children[i]);
                if (node->keys[i] < key)
                    i++;
            }
            insertNonFull(node->children[i], key);
        }
    }

    // Helper function to split the child y of node at index i
    void splitChild(BtreeNode *parent, int i, BtreeNode *y)
    {
        BtreeNode *z = new BtreeNode(t, y->isLeaf);
        z->keysPresent = t - 1;
        // Copy the last (t-1) keys of y to z
        for (int j = 0; j < t - 1; j++)
            z->keys[j] = y->keys[j + t];
        // Copy the last t children of y to z
        if (!y->isLeaf)
        {
            for (int j = 0; j < t; j++)
                z->children[j] = y->children[j + t];
        }
        y->keysPresent = t - 1;

        // Insert new child into parent
        for (int j = parent->keysPresent; j >= i + 1; j--)
            parent->children[j + 1] = parent->children[j];
        parent->children[i + 1] = z;

        // Move middle key of y up to parent
        for (int j = parent->keysPresent - 1; j >= i; j--)
            parent->keys[j + 1] = parent->keys[j];
        parent->keys[i] = y->keys[t - 1];
        parent->keysPresent++;
    }

    void remove(BtreeNode *node, int key)
    {
        int idx = 0;
        while (idx < node->keysPresent && node->keys[idx] < key)
            idx++;

        // Case 1: Key is in this node
        if (idx < node->keysPresent && node->keys[idx] == key)
        {
            if (node->isLeaf)
            {
                // Remove from leaf
                for (int i = idx + 1; i < node->keysPresent; ++i)
                    node->keys[i - 1] = node->keys[i];
                node->keysPresent--;
            }
            else
            {
                // Remove from internal node
                removeFromNonLeaf(node, idx);
            }
        }
        else
        {
            // Key not in this node
            if (node->isLeaf)
                return; // Key not found

            // Check if the child where key may exist has less than t keys
            bool flag = (idx == node->keysPresent);
            if (node->children[idx]->keysPresent < t)
                fill(node, idx);

            // If last child was merged, recurse on (idx-1)th child
            if (flag && idx > node->keysPresent)
                remove(node->children[idx - 1], key);
            else
                remove(node->children[idx], key);
        }
    }

    void removeFromNonLeaf(BtreeNode *node, int idx)
    {
        int k = node->keys[idx];
        // Case 2a: Predecessor child has at least t keys
        if (node->children[idx]->keysPresent >= t)
        {
            int pred = getPred(node, idx);
            node->keys[idx] = pred;
            remove(node->children[idx], pred);
        }
        // Case 2b: Successor child has at least t keys
        else if (node->children[idx + 1]->keysPresent >= t)
        {
            int succ = getSucc(node, idx);
            node->keys[idx] = succ;
            remove(node->children[idx + 1], succ);
        }
        // Case 2c: Both children have t-1 keys, merge them
        else
        {
            merge(node, idx);
            remove(node->children[idx], k);
        }
    }

    int getPred(BtreeNode *node, int idx)
    {
        BtreeNode *cur = node->children[idx];
        while (!cur->isLeaf)
            cur = cur->children[cur->keysPresent];
        return cur->keys[cur->keysPresent - 1];
    }

    int getSucc(BtreeNode *node, int idx)
    {
        BtreeNode *cur = node->children[idx + 1];
        while (!cur->isLeaf)
            cur = cur->children[0];
        return cur->keys[0];
    }

    // Ensures that the child node at index 'idx' has at least 't' keys.
    // If not, it borrows a key from a sibling or merges with a sibling.
    void fill(BtreeNode *node, int idx)
    {
        // If the previous sibling has at least t keys, borrow from it
        if (idx != 0 && node->children[idx - 1]->keysPresent >= t)
            borrowFromPrev(node, idx);
        // Else if the next sibling has at least t keys, borrow from it
        else if (idx != node->keysPresent && node->children[idx + 1]->keysPresent >= t)
            borrowFromNext(node, idx);
        // Else, merge with a sibling
        else
        {
            if (idx != node->keysPresent)
                merge(node, idx);
            else
                merge(node, idx - 1);
        }
    }

    // Borrows a key from the previous sibling and moves it to the child at index 'idx'.
    // Adjusts keys and children pointers accordingly.
    void borrowFromPrev(BtreeNode *node, int idx)
    {
        BtreeNode *child = node->children[idx];
        BtreeNode *sibling = node->children[idx - 1];

        // Shift all keys and children in child right by one to make space
        for (int i = child->keysPresent - 1; i >= 0; --i)
            child->keys[i + 1] = child->keys[i];
        if (!child->isLeaf)
        {
            for (int i = child->keysPresent; i >= 0; --i)
                child->children[i + 1] = child->children[i];
        }
        // Move key from parent to child
        child->keys[0] = node->keys[idx - 1];
        // Move last child of sibling to child if not leaf
        if (!child->isLeaf)
            child->children[0] = sibling->children[sibling->keysPresent];
        // Move key from sibling to parent
        node->keys[idx - 1] = sibling->keys[sibling->keysPresent - 1];
        child->keysPresent += 1;
        sibling->keysPresent -= 1;
    }

    // Borrows a key from the next sibling and moves it to the child at index 'idx'.
    // Adjusts keys and children pointers accordingly.
    void borrowFromNext(BtreeNode *node, int idx)
    {
        BtreeNode *child = node->children[idx];
        BtreeNode *sibling = node->children[idx + 1];

        // Move key from parent to child
        child->keys[child->keysPresent] = node->keys[idx];
        // Move first child of sibling to child if not leaf
        if (!child->isLeaf)
            child->children[child->keysPresent + 1] = sibling->children[0];
        // Move key from sibling to parent
        node->keys[idx] = sibling->keys[0];
        // Shift all keys and children in sibling left by one
        for (int i = 1; i < sibling->keysPresent; ++i)
            sibling->keys[i - 1] = sibling->keys[i];
        if (!sibling->isLeaf)
        {
            for (int i = 1; i <= sibling->keysPresent; ++i)
                sibling->children[i - 1] = sibling->children[i];
        }
        child->keysPresent += 1;
        sibling->keysPresent -= 1;
    }

    // Merges child at index 'idx' with its next sibling.
    // Moves a key from parent down and combines keys and children.
    void merge(BtreeNode *node, int idx)
    {
        BtreeNode *child = node->children[idx];
        BtreeNode *sibling = node->children[idx + 1];

        // Move key from parent to child
        child->keys[t - 1] = node->keys[idx];
        // Copy keys from sibling to child
        for (int i = 0; i < sibling->keysPresent; ++i)
            child->keys[i + t] = sibling->keys[i];
        // Copy children from sibling to child if not leaf
        if (!child->isLeaf)
        {
            for (int i = 0; i <= sibling->keysPresent; ++i)
                child->children[i + t] = sibling->children[i];
        }
        // Shift keys and children in parent left to fill gap
        for (int i = idx + 1; i < node->keysPresent; ++i)
            node->keys[i - 1] = node->keys[i];
        for (int i = idx + 2; i <= node->keysPresent; ++i)
            node->children[i - 1] = node->children[i];
        child->keysPresent += sibling->keysPresent + 1;
        node->keysPresent--;
        delete sibling;
    }
};

int main()
{
    int n, t;
    cin >> n >> t;

    Btree T1(t);

    for (int i = 0; i < n; i++) // insert operations
    {
        int x;
        cin >> x;
        T1.insert(x);
    }

    int d;
    cin >> d;
    for (int i = 0; i < d; i++) // delete operations
    {
        int x;
        cin >> x;
        T1.remove(x);
    }

    int target;
    cin >> target;
    cout << T1.search(target) << endl;
}