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
Node* middleNode(Node* head) 
{
    //BRUTE
    Node* temp=head;
    int count=0;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }   
    count=count/2 + 1;
    int cnt=0;
    temp=head;
    while(temp!=NULL)
    {
        cnt++;
        if(cnt==count)
            break;
        temp=temp->next;
    }
    return temp;



    //OPTIMAL (TORTOISE AND HARE)
    Node* slow=head,*fast=head;
    while(fast!=nullptr)
    {
        slow=slow->next;
        fast=fast->next;
        if(fast->next)
            fast=fast->next;
    }
    return slow;
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