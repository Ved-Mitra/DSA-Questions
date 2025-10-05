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
Node* remove_Nth_Node(Node* head,int pos)
{
    //BRUTE
    Node* temp=head;
    int nodes=0;
    while(temp!=NULL)
    {
        nodes++;
        temp=temp->next;
    }
    if(pos<0 || pos>nodes)
        return head;
    if(pos==nodes)
    {
        Node* ptr=head;
        head=head->next;
        delete ptr;
        return head;
    }
    temp=head;
    int i=0;
    while(i<(nodes-pos-1) && temp!=NULL)
    {
        i++;
        temp=temp->next;
    }
    Node* ptr=temp->next;
    temp->next=temp->next->next;
    delete ptr;
    return head;


    //OPTIMAL
    Node* fast=head;
    for(int i=0;i<pos;i++)
        fast=fast->next;
    Node* slow=head;
    if(fast==NULL)
    {
        Node* newHead=head->next;
        delete head;
        return newHead;
    }
    while(fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next;
    }
    Node* delNode=slow->next;
    slow->next=slow->next->next;
    delete delNode;
    return head;
}

int main()
{
    int n;
    cout << "Enter the size of array: " ;
    cin >> n;
    vector<int> arr(n);
    cout  << "Enter the elements of the array : " << endl;
    for(int i=0;i<n;i++)
        cin >> arr[i];
    Node* head=convertArrayToLL(arr);
    
}