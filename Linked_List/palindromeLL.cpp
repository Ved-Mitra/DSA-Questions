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
Node* reverseLL_iterative(Node* head)
{
    //OPTIMAL
    Node* temp=head;
    Node* prev=nullptr,*front=nullptr;
    while(temp!=nullptr)
    {
        front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
    }
    return temp;
}
bool PalindromeLL(Node* head)
{
    if(head==NULL || head->next==NULL)
        return true;
    //BRUTE
    //TC-O(N)
    //SC-O(n)
    Node* temp=head;
    stack<int> palin;
    while(temp!=NULL)
    {
        palin.push(temp->data);
        temp=temp->next;
    }
    temp=head;
    while(temp!=NULL)
    {
        if(temp->data!=palin.top())
            return false;
        temp=temp->next;
        palin.pop();
    }
    return true;


    //OPTIMAL
    //Tortoise and Hare ALGORITHM
    //TC-O(N)
    //SC-O(1)
    Node *fast=head;
    Node* slow=head;
    while(fast->next!=NULL && fast->next->next!=NULL)//O-(N/2)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    Node* newHead=reverseLL_iterative(slow->next);//O-(N/2)
    Node* first=head;
    Node* second=newHead;
    while(second!=NULL)//O-(N/2)
    {
        if(first->data != second->data)
        {
            reverseLL_iterative(newHead);
            return false;
        }
        first=first->next;
        second=second->next;
    }
    reverseLL_iterative(newHead);//O-(N/2)
    return true;
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