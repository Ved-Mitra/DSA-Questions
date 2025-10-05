#include<bits/stdc++.h>
using namespace std;

/*Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.*/

class Node
{
    public:
    int key;
    int val;
    Node* next;
    Node* back;

    public:
    Node(int key1,int val1)
    {
        key=key1;
        val=val1;
        next=nullptr;
        back=nullptr;
    }
    Node(int key1,int val1,Node*next1)
    {
        key=key1;
        val=val1;
        next=next1;
        back=nullptr;
    }
    Node(int key1,int val1,Node* next1,Node* back1)
    {
        key=key1;
        val=val1;
        next=next1;
        back=back1;
    }
};

class LRUCache{
private:
    unordered_map<int,Node*>mpp; //store key,Node
    int capacity;
    Node* head;
    Node* tail;
public:
    LRUCache(int capacity_) { //O(1)
        capacity=capacity_;
        mpp.clear();
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->back=head;
    }
    
    int get(int key) {//O(1)
        if(mpp.find(key)==mpp.end())
        {
            return -1;
        }
        Node* temp=mpp[key];
        deleteNode(temp);
        insertNodeAfterHead(temp);
        return temp->val;
    }
    
    void put(int key, int value) {//O(1)
        if(mpp.find(key)!=mpp.end())
        {
            Node* node=mpp[key];
            node->val=value;
            deleteNode(node);
            insertNodeAfterHead(node);
        }
        else
        {
            if(mpp.size()==capacity)
            {
                Node* node=tail->back;
                mpp.erase(node->key);
                deleteNode(node);
            }
            Node* node=new Node(key,value);
            mpp[key]=node;
            insertNodeAfterHead(node);
        }
    }

    void deleteNode(Node* node)
    {
        Node* prevNode=node->back;
        Node* afterNode=node->next;
        prevNode->next=afterNode;
        afterNode->back=prevNode;
    }

    void insertNodeAfterHead(Node* node)
    {
        Node* currAfterHead=head->next;
        head->next=node;
        node->next=currAfterHead;
        node->back=head;
        currAfterHead->back=node;
    }
};


int main()
{

}