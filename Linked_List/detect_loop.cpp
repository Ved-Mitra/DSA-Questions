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
Node* detectLoopLL(Node* head)
{
    Node* temp=head;
    unordered_map<Node*,int> hash;
    while(temp!=nullptr)
    {
        hash[temp]++;
        if(hash[temp]>1)
        {
            cout << "loop detected" << endl;
            return temp;    
        }
        temp=temp->next;
    }
    cout << "loop undetected" << endl;
    return head;

    //Tortoise and Hare Algorithm
    //BETTER
    Node* slow=head, *fast=head;
    while(fast!=nullptr && fast->next!=nullptr)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        {
            cout << "loop detected" << endl;
            return temp;
        }
    }
    cout << "loop undetected" << endl;
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