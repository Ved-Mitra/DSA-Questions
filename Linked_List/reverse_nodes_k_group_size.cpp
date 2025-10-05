#include<bits/stdc++.h>
using namespace std;


class Node //I get benefits like data abstraction, polmorphism, etc
{
    public:
    int data;
    Node *next;

    public:
    Node(int data1,Node *next1)
    {
        data=data1;
        next=next1;
    }

    public:
    Node(int data1)
    {
        data=data1;
        next=nullptr;
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
Node* reverseNodeIn_k_GroupSizesLL(Node* head,int k)
{
    Node* temp=head;
    int i=0;
    Node* dummyNode=new Node(-1);
    Node* temp2=dummyNode;
    while(temp!=NULL)
    {
        Node* prevNode=temp;
        Node* kth_Node=kthNode(temp,k);
        if(kth_Node==NULL)
        {
            temp2->next=prevNode;
            break;
        }
        Node* nextNode=kth_Node->next;
        kth_Node->next=NULL;
        Node* newHead=reverseLL(temp);
        temp2->next=newHead;
        temp2=prevNode;
        temp=nextNode;
    }
    return dummyNode->next;
}
Node* reverseLL(Node* head)
{
    Node*temp=head;
    Node* prev=nullptr,*front=nullptr;
    while(temp!=nullptr)
    {
        front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
    }
    return prev;
}
Node* kthNode(Node* temp,int k)
{
    for(int i=0;i<k-1 && temp!=NULL;i++)
        temp=temp->next;
    return temp;
}

int main()
{
    vector<int> arr={2,4,8,98,56,7};

    Node *head=convertArrayToLL(arr);

    return 0;
}