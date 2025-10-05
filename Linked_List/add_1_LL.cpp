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
Node* reverseLL(Node *head)
{
    Node* temp=head;
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
Node* add_1_NumberInLL(Node* head)
{
    //BETTER
    //TC-O(N)
    //SC-O(1)
    if(head==NULL)
        return NULL;
    Node* newHead=reverseLL(head);
    Node* temp=newHead;
    Node* prev=temp;
    int carry=1;
    while(temp!=NULL)
    {
        int sum=temp->data + carry;
        temp->data=sum%10;
        carry=sum/10;
        prev=temp;
        temp=temp->next;
    }
    if(carry)
    {
        Node* node=new Node(carry);
        prev->next=node;
    }
    return reverseLL(newHead);


    //OPTIMAL
    //BY RECURSION
}
Node* add_1_NumberInLL_recursive(Node* head)
{
    //without reversing
    int carry=add(head);
    if(carry==1)
    {
        Node* newNode=new Node(1);
        newNode->next=head;
        return newNode;
    }
    return head;
}
int add(Node* temp)
{
    if(temp==NULL)
        return 1;
    int carry=add(temp->next);
    temp->data=temp->data + carry;
    if(temp->data<10)
    {
        return 0;
    }
    temp->data=0;
    return 1;
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