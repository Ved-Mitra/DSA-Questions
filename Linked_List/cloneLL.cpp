#include<bits/stdc++.h>
using namespace std;


class Node //I get benefits like data abstraction, polmorphism, etc
{
    public:
    int data;
    Node *next;
    Node *random;

    public:
    Node(int data1,Node *next1)
    {
        data=data1;
        next=next1;
        random=nullptr;
    }

    public:
    Node(int data1)
    {
        data=data1;
        next=nullptr;
        random=nullptr;
    }

    public:
    Node(int data1,Node *next1,Node* random1)
    {
        data=data1;
        next=next1;
        random=random1;
    }    
};
Node* convertArrayToLL(vector<int> &arr)
{
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++)
    {
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}
Node* clone_LL_WithNextRandomPointer(Node* head)
{
    //BRUTE
    //TC-O(N)
    //SC-O(N)
    Node* temp=head;
    map<Node*,Node*>mpp;
    while(temp!=NULL)
    {
        Node* newNode=new Node(temp->data);
        mpp[temp]=newNode;
        temp=temp->next;
    }
    temp=head;
    while(temp!=NULL)
    {
        Node* copyNode=mpp[temp];
        copyNode->next=mpp[temp->next];
        copyNode->random=mpp[temp->random];
        temp=temp->next;
    }
    return mpp[head];


    //OPTIMAL
    //1. insert copyNode in between 
    //2. Connect the random pointers
    //3. connect the next pointers
    temp=head;
    //step 1
    while(temp!=NULL)
    {
        Node* newNode=new Node(temp->data);
        newNode->next=temp->next;
        temp->next=newNode;
        temp=temp->next->next;
    }
    //step 2
    temp=head;
    while(temp!=NULL)
    {
        Node* clone=temp->next;
        if(temp->random)
            clone->random=temp->random->next;
        temp=temp->next->next;
    }
    //step 3
    temp=head;
    Node* dummyNode=new Node(-1);
    Node* clone=dummyNode;
    while(temp!=NULL)
    {
        clone->next=temp->next;
        temp->next=temp->next->next;
        temp=temp->next;
        clone=clone->next;
    }
    return dummyNode->next;
}

int main()
{
    vector<int> arr={2,4,8,98,56,7};

    Node *head=convertArrayToLL(arr);

    return 0;
}