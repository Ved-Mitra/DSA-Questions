#include <bits/stdc++.h>
using namespace std;


// Enum for node colors
enum Color { RED, BLACK };

// Structure for a single node in the Red-Black Tree
struct Node {
    int data;          // The key/data of the node
    Color color;       // Color of the node (RED or BLACK)
    Node *parent;      // Pointer to the parent node
    Node *left;        // Pointer to the left child
    Node *right;       // Pointer to the right child

    // Constructor to initialize a node
    Node(int data) {
        this->data = data;
        parent = nullptr;
        left = nullptr;
        right = nullptr;
        this->color = RED; // New nodes are always inserted as RED
    }
};

// Red-Black Tree class
class RedBlackTree {
private:
    Node *root;    // Pointer to the root of the tree
    Node *TNULL;   // A sentinel NULL node

    // Helper function to print the tree (in-order traversal)
    void printHelper(Node* root, std::string indent, bool last) {
        if (root != TNULL) {
            std::cout << indent;
            if (last) {
                std::cout << "R----";
                indent += "   ";
            } else {
                std::cout << "L----";
                indent += "|  ";
            }

            std::string sColor = (root->color == RED) ? "RED" : "BLACK";
            std::cout << root->data << "(" << sColor << ")" << std::endl;
            printHelper(root->left, indent, false);
            printHelper(root->right, indent, true);
        }
    }

    // Helper function to search for a key in the tree
    Node* searchTreeHelper(Node* node, int key) {
        if (node == TNULL || key == node->data) {
            return node;
        }
        if (key < node->data) {
            return searchTreeHelper(node->left, key);
        }
        return searchTreeHelper(node->right, key);
    }
    
    // Fix the Red-Black Tree properties after deleting a node
    void deleteFixup(Node* x) {
        Node* s;
        while (x != root && x->color == BLACK) {
            if (x == x->parent->left) {
                s = x->parent->right;
                if (s->color == RED) {
                    s->color = BLACK;
                    x->parent->color = RED;
                    leftRotate(x->parent);
                    s = x->parent->right;
                }

                if (s->left->color == BLACK && s->right->color == BLACK) {
                    s->color = RED;
                    x = x->parent;
                } else {
                    if (s->right->color == BLACK) {
                        s->left->color = BLACK;
                        s->color = RED;
                        rightRotate(s);
                        s = x->parent->right;
                    }

                    s->color = x->parent->color;
                    x->parent->color = BLACK;
                    s->right->color = BLACK;
                    leftRotate(x->parent);
                    x = root;
                }
            } else {
                s = x->parent->left;
                if (s->color == RED) {
                    s->color = BLACK;
                    x->parent->color = RED;
                    rightRotate(x->parent);
                    s = x->parent->left;
                }

                if (s->right->color == BLACK && s->left->color == BLACK) {
                    s->color = RED;
                    x = x->parent;
                } else {
                    if (s->left->color == BLACK) {
                        s->right->color = BLACK;
                        s->color = RED;
                        leftRotate(s);
                        s = x->parent->left;
                    }

                    s->color = x->parent->color;
                    x->parent->color = BLACK;
                    s->left->color = BLACK;
                    rightRotate(x->parent);
                    x = root;
                }
            }
        }
        x->color = BLACK;
    }

    // Helper function to transplant subtrees
    void rbTransplant(Node* u, Node* v) {
        if (u->parent == nullptr) {
            root = v;
        } else if (u == u->parent->left) {
            u->parent->left = v;
        } else {
            u->parent->right = v;
        }
        v->parent = u->parent;
    }

    // Helper function to delete a node
    void deleteNodeHelper(Node* node, int key) {
        Node* z = TNULL;
        Node* x, *y;
        
        z = searchTreeHelper(this->root, key);

        if (z == TNULL) {
            std::cout << "Key " << key << " not found in the tree" << std::endl;
            return;
        }

        y = z;
        Color y_original_color = y->color;
        if (z->left == TNULL) {
            x = z->right;
            rbTransplant(z, z->right);
        } else if (z->right == TNULL) {
            x = z->left;
            rbTransplant(z, z->left);
        } else {
            y = minimum(z->right);
            y_original_color = y->color;
            x = y->right;
            if (y->parent == z) {
                x->parent = y;
            } else {
                rbTransplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }
            rbTransplant(z, y);
            y->left = z->left;
            y->left->parent = y;
            y->color = z->color;
        }
        delete z;
        if (y_original_color == BLACK) {
            deleteFixup(x);
        }
    }

    // Fix the Red-Black Tree properties after inserting a node
    void insertFixup(Node* k) {
        Node* u;
        while (k->parent->color == RED) {
            if (k->parent == k->parent->parent->right) {
                u = k->parent->parent->left; // uncle
                if (u->color == RED) {
                    u->color = BLACK;
                    k->parent->color = BLACK;
                    k->parent->parent->color = RED;
                    k = k->parent->parent;
                } else {
                    if (k == k->parent->left) {
                        k = k->parent;
                        rightRotate(k);
                    }
                    k->parent->color = BLACK;
                    k->parent->parent->color = RED;
                    leftRotate(k->parent->parent);
                }
            } else {
                u = k->parent->parent->right; // uncle
                if (u->color == RED) {
                    u->color = BLACK;
                    k->parent->color = BLACK;
                    k->parent->parent->color = RED;
                    k = k->parent->parent;
                } else {
                    if (k == k->parent->right) {
                        k = k->parent;
                        leftRotate(k);
                    }
                    k->parent->color = BLACK;
                    k->parent->parent->color = RED;
                    rightRotate(k->parent->parent);
                }
            }
            if (k == root) {
                break;
            }
        }
        root->color = BLACK;
    }

public:
    // Constructor
    RedBlackTree() {
        TNULL = new Node(0);
        TNULL->color = BLACK;
        TNULL->left = nullptr;
        TNULL->right = nullptr;
        root = TNULL;
    }

    // Search for a key in the tree
    Node* searchTree(int key) {
        return searchTreeHelper(this->root, key);
    }
    
    // Find the node with the minimum key
    Node* minimum(Node* node) {
        while (node->left != TNULL) {
            node = node->left;
        }
        return node;
    }
    
    // Perform a left rotation
    void leftRotate(Node* x) {
        Node* y = x->right;
        x->right = y->left;
        if (y->left != TNULL) {
            y->left->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nullptr) {
            this->root = y;
        } else if (x == x->parent->left) {
            x->parent->left = y;
        } else {
            x->parent->right = y;
        }
        y->left = x;
        x->parent = y;
    }

    // Perform a right rotation
    void rightRotate(Node* x) {
        Node* y = x->left;
        x->left = y->right;
        if (y->right != TNULL) {
            y->right->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nullptr) {
            this->root = y;
        } else if (x == x->parent->right) {
            x->parent->right = y;
        } else {
            x->parent->left = y;
        }
        y->right = x;
        x->parent = y;
    }

    // Insert a new key into the tree
    void insert(int key) {
        Node* node = new Node(key);
        node->left = TNULL;
        node->right = TNULL;

        Node* y = nullptr;
        Node* x = this->root;

        while (x != TNULL) {
            y = x;
            if (node->data < x->data) {
                x = x->left;
            } else {
                x = x->right;
            }
        }

        node->parent = y;
        if (y == nullptr) {
            root = node;
        } else if (node->data < y->data) {
            y->left = node;
        } else {
            y->right = node;
        }
        
        if (node->parent == nullptr) {
            node->color = BLACK;
            return;
        }

        if (node->parent->parent == nullptr) {
            return;
        }

        insertFixup(node);
    }
    
    // Delete a node with a given key
    void deleteNode(int data) {
        deleteNodeHelper(this->root, data);
    }

    // Print the tree structure
    void printTree() {
        if (root) {
            printHelper(this->root, "", true);
        }
    }
};

int main() {
    RedBlackTree bst;

    std::cout << "--- Inserting Elements ---" << std::endl;
    int elements_to_insert[] = {55, 40, 65, 60, 75, 57};
    for (int el : elements_to_insert) {
        std::cout << "Inserting " << el << "..." << std::endl;
        bst.insert(el);
        bst.printTree();
        std::cout << "-------------------------" << std::endl;
    }

    std::cout << "\n--- Searching for Elements ---" << std::endl;
    int key_to_search = 60;
    Node* found_node = bst.searchTree(key_to_search);
    if (found_node != nullptr && found_node->data != 0) { // Check against TNULL
        std::cout << "Found node with key " << key_to_search << ", color: " << (found_node->color == RED ? "RED" : "BLACK") << std::endl;
    } else {
        std::cout << "Node with key " << key_to_search << " not found." << std::endl;
    }

    key_to_search = 25;
    found_node = bst.searchTree(key_to_search);
    if (found_node != nullptr && found_node->data != 0) {
        std::cout << "Found node with key " << key_to_search << ", color: " << (found_node->color == RED ? "RED" : "BLACK") << std::endl;
    } else {
        std::cout << "Node with key " << key_to_search << " not found." << std::endl;
    }

    std::cout << "\n--- Deleting Elements ---" << std::endl;
    int elements_to_delete[] = {40, 65, 55, 57, 75, 60};
    for (int el : elements_to_delete) {
        std::cout << "Deleting " << el << "..." << std::endl;
        bst.deleteNode(el);
        bst.printTree();
        std::cout << "-------------------------" << std::endl;
    }
    
    return 0;
}
