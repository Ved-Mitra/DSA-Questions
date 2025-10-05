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
Node* deleteMiddleNode(Node* head)
{
    Node* slow=head;
    Node* fast=head;
    Node* prev=slow;
    while(fast->next!=NULL && fast->next->next!=NULL)
    {
        fast=fast->next->next;
        prev=slow;
        slow=slow->next;
    }
    if(fast->next==NULL)
    {
        prev->next=slow->next;
        delete slow;
    }
    else if(fast->next->next==NULL)
    {
        Node* delNode=slow->next;
        slow->next=slow->next->next;
        delete delNode;
    }
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