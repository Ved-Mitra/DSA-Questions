#include<bits/stdc++.h>
using namespace std;

/*Design and implement a data structure for a Least Frequently Used (LFU) cache.

Implement the LFUCache class:

LFUCache(int capacity) Initializes the object with the capacity of the data structure.
int get(int key) Gets the value of the key if the key exists in the cache. Otherwise, returns -1.
void put(int key, int value) Update the value of the key if present, or inserts the key if not already present. When the cache reaches its capacity, it should invalidate and remove the least frequently used key before inserting a new item. For this problem, when there is a tie (i.e., two or more keys with the same frequency), the least recently used key would be invalidated.
To determine the least frequently used key, a use counter is maintained for each key in the cache. The key with the smallest use counter is the least frequently used key.

When a key is first inserted into the cache, its use counter is set to 1 (due to the put operation). The use counter for a key in the cache is incremented either a get or put operation is called on it.

The functions get and put must each run in O(1) average time complexity.*/


//ME
class Node
{
    public:
    int key;
    int val;
    int cnt;
    Node* next;
    Node* back;

    public:
    Node(int key1,int val1)
    {
        key=key1;
        val=val1;
        cnt=1;
        next=nullptr;
        back=nullptr;
    }
    Node(int key1,int val1,Node*next1)
    {
        key=key1;
        val=val1;
        cnt=1;
        next=next1;
        back=nullptr;
    }
    Node(int key1,int val1,Node* next1,Node* back1)
    {
        key=key1;
        val=val1;
        cnt=1;
        next=next1;
        back=back1;
    }
    void deleteNode(Node* node)
    {
        Node* afterNode=node->next;
        Node* prevNode=node->back;
        afterNode->back=prevNode;
        prevNode->next=afterNode;
    }
    void insertafterHead(Node* node,Node* head)
    {
        Node* currAfterHead=head->next;
        node->next=currAfterHead;
        node->back=head;
        head->next=node;
        currAfterHead->back=node;
    }
};
class LFUCache {
private:
    unordered_map<int,Node*>mpp; //key,node

    int capacity;
    Node* head;
    Node* tail;

public:
    LFUCache(int capacity_) {
        capacity=capacity_;
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->back=head;
    }
    
    int get(int key) {
        if(mpp.find(key)==mpp.end())
            return -1;
        Node* node=mpp[key];
        node->cnt+=1;
        
    }
    
    void put(int key, int value) {
        if(capacity==0)
            return;
    }
};






//STRIVER
struct Node
{
    int key,val,cnt;
    Node* next;
    Node* prev;
    Node(int key_,int val_)
    {
        key=key_;
        val=val_;
        cnt=1;
    }
};
struct List
{
    int size;
    Node* head;
    Node* tail;
    List()
    {
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
        size=0;
    }
    void addFront(Node* node)
    {
        Node* temp=head->next;
        node->next=temp;
        node->prev=head;
        head->next=node;
        temp->prev=node;
        size++;
    }
    void removeNode(Node* delNode)
    {
        Node* delPrev=delNode->prev;
        Node* delNext=delNode->next;
        delPrev->next=delNext;
        delNext->prev=delPrev;
        size--;
    }
};
class LFUCache
{
    private:
        map<int,Node*> keyNode;
        map<int,List*> freqListMap;
        int capacity;
        int minFreq;
        int currSize;
    public:
        LFUCache(int capacity_)
        {
            capacity=capacity_;
            minFreq=0;
            currSize=0;
        }
        void updateFreqListMap(Node* node)
        {
            keyNode.erase(node->key);
            freqListMap[node->cnt]->removeNode(node);
            if(node->cnt == minFreq && freqListMap[node->cnt]->size==0)
            {
                minFreq++;
            }
            List* nextHigherFreqList=new List();
            if(freqListMap.find(node->cnt + 1)!=freqListMap.end())
            {
                nextHigherFreqList=freqListMap[node->cnt + 1];
            }
            node->cnt+=1;
            nextHigherFreqList->addFront(node);
            freqListMap[node->cnt]=nextHigherFreqList;
            keyNode[node->key]=node;
        }
        int get(int key)
        {
            if(keyNode.find(key)!=keyNode.end())
            {
                Node* node=keyNode[key];
                int value=node->val;
                updateFreqListMap(node);
                return value;
            }
            return -1;
        }
        void put(int key,int value)
        {
            if(capacity==0)
                return;
            if(keyNode.find(key)!=keyNode.end())
            {
                Node* node=keyNode[key];
                node->val=value;
                updateFreqListMap(node);
            }
            else
            {
                if(currSize==capacity)
                {
                    List* list=freqListMap[minFreq];
                    keyNode.erase(list->tail->prev->key);
                    freqListMap[minFreq]->removeNode(list->tail->prev);
                    currSize--;
                }
                currSize++;
                //adding new value
                minFreq=1;
                List* listFreq=new List();
                if(freqListMap.find(minFreq)!=freqListMap.end())
                {
                    listFreq=freqListMap[minFreq];
                }
                Node* node= new Node(key,value);
                listFreq->addFront(node);
                keyNode[key]=node;
                freqListMap[minFreq]=listFreq;
            }
        }
};





int main()
{

}