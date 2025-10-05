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
Node* rotate_LL(Node* head,int k)
{
    int n=0;
    Node *ptr=head;
    while(ptr!=NULL)
    {
        n++;
        ptr=ptr->next;
    }
    if(n==0)
        return head;
    k=k%n;
    if(k==0)
        return head;
    int temp1[n-k];
    int temp2[k];
    ptr=head;
    for(int i=0;i<n-k;i++)
    {
        temp1[i]=ptr->data;
        ptr=ptr->next;
    }
    for(int i=n-k;i<n;i++)
    {
        temp2[i-n+k]=ptr->data;
        ptr=ptr->next;
    }
    ptr=head;
    for(int i=0;i<k;i++)
    {
        ptr->data=temp2[i];
        ptr=ptr->next;
    }
    for(int i=k;i<n;i++)
    {
        ptr->data=temp1[i-k];
        ptr=ptr->next;
    }
    return head;


    //OPTIMAL
    Node *tail=head;
    int n=1;
    while(tail->next!=NULL)
    {
        tail=tail->next;
        n++;
    }
    if(k%n==0)
        return head;
    k%=n;
    k=n-k;
    tail->next=head;
    int count=0;
    
    Node* temp=tail;
    while(count<k)
    {
        count++;
        temp=temp->next;
    }
    Node* newHead=temp->next;
    temp->next=NULL;
    return newHead;
}

int main()
{
    vector<int> arr={2,4,8,98,56,7};

    Node *head=convertArrayToLL(arr);

    return 0;
}